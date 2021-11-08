#include <fmt/format.h>

#include <drogon/utils/Utilities.h>

#include <include/service/login/exception/invalid_session_exception.hpp>
#include "include/database/sessions_db.hpp"

ChallengeSession SessionsDB::createSession(int clientNonce)
{
    auto sessionId = drogon::utils::getUuid();
    auto serverNonce = std::rand(); // NOLINT(cert-msc50-cpp)
    auto challenge = clientNonce + serverNonce;

    auto command = fmt::format(
            "set {} {} EX {}",
            sessionId,
            serverNonce,
            20
    );
    redis->execCommandAsync(
            [&](const drogon::nosql::RedisResult& r) {},
            [&](const std::exception& e) {
                LOG_ERROR << "Redis error while creating session " << sessionId << ": " << e.what();
            },
            command
    );

    return {sessionId, challenge};
}

int SessionsDB::findServerNonceBySessionId(const std::string& sessionId)
{
    auto command = fmt::format("get {}", sessionId);
    auto resultOptional = execRedisCommandSync(command);

    if (!resultOptional.has_value())
        throw SessionNotFoundException(sessionId);

    return std::stoi(resultOptional.value());
}

void SessionsDB::deleteSessionBySessionId(const std::string& sessionId)
{
    auto command = fmt::format("del {}", sessionId);
    redis->execCommandAsync(
            [&](const drogon::nosql::RedisResult& r) {},
            [&](const std::exception& e) {
                LOG_ERROR << "Redis error while deleting session " << sessionId << ": " << e.what();
            },
            command
    );
}

std::optional<std::string> SessionsDB::execRedisCommandSync(const std::string& command)
{
    std::mutex mutex;
    std::unique_lock<std::mutex> lock(mutex);
    std::condition_variable commandFinished;

    std::optional<std::string> result;

    redis->execCommandAsync(
            [&](const drogon::nosql::RedisResult& r) {
                if (!r.isNil())
                    result = r.asString();

                commandFinished.notify_all();
            },
            [](const std::exception& e) {
                throw e;
            },
            command
    );

    commandFinished.wait(lock);

    return result;
}

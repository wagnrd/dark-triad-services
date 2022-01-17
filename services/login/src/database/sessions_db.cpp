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

drogon::Task<int> SessionsDB::findServerNonceBySessionId(const std::string& sessionId)
{
    auto command = fmt::format("get {}", sessionId);
    auto redisResult = co_await redis->execCommandCoro(command);

    if (redisResult.isNil())
        throw SessionNotFoundException(sessionId);

    co_return std::stoi(redisResult.asString());
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

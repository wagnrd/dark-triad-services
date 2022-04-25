#include "drogon_extended/json_mapper/json_converter.hpp"

#include "include/factory/challenge_response_session_factory.hpp"

ChallengeResponseSession ChallengeResponseSessionFactory::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    auto sessionId = JsonConverter::check(jsonPtr, "session_id").asString();
    auto challengeResponse = JsonConverter::check(jsonPtr, "challenge_response").asInt64();

    return {sessionId, challengeResponse};
}
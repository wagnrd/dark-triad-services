#include <drogon_extended/json_mapper/json_converter.hpp>

#include "include/controller/factory/challenge_session_factory.hpp"

std::shared_ptr<Json::Value> ChallengeSessionFactory::to_json(const ChallengeSession& challengeSession)
{
    auto responseJson = std::make_shared<Json::Value>();

    (*responseJson)["session_id"] = challengeSession.id;
    (*responseJson)["challenge"] = challengeSession.challenge;

    return responseJson;
}

#include <drogon_extended/json_mapper/json_converter.hpp>

#include "include/client/factory/oidc_id_token_factory.hpp"

OidcIdToken OidcIdTokenFactory::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    auto idToken = JsonConverter::check(jsonPtr, "id_token").asString();
    auto tokenType = JsonConverter::check(jsonPtr, "token_type").asString();

    return OidcIdToken(idToken, tokenType);
}

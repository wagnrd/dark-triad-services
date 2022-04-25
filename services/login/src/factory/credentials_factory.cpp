#include "drogon_extended/json_mapper/json_converter.hpp"

#include "include/factory/credentials_factory.hpp"

Credentials CredentialsFactory::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    auto email = JsonConverter::check(jsonPtr, "email").asString();
    auto password = JsonConverter::check(jsonPtr, "password").asString();

    return Credentials(email, password);
}
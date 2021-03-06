#ifndef DARK_TRIAD_SERVICES_CHARACTERS_HPP
#define DARK_TRIAD_SERVICES_CHARACTERS_HPP

#include <drogon/HttpController.h>
#include <drogon_extended/security/api_key_guard.hpp>

#include <include/configuration/base_config.hpp>
#include <include/controller/exception_mapper/characters_exception_mapper.hpp>

namespace private_api
{
    class characters: public drogon::HttpController<characters> {

        std::shared_ptr<BaseConfig> config = Configuration<BaseConfig>::get();
        CharactersService* charactersService = CharactersService::get();
        ApiKeyGuard apiKeyGuard = ApiKeyGuard(config->webServer->apiKey);
        CharactersExceptionMapper exceptionMapper;

    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(characters::get_character, "/{1}", drogon::Get);
            METHOD_ADD(characters::update_exp, "/{1}/exp/{2}}", drogon::Put);
        METHOD_LIST_END

        drogon::Task<>
        get_character(drogon::HttpRequestPtr request, std::function<void(const drogon::HttpResponsePtr&)> callback,
                      const std::string& characterName);

        drogon::Task<void> update_exp(drogon::HttpRequestPtr request,
                                      std::function<void(const drogon::HttpResponsePtr&)> callback,
                                      const std::string& characterName,
                                      uint32_t exp);
    };
}

#endif //DARK_TRIAD_SERVICES_CHARACTERS_HPP
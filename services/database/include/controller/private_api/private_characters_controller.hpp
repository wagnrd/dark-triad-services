#ifndef DATABASE_API_CHARACTERS_HPP
#define DATABASE_API_CHARACTERS_HPP

#include <drogon/HttpController.h>
#include <drogon_extended/security/security.hpp>

#include <include/configuration/base_config.hpp>
#include <include/controller/exception_mapper/characters_exception_mapper.hpp>

namespace private_api
{
    class characters: public drogon::HttpController<characters> {

        std::shared_ptr<BaseConfig> config = Configuration<BaseConfig>::get();
        CharactersService* charactersService = CharactersService::get();
        CharactersExceptionMapper exceptionMapper;

    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(characters::get_character, "/{1}/userId/{2}", drogon::Get);
            METHOD_ADD(characters::update_exp, "/{1}/exp/{2}}", drogon::Put);
        METHOD_LIST_END

        void get_character(const drogon::HttpRequestPtr& request,
                           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                           const std::string& characterName,
                           const std::string& userId);

        void update_exp(const drogon::HttpRequestPtr& request,
                        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                        const std::string& characterName,
                        uint32_t exp);
    };
}

#endif //DATABASE_API_CHARACTERS_HPP

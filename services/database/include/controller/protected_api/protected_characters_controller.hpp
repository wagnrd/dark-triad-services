#ifndef DARK_TRIAD_SERVICES_CHARACTERS_HPP
#define DARK_TRIAD_SERVICES_CHARACTERS_HPP

#include <drogon/drogon.h>

#include <include/configuration/base_config.hpp>
#include <include/controller/exception_mapper/characters_exception_mapper.hpp>
#include "drogon_extended/security/jwt_token_guard.hpp"

namespace protected_api
{
    class characters: public drogon::HttpController<characters> {

        std::string publicKey = R"(-----BEGIN CERTIFICATE-----
MIIDCTCCAfGgAwIBAgIJD1kojIKHKqAIMA0GCSqGSIb3DQEBCwUAMCIxIDAeBgNV
BAMTF2RhcmstdHJpYWQuZXUuYXV0aDAuY29tMB4XDTIxMDIxMTA4MzA1MVoXDTM0
MTAyMTA4MzA1MVowIjEgMB4GA1UEAxMXZGFyay10cmlhZC5ldS5hdXRoMC5jb20w
ggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDDFALkPJe+0gqjAiZ4EAer
bR/UPctpxS2f/PMEwMIipcqiKO2VW5vJ7DH4FWXcyJqcRVWDPb+/VMfbkHj4gJRK
wWkqNqW/YYG/YdPNzws5R2A78MYiAGovmIg11eMSadiKo7+MXAN7Nvpc8w9IKtV5
0R4cgXn1xb5IzbW9a0kJhrWXv9CDrg/nhfYLQ4UfNPK6EDRjiJsLxQjNc1s264DS
6IX4M7UT32jgcR5PBQLYKHNLBTFroCEoojRdT02oEiSfr+uMEBaNP0OrngJ17fk/
jk+v/g2XLLmvVY9Qh92VE2SwinJQGn8OLAPpohKo9Hi2IHB91DYWW7+LvEIHB0Xn
AgMBAAGjQjBAMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYEFLPcl67jUMckJxzc
f0G3YluABM+AMA4GA1UdDwEB/wQEAwIChDANBgkqhkiG9w0BAQsFAAOCAQEAEfrB
mwWSYNiHP25x6kykrWDLA/Mfwr85dmnIqTrXs3GZ3LXJIRBu9sX3Bbxd5ezQs1kg
IsF+DqfvwZJXWMDcrCs+STKSPlGMJpbYcPOkKc9wuvY3CaVooSW0qBFld+Iogp3g
diWFFd+dyhWVRcnoTPGehQpej34shUpbWAG7F+TuQUXMCsXGKA08Bcea8dVqPWv9
g7iuK8RlUoWP9DqWKSBMPsR2ECA1ssmFw4HeWqpD+zZssX4CC5au9XdKJTzIHaVX
8LBCZ5lcQ5p5LPcGwC2rjmE0jedjidaTKyAWl/a6xWtqS+vSc5CFIZo8+1cGuC/2
P90F2g0l/3qfb8+j5g==
-----END CERTIFICATE-----)";

        std::shared_ptr<BaseConfig> config = Configuration<BaseConfig>::get();
        CharactersService* charactersService = CharactersService::get();
        JwtTokenGuard jwtTokenGuard = JwtTokenGuard(publicKey);
        CharactersExceptionMapper exceptionMapper;

    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(characters::get_all_characters, "", drogon::Get);
            METHOD_ADD(characters::create_character, "", drogon::Post);
            METHOD_ADD(characters::delete_character, "/{1}", drogon::Delete);
            METHOD_ADD(characters::delete_all_characters, "", drogon::Delete);
            METHOD_ADD(characters::character_name_exists, "/{1}/exists", drogon::Get);
        METHOD_LIST_END

        drogon::Task<> get_all_characters(drogon::HttpRequestPtr request,
                                          std::function<void(const drogon::HttpResponsePtr&)> callback);

        drogon::Task<> create_character(drogon::HttpRequestPtr request,
                                        std::function<void(const drogon::HttpResponsePtr&)> callback);

        drogon::Task<> delete_character(drogon::HttpRequestPtr request,
                                        std::function<void(const drogon::HttpResponsePtr&)> callback,
                                        const std::string& characterName);

        drogon::Task<> delete_all_characters(drogon::HttpRequestPtr request,
                                             std::function<void(const drogon::HttpResponsePtr&)> callback);

        drogon::Task<> character_name_exists(drogon::HttpRequestPtr request,
                                             std::function<void(const drogon::HttpResponsePtr&)> callback,
                                             const std::string& characterName);
    };
}

#endif //DARK_TRIAD_SERVICES_CHARACTERS_HPP
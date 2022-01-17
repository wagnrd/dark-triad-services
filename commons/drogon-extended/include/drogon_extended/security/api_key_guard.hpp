#ifndef DARK_TRIAD_SERVICES_API_KEY_GUARD_HPP
#define DARK_TRIAD_SERVICES_API_KEY_GUARD_HPP

#include "drogon/HttpRequest.h"

class ApiKeyGuard {

    std::string apiKey;

public:
    explicit ApiKeyGuard(std::string apiKey);

    void check(const drogon::HttpRequestPtr& request);
};

#endif //DARK_TRIAD_SERVICES_API_KEY_GUARD_HPP

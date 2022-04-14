#ifndef DARK_TRIAD_SERVICES_JSON_MODEL_HPP
#define DARK_TRIAD_SERVICES_JSON_MODEL_HPP

#include <memory>
#include <json/json.h>

class JsonModel {

    std::shared_ptr<Json::Value> jsonPtr;

public:
    explicit JsonModel(std::shared_ptr<Json::Value> json);
    virtual ~JsonModel() = default;

    virtual Json::Value json();

protected:
    Json::Value& check(const std::string& key);
};

#endif //DARK_TRIAD_SERVICES_JSON_MODEL_HPP

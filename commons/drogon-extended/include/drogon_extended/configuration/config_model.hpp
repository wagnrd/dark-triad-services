#ifndef DARK_TRIAD_SERVICES_CONFIG_MODEL_HPP
#define DARK_TRIAD_SERVICES_CONFIG_MODEL_HPP

#include <utility>

#include <json/value.h>

#include <drogon_extended/configuration/exceptions/invalid_env_var_exception.hpp>
#include <drogon_extended/configuration/exceptions/invalid_config_var_exception.hpp>
#include <drogon_extended/configuration/exceptions/invalid_config_obj_exception.hpp>
#include "configuration.hpp"

template<class BaseConfigT>
class ConfigModel {

    const Json::Value& json;
    Json::Value allConfig;

protected:
    std::string get_env_var(const std::string& key)
    {
        const char* valueStr = std::getenv(key.c_str());

        if (valueStr == nullptr)
            throw InvalidEnvVarException(key);

        std::string value = valueStr;
        allConfig["(" + key + ")"] = value;

        return value;
    }

    std::string get_env_var(const std::string& key, const std::string& defaultValue)
    {
        const char* valueStr = std::getenv(key.c_str());
        std::string value;

        if (valueStr == nullptr)
            value = defaultValue;
        else
            value = valueStr;

        allConfig["(" + key + ")"] = value;
        return value;
    }

    Json::Value get_json_var(const std::string& key)
    {
        auto value = json[key];

        if (value.empty())
            throw InvalidConfigVarException(key);

        allConfig[key] = value;
        return value;
    }

    Json::Value get_json_var(const std::string& key, const std::string& defaultValue)
    {
        auto value = json.get(key, defaultValue);
        allConfig[key] = value;

        return value;
    }

    template<class T>
    std::shared_ptr<T> get_json_obj_var(const std::string& key)
    {
        Json::Value jsonValue = json[key];

        if (jsonValue.empty())
            throw InvalidConfigVarException(key);

        try
        {
            auto value = std::make_shared<T>(jsonValue);
            allConfig[key] = value->allConfig;

            return value;
        }
        catch (std::exception& e)
        {
            throw InvalidConfigObjException(key, e);
        }
    }

    template<class T>
    std::shared_ptr<T> register_custom_object(const std::string& key)
    {
        auto value = std::make_shared<T>(Json::Value());
        allConfig[key] = value->allConfig;

        return value;
    }

    const std::string& register_custom_value(const std::string& key, const std::string& value)
    {
        allConfig[key] = value;
        return value;
    }

public:
    explicit ConfigModel(const Json::Value& json) : json(json)
    {}

    friend Configuration<BaseConfigT>;
};

#endif //DARK_TRIAD_SERVICES_CONFIG_MODEL_HPP

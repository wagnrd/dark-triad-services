#ifndef DATABASE_API_CONFIGURATION_HPP
#define DATABASE_API_CONFIGURATION_HPP

#include <fstream>
#include <memory>

#include <json/json.h>
#include <drogon/Attribute.h>

class BaseConfig;

template<class T>
class Configuration {

    std::shared_ptr<T> baseConfig;

public:
    Configuration()
    {
        std::ifstream configFile;

        try
        {
            configFile.open("../config.json", std::ios::binary);

            if (configFile.fail() || configFile.bad())
                throw std::exception();
        }
        catch (std::exception& e)
        {
            throw std::runtime_error("Could not open configuration file 'config.json'");
        }

        Json::Value json;
        configFile >> json;

        baseConfig = std::make_shared<T>(json);

        LOG_INFO << get_config_log();
    }

    static std::shared_ptr<T> get()
    {
        static Configuration<T> configuration;
        return configuration.baseConfig;
    }

private:
    std::string get_config_log()
    {
        auto configText = baseConfig->allConfig.toStyledString();
        return "\nCurrent configuration in use:\n\n" + configText + "\nConfiguration is valid\n\n";
    }
};

#endif //DATABASE_API_CONFIGURATION_HPP

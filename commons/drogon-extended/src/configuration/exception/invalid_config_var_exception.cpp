#include <utility>

#include <drogon_extended/configuration/exceptions/invalid_config_var_exception.hpp>

InvalidConfigVarException::InvalidConfigVarException(std::string configVarName)
        : runtime_error("Config variable '" + configVarName + "' is not set or invalid!"),
          configVarName(std::move(configVarName))
{}

const char* InvalidConfigVarException::what() const noexcept
{
    return runtime_error::what();
}

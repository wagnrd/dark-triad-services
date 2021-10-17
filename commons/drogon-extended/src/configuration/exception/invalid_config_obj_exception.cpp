#include <utility>

#include <drogon_extended/configuration/exceptions/invalid_config_obj_exception.hpp>

InvalidConfigObjException::InvalidConfigObjException(std::string configObjName, std::exception& e)
        : runtime_error("Config object '" + configObjName + "' is not set or invalid:\n" + e.what()),
          configVarName(std::move(configObjName))
{}

const char* InvalidConfigObjException::what() const noexcept
{
    return runtime_error::what();
}

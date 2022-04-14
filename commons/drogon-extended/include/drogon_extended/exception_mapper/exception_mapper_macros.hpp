#ifndef DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_MACROS_HPP
#define DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_MACROS_HPP

#include "global_exception_mapper.hpp"

#define HANDLE_GLOBAL_EXCEPTIONS                                                      \
        GlobalExceptionMapper::handle_global_exceptions([&] { throw; }, callback );   \

#define HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)                       \
        GlobalExceptionMapper::handle_global_exceptions([&] {               \
            exceptionMapper.handle_exceptions([&] { throw; }, callback);    \
        }, callback );

#endif //DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_MACROS_HPP

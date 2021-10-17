#ifndef DATABASE_API_CHARACTERS_EXCEPTION_MAPPER_HPP
#define DATABASE_API_CHARACTERS_EXCEPTION_MAPPER_HPP

#include <drogon_extended/exception_mapper/exception_mapper.hpp>

class CharactersExceptionMapper: public ExceptionMapper {
public:
    void handle_exceptions(std::function<void()>&& controllerImplementation,
                           std::function<void(const drogon::HttpResponsePtr&)>& callback) override;
};

#endif //DATABASE_API_CHARACTERS_EXCEPTION_MAPPER_HPP

cmake_minimum_required(VERSION 3.1.0)
project(drogon_extended)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE INCLUDES "include/**.hpp")
file(GLOB_RECURSE SOURCES "src/**.cpp")

add_library(
        drogon_extended

        ${INCLUDES}
        ${SOURCES}
)

# Drogon (web service framework)
add_subdirectory("lib/drogon")

# jwt-cpp (JWT library)
set(JWT_CPP_INCLUDES "lib/jwt-cpp/include")

target_include_directories(
        drogon_extended PUBLIC

        "include"
        ${JWT_CPP_INCLUDES}
)

target_link_libraries(
        drogon_extended PUBLIC

        drogon
)

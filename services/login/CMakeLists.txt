cmake_minimum_required(VERSION 3.1.0)
project(login_service)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

string(TOLOWER "cmake-build-${CMAKE_BUILD_TYPE}" build_dir)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${build_dir})

file(GLOB_RECURSE INCLUDES "include/**.hpp")
file(GLOB_RECURSE SOURCES "src/**.cpp")

add_executable(
        login_service

        ${INCLUDES}
        ${SOURCES}
)

# String format lib (to be exchanged with std::format in c++20)
find_package(fmt)

target_link_libraries(
        login_service PUBLIC

        drogon_extended
        fmt
)

cmake_minimum_required(VERSION 3.1.0)
project(dark_triad_services)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# commons
add_subdirectory("commons/drogon-extended")

#services
add_subdirectory("services/login")
add_subdirectory("services/database")
cmake_minimum_required(VERSION 3.15...4.4)
project(NSFlow VERSION 1.0
		DESCRIPTION "Simulator"
		LANGUAGES CXX)
include(FetchContent)
include(CTest)
FetchContent_Declare(catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.15.0)
FetchContent_MakeAvailable(catch2)

add_library(version STATIC src/version.cpp)
target_include_directories(version PUBLIC include)
add_executable(main apps/main.cpp)
target_link_libraries(main PRIVATE version)

add_executable(nsflow_tests tests/test_version.cpp)
target_link_libraries(nsflow_tests PRIVATE version Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(nsflow_tests)


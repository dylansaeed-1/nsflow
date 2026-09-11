cmake_minimum_required(VERSION 3.15...4.4)
project(NSFlow VERSION 1.0
		DESCRIPTION "Simulator"
		LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include(CTest)
FetchContent_Declare(catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.15.0)
FetchContent_MakeAvailable(catch2)

add_library(nsflow_core STATIC 	src/field2d.cpp
								src/boundary.cpp)
target_include_directories(nsflow_core PUBLIC include)

add_executable(main apps/main.cpp)
target_link_libraries(main PRIVATE nsflow_core)

add_executable(nsflow_tests tests/test_vec2.cpp
							tests/test_field2d.cpp
							tests/test_boundary.cpp
							)

target_link_libraries(nsflow_tests PRIVATE nsflow_core Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(nsflow_tests)

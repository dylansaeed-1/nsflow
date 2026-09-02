cmake_minimum_required(VERSION 3.15...4.4)
project(NSFlow VERSION 1.0
		DESCRIPTION "Simulator"
		LANGUAGES CXX)

add_library(version STATIC src/version.cpp)
target_include_directories(version PUBLIC include)
add_executable(main apps/main.cpp)
target_link_libraries(main PRIVATE version)


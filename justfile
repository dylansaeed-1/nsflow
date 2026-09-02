default:
    @just --list
build:
    cmake --preset default 
    cmake --build build
test: build
    ctest --test-dir build --output-on-failure
run: build
    ./build/main
clean:
    rm -rf build
fmt:
    clang-format -i src/*.cpp apps/*.cpp tests/*.cpp include/nsflow/*.hpp
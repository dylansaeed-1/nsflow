#include "catch2/catch_approx.hpp"
#include "nsflow/field2d.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
TEST_CASE("Field2D initialisation") {
    const auto g = nsflow::Grid(3, 3, 1.0, 1.0, 1);
    const auto f = nsflow::Field2D(g);
    SECTION("0-Constructor") {
        for (auto i = -1; i <= f.nx(); ++i) {
            for (auto j = -1; j <= f.ny(); ++j) {
                REQUIRE(f(i, j) == Catch::Approx(0.0));
            }
            std::cout << std::endl;
        }
    }
}
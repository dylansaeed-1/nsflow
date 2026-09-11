#include "catch2/catch_approx.hpp"
#include "catch2/catch_message.hpp"
#include "nsflow/field2d.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Field2D initialisation") {
    const auto g = nsflow::Grid(3, 5, 1.0, 1.0, 3);
    const auto f = nsflow::Field2D(g);
    SECTION("0-Constructor") {
        // Interior starts from (0,0), ghost cells at (-g, -g) to (g-1, g-1)
        // Loops over all cells
        for (auto i = -f.ghost(); i < f.nx() + f.ghost(); ++i) {
            for (auto j = -1; j <= f.ny(); ++j) {
                INFO("Cell (" << i << ", " << j << ")");
                REQUIRE(f(i, j) == Catch::Approx(0.0));
            }
        }
    }
}
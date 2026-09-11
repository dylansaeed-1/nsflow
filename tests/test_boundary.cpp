#include "catch2/catch_approx.hpp"
#include "catch2/catch_message.hpp"
#include "nsflow/boundary.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Boundary condition") {
    const auto g = nsflow::Grid(3, 5, 1.0, 1.0, 1);
    auto f = nsflow::Field2D(g);
    f.fill(1.0);
    for (int i = 0; i < f.nx(); ++i){
        for (int j = 0; j < f.ny(); ++j){
            f(i, j) = i + 10.0*j;
        }
    }

    SECTION("Dirichlet") {
        // Interior filled with 1.0, boun
        auto bc = nsflow::Dirichlet(2.0);
        bc.apply(g, nsflow::Side2D::LEFT, f);
        for (int j = 0; j < f.ny(); ++j) {
            INFO("Index " << j << ", f(-1, " << j << "): " << f(-1, j) << "f(0): " << f(0,j));
            REQUIRE((f(-1, j) + f(0, j)) / 2 == Catch::Approx(2.0));
        }
    }
    SECTION("Neumann"){
        auto bc = nsflow::Neumann(2.0);
        bc.apply(g, nsflow::Side2D::LEFT, f);
        for(int j  = 0; j < f.ny(); ++j){
            REQUIRE((f(-1, j) - f(0, j))/g.dx() == Catch::Approx(2.0));
        }
    }
    SECTION("Right boundary"){
        auto bc = nsflow::Neumann(2.0);
        bc.apply(g, nsflow::Side2D::RIGHT, f);
        for(int j  = 0; j < f.ny(); ++j){
            INFO("Index " << j << ", f(ny-1, " << j << "): " << f(f.ny()-1, j) << "f(ny): " << f(f.ny(),j));
            REQUIRE((f(f.nx(), j) - f(f.nx()-1, j))/g.dx() == Catch::Approx(2.0));
        }
    }
}
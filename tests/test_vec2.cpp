#include "catch2/catch_approx.hpp"
#include "nsflow/vec2.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Vec2 arithmetic"){
    nsflow::Vec2 a{1.5, 2.6};
    nsflow::Vec2 b{1.1, 2.2};
    SECTION("Addition commutative and identity"){
        REQUIRE(a + b == b + a);
        REQUIRE(a + (-a) == nsflow::Vec2{0.0, 0.0});
        REQUIRE(a + nsflow::Vec2{0.0 ,0.0} == a);
    }
    SECTION("norm, norm squared and all that..."){
        nsflow::Vec2 v{3.0, 4.0};
        REQUIRE(nsflow::norm(v) == Catch::Approx(5.0));
        REQUIRE(nsflow::norm_squared(v) == Catch::Approx(25.0));

    }

}
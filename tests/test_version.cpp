#include <catch2/catch_test_macros.hpp>
#include "nsflow/version.hpp"

TEST_CASE("Testing the test"){
    REQUIRE(not version().empty());
}


#include "nsflow/version.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Testing the test") { REQUIRE(not version().empty()); }

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Basic assert", "[sanity]")
{
    REQUIRE(1==1);
}

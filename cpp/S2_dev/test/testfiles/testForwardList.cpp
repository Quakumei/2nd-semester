#include "../src/ForwardList.hpp"
#include <forward_list>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace tampio;

TEST_CASE("ForwardList works as intended", "[ForwardList]")
{
  ForwardList< int > fl;
}

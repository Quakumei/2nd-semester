
#include "../src/ForwardList.hpp"
#include <forward_list>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("ForwardList works as intended", "[ForwardList]")
{
  tampio::ForwardList< int > fl;
  std::forward_list< int > flstl;
}

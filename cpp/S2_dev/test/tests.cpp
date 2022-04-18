
#include "../common/List.hpp"
// #include "../src/ForwardList.hpp"
#include <forward_list>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

template< class T >
using ForwardList = tampio::List< T >;

TEST_CASE("1==1", "[Sanity]")
{
  REQUIRE(1 == 1);
}

TEST_CASE("ForwardList works as <forward_list>", "[Unit]")
{
  REQUIRE(1 == 1);

  ForwardList< int > tamp_fl;
  std::forward_list< int > stl_fl;

  // Basic operations
  for (int i = 0; i < 10; i++)
  {
    tamp_fl.pushHead(i);
    stl_fl.push_front(i);
  }
  for (int i = 0; i < 10; i++)
  {
    REQUIRE(tamp_fl.top() == stl_fl.front());
    stl_fl.pop_front();
    tamp_fl.rmFront();
  }

  for (int i = 0; i < 100; i++)
  {
    tamp_fl.pushHead(i);
    stl_fl.push_front(i);
  }

  for (int i = 0; i < 100; i++)
  {
    REQUIRE(tamp_fl.top() == stl_fl.front());
    stl_fl.pop_front();
    tamp_fl.rmFront();
  }

  // Iteration
  for (int i = 0; i < 5; i++)
  {
    tamp_fl.pushHead(i);
    stl_fl.push_front(i);
  }

  // for (auto el : stl_fl)
  // {
  //   INFO("stl_fl: " << el);
  // }

  std::forward_list< int >::iterator it = stl_fl.begin();
  REQUIRE(*it == tamp_fl.top());
  tamp_fl.rmFront();
  REQUIRE(*(++it) == tamp_fl.top());

  // "Calling front on an empty container is undefined"
  // REQUIRE_THROWS(stl_fl.front());
  // REQUIRE_THROWS(tamp_fl.top());
}
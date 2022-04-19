
#include "../src/List.hpp"
// #include "../src/ForwardList.hpp"
#include <forward_list>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

  // "Calling front on an empty container is undefined"
  // REQUIRE_THROWS(stl_fl.front());
  // REQUIRE_THROWS(tamp_fl.top());
}

TEST_CASE("Custom iterator doing good!", "[Unit]")
{
  ForwardList< int > tamp_fl;
  std::forward_list< int > stl_fl;
  // Iteration
  for (int i = 0; i < 5; i++)
  {
    tamp_fl.pushHead(i);
    stl_fl.push_front(i);
  }
  std::forward_list< int >::iterator it_stl = stl_fl.begin();
  ForwardList< int >::Iterator it_tamp = tamp_fl.begin();
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(*(it_stl++) == *(it_tamp++));
  }

  // for (auto el : stl_fl)
  // {
  //   INFO("stl_fl: " << el);
  // }
}
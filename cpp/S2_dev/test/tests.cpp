#include "../src/ForwardList.hpp"
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

  tampio::ForwardList< int > tamp_fl;
  std::forward_list< int > stl_fl;

  // Basic operations
  for (int i = 0; i < 10; i++)
  {
    tamp_fl.pushFront(i);
    stl_fl.push_front(i);
  }
  for (int i = 0; i < 10; i++)
  {
    REQUIRE(tamp_fl.front() == stl_fl.front());
    stl_fl.pop_front();
    tamp_fl.deleteFront();
  }

  for (int i = 0; i < 100; i++)
  {
    tamp_fl.pushFront(i);
    stl_fl.push_front(i);
  }

  for (int i = 0; i < 100; i++)
  {
    REQUIRE(tamp_fl.front() == stl_fl.front());
    stl_fl.pop_front();
    tamp_fl.deleteFront();
  }

  // "Calling front on an empty container is undefined"
  // REQUIRE_THROWS(stl_fl.front());
  // REQUIRE_THROWS(tamp_fl.top());
  REQUIRE(stl_fl.empty());
  REQUIRE(tamp_fl.empty());
}

TEST_CASE("Custom iterator doing good!", "[Unit]")
{
  tampio::ForwardList< int > tamp_fl;
  std::forward_list< int > stl_fl;
  // Iteration
  for (int i = 0; i < 5; i++)
  {
    tamp_fl.pushFront(i);
    stl_fl.push_front(i);
  }
  std::forward_list< int >::iterator it_stl = stl_fl.begin();
  tampio::ForwardList< int >::Iterator it_tamp = tamp_fl.beforeBegin()++;
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(*(it_stl++) == *(it_tamp++));
  }
}
#endif
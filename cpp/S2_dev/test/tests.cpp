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
  tampio::ForwardList< int >::Iterator it_tamp = tamp_fl.begin();
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(*(it_stl++) == *(it_tamp++));
  }

  std::forward_list< int >::iterator it_stl_bb = stl_fl.before_begin();
  tampio::ForwardList< int >::Iterator it_tamp_bb = tamp_fl.beforeBegin();
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(*(++it_stl_bb) == *(++it_tamp_bb));
  }

  // insertAfter
  // first
  const int HOLY = 42;
  tamp_fl.insertAfter(tamp_fl.beforeBegin(), HOLY);
  stl_fl.insert_after(stl_fl.before_begin(), HOLY);
  it_stl = stl_fl.begin();
  it_tamp = tamp_fl.begin();
  REQUIRE(*(it_stl) == *(it_tamp));
  REQUIRE(HOLY == *(it_tamp));

  //   // last
  const int HOLY_2 = 43;
  std::cout << "insert ready 0";
  it_tamp = tamp_fl.insertAfter(tamp_fl.end(), HOLY_2);
  REQUIRE(HOLY_2 == *(it_tamp));
  std::cout << "insert done 1";

  // it_stl_bb = stl_fl.before_begin();
  it_tamp_bb = tamp_fl.beforeBegin();
  for (int i = 0; i < 7; i++)
  {
    std::cout << '\n' << *(++it_tamp_bb);
  }
  // stl_fl.insert_after(stl_fl.end(), HOLY_2);
  // std::cout << "insert done 2";
  // it_stl = stl_fl.end();
  // it_tamp = tamp_fl.end();

  // REQUIRE(*(it_stl) == *(it_tamp));
}

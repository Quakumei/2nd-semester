#include "../src/Stack.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Pushing and popping works well", "[Stack]"){
    Stack<int> stack;

    REQUIRE_THROWS(stack.pop());
    stack.push(5);
    stack.push(2);
    stack.push(57);
    stack.push(10);
    stack.push(7);
    stack.push(8);
    stack.push(22);
    REQUIRE(stack.pop() == 22);
    REQUIRE(stack.pop() == 8);
    REQUIRE(stack.pop() == 7);
    REQUIRE(stack.pop() == 10);
    stack.push(89);
    stack.push(15);
    REQUIRE(stack.pop() == 15);
    REQUIRE(stack.pop() == 89);
    REQUIRE(stack.pop() == 57);    
}

        




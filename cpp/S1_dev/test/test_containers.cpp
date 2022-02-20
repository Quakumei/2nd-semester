#include "../src/Stack.cpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("pop&push", "[Stack]"){
    Stack<int> st;
    st.push(1);
    REQUIRE(st.getSize() == 1);
    REQUIRE(st.drop() == 1);
    REQUIRE(st.drop() == 3);
    REQUIRE(st.drop() == 2);
    REQUIRE(st.drop() == 1);
}

        




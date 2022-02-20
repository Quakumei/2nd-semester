#include "../src/Stack.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Stack stores values well", "[Stack]"){
    Stack<int> st;
    SECTION( "pushing 4 values"){
        REQUIRE_NOTHROW([&](){
            st.push(1);
            st.push(2);
            st.push(1);
            st.push(2);
        });
    }
}



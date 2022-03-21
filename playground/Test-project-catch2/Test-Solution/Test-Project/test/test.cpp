 #include "../src/Calc.h"

 #define CATCH_CONFIG_MAIN
 #include "catch.hpp"

 TEST_CASE("Addition is computed properly", "[Calc]"){
     Calc * calculator = new Calc();
     REQUIRE(calculator->add(3,5) == 8);
     REQUIRE(calculator->add(3,5) == calculator->add(5,3));
     REQUIRE_FALSE(calculator->add(0.5,0.5) == 1);
 }

 TEST_CASE("Fail case", "[Calc]"){
     Calc * calculator = new Calc();
     REQUIRE_FALSE(calculator->a == 42);
 }


#include "hwlib.hpp"
#include "array.hpp"
#include <ostream>

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

TEST_CASE("add"){
    intset set;
    set.add(5);
    std::stringstream s;
   s << set;
   REQUIRE( s.str() == "[5][0][0][0][0][0][0][0][0][0]\n" );
}

TEST_CASE("remove"){
    intset set;
    set.add(5);
    set.remove(5);
    std::stringstream s;
   s << set;
   REQUIRE( s.str() == "[0][0][0][0][0][0][0][0][0][0]\n" );
}

TEST_CASE("contain"){
    intset set;
    set.add(5);
   REQUIRE( set.contains(5) == 1 );
}

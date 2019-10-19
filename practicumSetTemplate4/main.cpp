#include "hwlib.hpp"
#include "array.hpp"
#include <ostream>

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

TEST_CASE("max"){
    intset<char, 10> set;
    set.add('a');
    set.add('g');
    set.add('z');
    REQUIRE( set.max() == 'z' );
}
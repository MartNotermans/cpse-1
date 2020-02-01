#include "hwlib.hpp"

int main( void ){   
   auto led = hwlib::target::led;
   hwlib::blink( led );
}
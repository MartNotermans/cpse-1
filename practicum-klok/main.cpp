#include "hwlib.hpp"
#include "coordinates.hpp"
#include "clock.hpp"
#include "draw.hpp"


int main( void ){	
    // wait for the PC console to start
    hwlib::wait_ms( 500 );   
   
    constexpr coordinates cords;
    

    namespace target = hwlib::target;
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

    // use the buffered version
    auto oled = hwlib::glcd_oled( i2c_bus, 0x3c );  

    clock oledClock(cords, oled);
    
    int time[2] = {9,30};
    oledClock.update(time);
}


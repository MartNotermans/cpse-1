#ifndef CLOCK_HPP
#define CLOCK_HPP

//#include "draw.hpp"
#include "coordinates.hpp"

class clock{
private:
    const coordinates& cords;
    const hwlib::glcd_oled oled;
public:
    clock(const coordinates& cords, hwlib::glcd_oled& oled):
    cords (cords), oled (oled)
    {
        // namespace target = hwlib::target;
   
        // auto scl = target::pin_oc( target::pins::scl );
        // auto sda = target::pin_oc( target::pins::sda );
    
        // auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    
        // // use the buffered version
        // auto oled = hwlib::glcd_oled( i2c_bus, 0x3c );  

        oled.clear();
        //circle outline (oled, hwlib::xy(cords.midpoint[0],cords.midpoint[1]), cords.rad);
        for(int i = 0; i < 12; ++i){
            oled.write(hwlib::xy(cords.getHourX(i), cords.getHourY(i)));
        }

        //outline.draw();
        oled.flush();
   
    }

    //void outline();
};

#endif
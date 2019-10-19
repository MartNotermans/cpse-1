#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "draw.hpp"
#include "coordinates.hpp"

class clock{
private:
    const coordinates& cords;
    hwlib::glcd_oled oled;
public:
    clock(const coordinates& cords, hwlib::glcd_oled& oled):
    cords (cords), oled (oled)
    {
        oled.clear();
        for(int i = 0; i < 60; i += 5){
            oled.write(hwlib::xy(cords.getXBig(i), cords.getYBig(i)));
        }

        for(int i = 0; i < 60; i += 15){
            int tempCords[2] = {cords.getXBig(i), cords.getYBig(i)};
        
            circle indication(oled, hwlib::xy(tempCords[0], tempCords[1]), 1);
            indication.draw();
        }
        oled.flush();
    }

    void update(int time[2]);
    void outline();
    void clockHands(int time[2]);
};

#endif
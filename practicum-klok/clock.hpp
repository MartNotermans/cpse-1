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
    {}

    void update(int time[2]);
    void outline();
    void clockHands(int time[2]);
};

#endif
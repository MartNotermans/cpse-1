#include "clock.hpp"

void clock::update(int time[2]){
    oled.clear();
    
    outline();
    clockHands(time);

    oled.flush();
}

void clock::outline(){
    for(int i = 0; i < 12; ++i){
        oled.write(hwlib::xy(cords.getHourX(i), cords.getHourY(i)));
    }

    for(int i = 0; i < 12; i += 3){
        int tempCords[2] = {cords.getHourX(i), cords.getHourY(i)};
        
        circle indication(oled, hwlib::xy(tempCords[0], tempCords[1]), 1);
        indication.draw();
    }
}

void clock::clockHands(int time[2]){
    line hourHand (oled, hwlib::xy (cords.midpoint[0],cords.midpoint[1]),
                         hwlib::xy (cords.getHourX(time[0]) ,cords.getHourY(time[1]) ) );
    hourHand.draw();
}
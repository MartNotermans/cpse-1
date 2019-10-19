#include "clock.hpp"
#include "hwlib.hpp"

void clock::update(int time[2]){
    oled.clear();
    
    clockHands(time);
    outline();
    

    oled.flush();
}

void clock::outline(){
    for(int i = 0; i < 60; i+=5){
        oled.write(hwlib::xy(cords.getXBig(i), cords.getYBig(i)));
    }

    for(int i = 0; i < 60; i += 15){
        int tempCords[2] = {cords.getXBig(i), cords.getYBig(i)};
        
        circle indication(oled, hwlib::xy(tempCords[0], tempCords[1]), 1);
        indication.draw();
    }
}

void clock::clockHands(int time[2]){
    int ofset = (round(time[1]/12.0));
    //hwlib::cout<<ofset<<hwlib::endl;
    line hourHand (oled, hwlib::xy (cords.midpoint[0],cords.midpoint[1]),
                         hwlib::xy (cords.getXSmall(time[0]*5 + ofset ) 
                                   ,cords.getYSmall(time[0]*5 + ofset ) ) );
    hourHand.draw();

    line minuteHand (oled, hwlib::xy (cords.midpoint[0],cords.midpoint[1]),
                        hwlib::xy (cords.getXBig(time[1])
                                  ,cords.getYBig(time[1]) ) );
    minuteHand.draw();
}
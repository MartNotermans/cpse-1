// #include "clock.hpp"
// #include "hwlib.hpp"
// #include "draw.hpp"
// #include "coordinates.hpp"



// void clock::outline(){
//     oled.clear();
//     //circle outline (oled, hwlib::xy(cords.midpoint[0],cords.midpoint[1]), cords.rad);
//     for(int i = 0; i < 12; ++i){
//         oled.write(hwlib::xy(cords.getHourX(i), cords.getHourY(i)));
//     }

//     //outline.draw();
//     oled.flush();
// }
#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include "hwlib.hpp"
#include <math.h>
#define PI 3.14159265358979323846

class coordinates {
private:
    int coordinatesArray[60][2] = {};
public:
    int midpoint[2] = {63, 31};
    int rad = 30;

    constexpr coordinates(){
        for(int i = 0; i < 60; i++){

        int angle_deg = (i * 6); //angle in degrees

        float x = rad * cos(angle_deg * PI/180);
        float y = rad * sin(angle_deg * PI/180);

        coordinatesArray[i][0] = x+midpoint[0];
        coordinatesArray[i][1] = y+midpoint[1];
        }
    };

    int getMinuteX(int minute) const{
    return coordinatesArray[minute][0];
    }
    int getMinuteY(int minute) const{
        return coordinatesArray[minute][1];
    }

    int getHourX(int hour) const{
        return coordinatesArray[hour*5][0];
    }
    int getHourY(int hour) const{
        return coordinatesArray[hour*5][1];
    }
};

#endif
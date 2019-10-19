#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include "hwlib.hpp"
#include <math.h>
#define PI 3.14159265358979323846

class coordinates {
private:
    int coordinatesArrayBig[60][2] = {};
    int coordinatesArraySmall[60][2] = {};
public:
    int midpoint[2] = {63, 31};
    int radBig = 30;
    int radSmall = 20;

    constexpr coordinates(){
        for(int i = 0; i < 60; i++){
            int angle_deg = (i * 6); //angle in degrees

            float Bx = radBig * sin(angle_deg * PI/180);
            float By = radBig * -cos(angle_deg * PI/180);
            coordinatesArrayBig[i][0] = Bx+midpoint[0];
            coordinatesArrayBig[i][1] = By+midpoint[1];


            float Sx = radSmall * sin(angle_deg * PI/180);
            float Sy = radSmall * -cos(angle_deg * PI/180);
            coordinatesArraySmall[i][0] = Sx+midpoint[0];
            coordinatesArraySmall[i][1] = Sy+midpoint[1];
        }
    };

    int getXBig(int minute) const{
        return coordinatesArrayBig[minute][0];
    }
    int getYBig(int minute) const{
        return coordinatesArrayBig[minute][1];
    }

    // int getHourXBig(int hour) const{
    //     return coordinatesArrayBig[hour*5][0];
    // }
    // int getHourYBig(int hour) const{
    //     return coordinatesArrayBig[hour*5][1];
    // }


    int getXSmall(int minute) const{
        return coordinatesArraySmall[minute][0];
    }
    int getYSmall(int minute) const{
        return coordinatesArraySmall[minute][1];
    }

    // int getHourXSmall(int hour) const{
    //     return coordinatesArraySmall[hour*5][0];
    // }
    // int getHourYSmall(int hour) const{
    //     return coordinatesArraySmall[hour*5][1];
    // }
};

#endif
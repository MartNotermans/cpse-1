#include "array.hpp"
#include <ostream>
#include <array>

void intset::add(int value){
    if(index < 10){
        set[index] = value;
        index++;
    }
}

void intset::remove(int value){
    for(int i = 0; i < 10; i++){
        if(set[i] == value){
            for(int j = i; j < 9; j++){
                set[j] = set[j+1];
            }
            set[9] = 0;
            index = index-1;
        }
    }
}

bool intset::contains(int value){
    for(int i = 0; i < 10; i++){
        if(set[i] == value){
            return 1;
        }
    }
    return 0;
}

std::ostream& operator<<( std::ostream & lhs, const intset & rhs ){
    for(int i = 0; i < 10; i++){
        lhs<<"["<<rhs.set[i]<<"]";
    }
    lhs<<std::endl;
    return lhs;
}
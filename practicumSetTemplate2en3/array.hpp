#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <array>

template <typename T, int n>
class intset{
private:
    std::array<T, n> set = {};
    int index = 0;
public:
    intset(){}

    void add(T value){
        if(index < n){
            set[index] = value;
            index++;
        }
    }

    void remove(T value){
        for(int i = 0; i < n; i++){
            if(set[i] == value){
                for(int j = i; j < n-1; j++){
                    set[j] = set[j+1];
                }
                set[n] = 0;
                index = index-1;
            }
        }
    }

    bool contains(T value){
        for(int i = 0; i < n; i++){
            if(set[i] == value){
                return 1;
            }
        }
        return 0;
    }

    T max(){
        T temp = set[0];
        for(int i = 0; i < n; i++){
            if(set[i] > temp){
                temp = set[i];
            }
        }
        return temp;
    }

    friend std::ostream& operator<<(std::ostream & lhs , const intset & rhs){
        for(int i = 0; i < n; i++){
            lhs<<"["<<rhs.set[i]<<"]";
        }
        lhs<<std::endl;
        return lhs;
    }

};
#endif
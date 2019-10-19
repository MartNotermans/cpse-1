#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <array>

class intset{
private:
    std::array<int, 10> set = {};
    int index = 0;
public:
    intset(){}

    void add(int value);

    void remove(int value);

    bool contains(int value);

    friend std::ostream& operator<<(std::ostream & lhs , const intset & rhs);
};

#endif
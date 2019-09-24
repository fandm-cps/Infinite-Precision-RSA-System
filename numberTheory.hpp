#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

#include "ReallyLongInt.hpp"
#include <stdio.h>
#include <string>
#include <vector>

struct arrReallyLongInt{ 
    ReallyLongInt arr[3]; 
}; 


class numberTheory{
    public:
    arrReallyLongInt extendedEulid(ReallyLongInt a, ReallyLongInt b);
};

#endif
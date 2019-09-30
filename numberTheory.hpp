#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

#include "ReallyLongInt.hpp"
#include <stdio.h>
#include <string>
#include <vector>


class numberTheory{
    public:
    void extendedEulid(ReallyLongInt a, ReallyLongInt b, ReallyLongInt* d, ReallyLongInt* x, ReallyLongInt* y);
};

#endif
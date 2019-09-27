#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void numberTheory::extendedEulid(ReallyLongInt a, ReallyLongInt b, ReallyLongInt* d, ReallyLongInt* x, ReallyLongInt* y){
    if(b.toString() == "0"){
        ReallyLongInt x_tmp(1);
        ReallyLongInt y_tmp;
        *d = a;
        *x = x_tmp;
        *y = y_tmp;
        return;
    }
    else{
        this->extendedEulid(b, a % b, d, x, y);
        ReallyLongInt x_1 = *y;
        ReallyLongInt y_1 = *x - *y * (a / b);
        *x = x_1;
        *y = y_1;
    }
    return;
}

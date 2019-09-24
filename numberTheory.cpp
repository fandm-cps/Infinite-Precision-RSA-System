#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
#include "ReallyLongInt.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include <list>

using namespace std;

arrReallyLongInt numberTheory::extendedEulid(ReallyLongInt a, ReallyLongInt b){
    arrReallyLongInt result;
    if(b.toString() == "0"){
        ReallyLongInt x(1);
        ReallyLongInt y;
        result.arr[0] = a;
        result.arr[1] = x;
        result.arr[2] = y;
        return result;
    }
    else{
        result = this->extendedEulid(b, a % b);
        ReallyLongInt x_1 = result.arr[2];
        ReallyLongInt y_1 = result.arr[1] - result.arr[2] * (a / b);
        result.arr[1] = x_1;
        result.arr[2] = y_1;
    }
    return result;
}

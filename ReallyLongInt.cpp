//
//  ReallyLongInt.cpp
//  project1
//
//  Created by 肖正义 on 9/10/19.
//  Copyright © 2019 Zhengyi Xiao. All rights reserved.
//

#include "ReallyLongInt.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

ReallyLongInt::ReallyLongInt(void){
    digits = new vector<bool>(16, false);
    size = 16;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    digits = new vector<bool>;
    isNeg = (num < 0);
    //size = int(log2(num));
    size = 0;
    while(num != 0){
        if(num % 2 != 0)
            digits->push_back(true);
        else
            digits->push_back(false);
        num /= 2;
        size ++;
    }
}

ReallyLongInt::ReallyLongInt(const string &numStr){
    
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    digits = other.digits;
    size = other.size;
    isNeg = other.isNeg;
}

ReallyLongInt::~ReallyLongInt(void)
{
    std::cout << "Destruct " << toString() << std::endl;
    delete digits;
}

string ReallyLongInt::toString() const{
    int ans = 0;
    for(int i = 0; i < size; i++)
        if((*digits)[i] == true)
            ans += pow(2, i);
    isNeg == true ? ans *= -1 : ans;
    return to_string(ans);
}

string ReallyLongInt::toStringBinary() const{
    string str = "";
    for(int i = 0; i < size; i++)
        (*digits)[i] == true ? str += "1" : str += "0";
    return str;
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    return (other.isNeg == this->isNeg) and (*other.digits == *this->digits);
}

bool ReallyLongInt::absGreater(const ReallyLongInt &other)const{
    for(int i = 0; i < this->size; i++)
        if((*digits)[i] == false and (*other.digits)[i] == true)
            return false;
    return true;
}


bool ReallyLongInt::greater(const ReallyLongInt& other)const{
    return (absGreater(other) and not isNeg) or (not absGreater(other) and other.isNeg);
}


//
//  ReallyLongInt.cpp
//  project1
//
//  Created by 肖正义 on 9/10/19.
//  Copyright © 2019 Zhengyi Xiao. All rights reserved.
//
#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class ReallyLongInt{
    
private:
    vector<bool> *digits;
    unsigned int size;
    bool isNeg;
    bool absGreater(const ReallyLongInt& other)const;

public:
    ReallyLongInt();
    ~ReallyLongInt();
    ReallyLongInt(long long num);
    ReallyLongInt(const string &numStr);
    ReallyLongInt(const ReallyLongInt& other);
    
    string toString() const;
    string toStringBinary() const;
    
    bool equal(const ReallyLongInt& other) const;
    bool greater(const ReallyLongInt& other) const;
};

#endif


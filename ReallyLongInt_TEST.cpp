//
//  ReallyLongInt_TEST.cpp
//  project1
//
//  Created by 肖正义 on 9/11/19.
//  Copyright © 2019 Zhengyi Xiao. All rights reserved.
//

#include "ReallyLongInt.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int main(){
    cout << "==========new int a ==========" << endl;
    long long first = 3;
    ReallyLongInt a(first);
    std::cout << "num            : "<< first << std::endl;
    std::cout << "toStringBinary : "<< a.toStringBinary() << std::endl;
    std::cout << "toString       : " << a.toString() << std::endl;
    //std::cout << "size           : " << a.size << std::endl;
    
    cout << "==========new int b ==========" << endl;
    int second = 0;
    ReallyLongInt b(second);
    std::cout << "num            : "<< second << std::endl;
    std::cout << "toStringBinary : "<< b.toStringBinary() << std::endl;
    std::cout << "toString       : " << b.toString() << std::endl;
    //std::cout << "size           : " << b.size << std::endl;
    cout << "========== compare ==========" << endl;
    std::cout << "equal test     : " << a.equal(b) << std::endl;
    //std::cout << "absGreater test: "<<a.absGreater(b) << std::endl;
    std::cout << "greater test   : "<< a.greater(b) << std::endl;
    cout << "==========copy test==========" << endl;
    cout << "==========new int c ==========" << endl;
    ReallyLongInt c(b);
    std::cout << "toStringBinary : "<< c.toStringBinary() << std::endl;
    std::cout << "toString       : " << c.toString() << std::endl;
    std::cout << "equal test     : " << c.equal(b) << std::endl;
    std::cout << "equal test     : " << c.equal(a) << std::endl;
    
    cout << "==========string test==========" << endl;
    cout << "==========new int d ==========" << endl;
    ReallyLongInt d("0");
    std::cout << "toStringBinary : "<< d.toStringBinary() << std::endl;
    std::cout << "toString       : " << d.toString() << std::endl;
    std::cout << "equal test     : " << d.equal(c) << std::endl;
    std::cout << "equal test     : " << d.equal(b) << std::endl;
    
    cout << "==========new int e ==========" << endl;
    ReallyLongInt e("0");
    std::cout << "toStringBinary : "<< e.toStringBinary() << std::endl;
    std::cout << "toString       : " << e.toString() << std::endl;

    
    return 0;
}

#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.cpp"
#include "numberTheory.cpp"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

#ifndef CATCH_CONFIG_MAIN
using namespace std;

int main(int argc, char** argv){

    ReallyLongInt p(argv[1]);
    ReallyLongInt q(argv[2]);

    if(not p.isPrime() or not q.isPrime()){
        cout << "Either the first or the second number is not a prime, please re-run the program and try again!" << endl;
        return 1;
    }
    ReallyLongInt n = p * q;
    ReallyLongInt t = (p - 1) * (q - 1);
    
    cout << n.toString() << " " << t.toString() <<endl;

    ReallyLongInt e(1);
    numberTheory nT;
    ReallyLongInt* d = new ReallyLongInt();
    ReallyLongInt* x = new ReallyLongInt();
    ReallyLongInt* y = new ReallyLongInt();

    while(d->toString() != "1"){
        e = e + 1;
        nT.extendedEulid(e, t, d, x, y);
    }

    if(not x->greater(0))
        *x = (*x) + t;

    ofstream publicKey;
    publicKey.open(argv[3]);
    publicKey << e.toString() << " " << n.toString();
    publicKey.close();

    ofstream privateKey;
    privateKey.open(argv[4]);
    privateKey << x->toString() << " " << n.toString();
    privateKey.close();

    return 0; 
} 

#endif
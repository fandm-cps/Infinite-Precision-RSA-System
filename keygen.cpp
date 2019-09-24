#include "ReallyLongInt.hpp"
#include "ReallyLongInt.cpp"
#include "numberTheory.hpp"
#include "numberTheory.cpp"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>


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

    ReallyLongInt e(2);

    numberTheory nT;

    ReallyLongInt d;
    arrReallyLongInt gcd;
    while(d.toString() != "1"){
        gcd = nT.extendedEulid(e, t);
        d = gcd.arr[0];
        e = e + 1;
    }
    d = gcd.arr[1];
    if(not d.greater(0))
        d = -d;

    ofstream publicKey;
    publicKey.open(argv[3]);
    publicKey << e.toString() << " " << n.toString();
    publicKey.close();

    ofstream privateKey;
    privateKey.open(argv[4]);
    privateKey << d.toString() << " " << n.toString();
    privateKey.close();

    return 0; 
} 
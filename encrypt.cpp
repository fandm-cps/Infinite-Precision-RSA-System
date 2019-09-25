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
    ifstream publicKey(argv[1]);
    char c;

    ReallyLongInt e;
    ReallyLongInt n;
    if(publicKey.is_open()){
        string tmp = "";
        while (publicKey.get(c) and c != ' ')
            tmp += c;
        e = ReallyLongInt(tmp);

        tmp = "";
        while (publicKey.get(c) and c != ' ')
            tmp += c;
        n = ReallyLongInt(tmp);
    }
    else{
        cout << "the public key file is wrong!";
        return 1;
    }

    ifstream inputFile(argv[2]);
    ofstream outputFile(argv[3]);
    while (inputFile.get(c)){
        unsigned long long tmp = (unsigned long long)c;
        ReallyLongInt x(tmp);
        ReallyLongInt y = (x.exp(e)) % n;
        cout << c<< " "<< x.toString() << " " << e.toString() << " " << n.toString() << " " << y.toString() <<endl;
        outputFile << (y.toString()) << " ";
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}
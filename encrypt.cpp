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

    fstream inputFile(argv[2]);
    ofstream outputFile;
    outputFile.open(argv[3]);
    if(inputFile.is_open()){
        while (inputFile.get(c)){
            int ASCI = int(c);
            ReallyLongInt x(ASCI);
            ReallyLongInt y = x.exp(e) % n;
            outputFile << (y.toString());
            if(c == ' ')
                outputFile << " ";
        }
    }
    else{
        cout << "the public key file is wrong!";
        return 1;
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}
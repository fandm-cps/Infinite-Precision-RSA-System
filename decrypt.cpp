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
    ifstream privateKey(argv[1]);
    char c;

    ReallyLongInt d;
    ReallyLongInt n;
    if(privateKey.is_open()){
        string tmp = "";
        while (privateKey.get(c) and c != ' ')
            tmp += c;
        d = ReallyLongInt(tmp);

        tmp = "";
        while (privateKey.get(c) and c != ' ')
            tmp += c;
        n = ReallyLongInt(tmp);
    }
    else{
        cout << "the private key file is wrong!";
        return 1;
    }

    fstream inputFile(argv[2]);
    ofstream outputFile;
    outputFile.open(argv[3]);
    if(inputFile.is_open()){
        while (inputFile.get(c)){
            int ASCI = c;
            ReallyLongInt x(ASCI);
            ReallyLongInt y = x.exp(d) % n;
            int result = stoi(y.toString()); 
            outputFile << char(result) << " ";
        }
    }
    else{
        cout << "the private key file is wrong!";
        return 1;
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}
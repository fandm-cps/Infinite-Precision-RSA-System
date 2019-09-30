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

    ifstream inputFile(argv[2]);
    ofstream outputFile(argv[3]);
    string tmp;
    inputFile >> tmp;
    ReallyLongInt y(tmp);
    while(!inputFile.eof()){
        long long tmp_x = stoll((y.exp(d) % n).toString());
        char x = (char)tmp_x;
        outputFile << x;
        inputFile>> tmp;
        y = tmp;
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}
#include "ReallyLongInt.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>  
#include <cmath>



ReallyLongInt::ReallyLongInt(void){
    digits = new vector<bool>(16, false);
    size = 16;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    (isNeg = (num < 0)) ? num *= -1 : num;
    int counter = 0;

    for(long long power = 1; num >= power and counter != 62; counter++)
        power *= 2;

    size = pow(2, ceil(log2((counter == 0 or counter == 62)? counter += 1 : counter)));

    digits = new vector<bool>(size, false);
    for(int i = 0; i < size; i++){
        num % 2 != 0 ? (*digits)[i] = - true : (*digits)[i] = false;
        num /= 2;
    }
}

ReallyLongInt::ReallyLongInt(const string &numStr){
    long long num = 0;
    if(numStr.substr(0,1) != "-"){
        isNeg = false;
        for(int i = 0; i < numStr.length(); i++){
            num += ceil(std::stoi(numStr.substr(i,1)) * ceil(pow(10, numStr.length() - 1 - i)));
        }
    }
    else{
        size --;
        isNeg = true;
        for(int i = 1; i < numStr.length(); i++)
            num += std::stoi(numStr.substr(i,1)) * pow(10, numStr.length() - 1 - i);
    }
    int counter = 0;
    for(long long power = 1; num >= power; counter++){
        if(counter == 62){
            counter ++;
            break;
        }
        power *= 2;
    }
    num == 0 ? size = 1 : size = pow(2, ceil(log2(counter)));
    digits = new vector<bool>(size, false);
    for(int i = 0; i < size; i++){
        num % 2 != 0 ? (*digits)[i] = true : (*digits)[i] = false;
        num /= 2;
    }
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    digits = new vector<bool>(other.size, false);
    for(int i = 0; i < other.size; i++)
        (*digits)[i] = (*other.digits)[i];
    size = other.size;
    isNeg = other.isNeg;
}

ReallyLongInt::~ReallyLongInt(void)
{
    delete this->digits;
}

string ReallyLongInt::toString() const{
    long long ans = 0;
    for(int i = 0; i < size; i++){
        if((*digits)[i] == true){
            long long power = 1;
            for(int j = 0; j < i; j ++)
                    power *= 2;
            ans += power;
        }
    }
    isNeg == true ? ans *= -1 : ans;
    return to_string(ans);
}

string ReallyLongInt::toStringBinary() const{
    string str = "";
    if(size == 1)
        return "0";
    for(int i = size - 1; i >= 0; i--)
        (*digits)[i] == true ? str += "1" : str += "0";
    return str;
}

//return true if this and other have the same sign and the digits are the same
bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    return (other.isNeg == this->isNeg) and (*other.digits == *this->digits);
}

bool ReallyLongInt::absGreater(const ReallyLongInt &other)const{
    if(this->size > other.size)
        return true;
    else if (this->size < other.size)
        return false;
    for(int i = this->size - 1; i >= 0 ; i--)
        if((*digits)[i] == false and (*other.digits)[i] == true)
            return false;
        else if ((*digits)[i] == true and (*other.digits)[i] == false)
            return true;
    return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other)const{
    return (absGreater(other) and not isNeg) or (not absGreater(other) and other.isNeg);
}

/*


ReallyLongInt::ReallyLongInt(const string &numStr){
    if((numStr.substr(i,1) == "1") or (numStr.substr(i,1) == "3") or (numStr.substr(i,1) == "5") or
        (numStr.substr(i,1) == "7") or (numStr.substr(i,1) == "9"))
    string numStr_2 = "";
    int next_add = 0;
    int current_add = 0;
    for(int i = 0; i < numStr.length(); i++){
        if((numStr.substr(i,1) == "1") or (numStr.substr(i,1) == "3") or (numStr.substr(i,1) == "5") or
        (numStr.substr(i,1) == "7") or (numStr.substr(i,1) == "9"))
            next_add = 5;
        else
            next_add = 0;
        if((std::stoi(numStr.substr(i,1)) + current_add) != 0)
            numStr_2 += to_string((std::stoi(numStr.substr(i,1)) + current_add));
    }

}
*/
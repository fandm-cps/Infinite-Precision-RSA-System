#include "ReallyLongInt.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>  
#include <cmath>

#define DEBUG

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
        num % 2 != 0 ? (*digits)[i] = true : (*digits)[i] = false;
        num /= 2;
    }
}

ReallyLongInt::ReallyLongInt(const string &numStr){
    int num = 0;
    if(numStr.substr(0,1) != "-"){
        isNeg = false;
        for(int i = 0; i < numStr.length(); i++)
            num += std::stoi(numStr.substr(i,1)) * pow(10, numStr.length() - 1 - i);
    }
    else{
        size --;
        isNeg = true;
        for(int i = 1; i < numStr.length(); i++)
            num += std::stoi(numStr.substr(i,1)) * pow(10, numStr.length() - 1 - i);
    }
    
    long long power = 1;
    int counter = 0;
    for(counter = 0; num >= power; counter++){
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

#ifdef DEBUG 

#include "ReallyLongInt.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>  
#include <cmath>
int main(){
    cout << "==========new int a ==========" << endl;
    ReallyLongInt defalutTest();
    long long first = 9223372036854775807;
    ReallyLongInt a(first);
    std::cout << "num            : "<< first << std::endl;
    std::cout << "toStringBinary : "<< a.toStringBinary() << std::endl;
    std::cout << "toString       : " << a.toString() << std::endl;
    //std::cout << "size           : " << a.size << std::endl;

    cout << "==========new int b ==========" << endl;
    int second = -1234567;
    ReallyLongInt b(second);
    std::cout << "num            : "<< second << std::endl;
    std::cout << "toStringBinary : "<< b.toStringBinary() << std::endl;
    std::cout << "toString       : " << b.toString() << std::endl;
    //std::cout << "size           : " << b.size << std::endl;
    cout << "========== compare ==========" << endl;
    std::cout << "equal test     : " << a.equal(b) << std::endl;
    //std::cout << "absGreater test: "<<a.absGreater(b) << std::endl;
    std::cout << "greater test   : "<< a.greater(b) << std::endl;
    std::cout << "greater test   : "<< b.greater(a) << std::endl;
    ReallyLongInt f(9223372036854775807);
    std::cout << "greater test   : "<< a.greater(f) << std::endl;
    std::cout << "greater test   : "<< f.greater(a) << std::endl;
    cout << "==========copy test==========" << endl;
    cout << "==========new int c ==========" << endl;
    ReallyLongInt c(b);
    std::cout << "toStringBinary : "<< c.toStringBinary() << std::endl;
    std::cout << "toString       : " << c.toString() << std::endl;
    std::cout << "equal test     : " << c.equal(b) << std::endl;
    std::cout << "equal test     : " << c.equal(a) << std::endl;

    cout << "==========string test==========" << endl;
    cout << "==========new int d ==========" << endl;
    ReallyLongInt d("-1234567");
    std::cout << "toStringBinary : "<< d.toStringBinary() << std::endl;
    std::cout << "toString       : " << d.toString() << std::endl;
    std::cout << "equal test     : " << d.equal(c) << std::endl;
    std::cout << "equal test     : " << d.equal(b) << std::endl;

    cout << "==========new int e ==========" << endl;
    ReallyLongInt e("9223372036854775807");
    std::cout << "toStringBinary : "<< e.toStringBinary() << std::endl;
    std::cout << "toString       : " << e.toString() << std::endl;

    cout << "==========new int f ==========" << endl;
    ReallyLongInt h("0");
    std::cout << "toStringBinary : "<< h.toStringBinary() << std::endl;
    std::cout << "toString       : " << h.toString() << std::endl;

    cout << "==========new int g ==========" << endl;
    ReallyLongInt g(0);
    std::cout << "toStringBinary : "<< g.toStringBinary() << std::endl;
    std::cout << "toString       : " << g.toString() << std::endl;

    cout << "==========new int e ==========" << endl;
    ReallyLongInt i("-9223372036854775807");
    std::cout << "toStringBinary : "<< i.toStringBinary() << std::endl;
    std::cout << "toString       : " << i.toString() << std::endl;
    std::cout << "greater test   : "<< e.greater(g) << std::endl;
    std::cout << "greater test   : "<< e.greater(f) << std::endl;
    return 0;
}

#endif

#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class ReallyLongInt{
    
private:
    vector<bool> *digits;
    unsigned int size;
    bool isNeg;
    bool absGreater(const ReallyLongInt& other)const;
    
    ReallyLongInt absAdd(const ReallyLongInt& other) const;
    ReallyLongInt absSub(const ReallyLongInt& other) const;
    ReallyLongInt absMult(const ReallyLongInt& other) const;
    void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
    
    void flipSign();
    ReallyLongInt expHelper(ReallyLongInt base, ReallyLongInt exp);
    bool parity();
    void swap(ReallyLongInt other);
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
    
    void removeLeadingZeros(void);
    
    ReallyLongInt add(const ReallyLongInt& other) const;
    ReallyLongInt sub(const ReallyLongInt& other) const;
    ReallyLongInt mult(const ReallyLongInt& other) const;
    void div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
    
    ReallyLongInt operator-() const;
    
    ReallyLongInt& operator=(const ReallyLongInt& other);
    
    ReallyLongInt exp(const ReallyLongInt e);
    
    bool isPrime();
};

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y);

#endif

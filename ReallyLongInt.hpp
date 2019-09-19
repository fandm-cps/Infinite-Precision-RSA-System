#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP

#include <stdio.h>
#include <string.h>
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
    
    void flipSign();
    
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
    
    void swap(ReallyLongInt other);
    
    ReallyLongInt add(const ReallyLongInt& other) const;
    
    ReallyLongInt sub(const ReallyLongInt& other) const;
    
    ReallyLongInt absMult(const ReallyLongInt& other) const;
    
    ReallyLongInt operator-() const;
    
    ReallyLongInt& operator=(const ReallyLongInt& other);
    
};

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y);

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y);

#endif


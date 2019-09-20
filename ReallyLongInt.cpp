#include "ReallyLongInt.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>



ReallyLongInt::ReallyLongInt(void){
    digits = new vector<bool>(1, false);
    size = 1;
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
    this->removeLeadingZeros();
}

ReallyLongInt::ReallyLongInt(const string &numStr){
    long long num = stoll(numStr);
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
    this->removeLeadingZeros();
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    digits = new vector<bool>(other.size, false);
    for(int i = 0; i < other.size; i++)
        (*digits)[i] = (*other.digits)[i];
    size = other.size;
    isNeg = other.isNeg;
    this->removeLeadingZeros();
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
    for(int i = size - 1; i >= 0; i--)
        (*digits)[i] == true ? str += "1" : str += "0";
    return str;
}

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

void ReallyLongInt::removeLeadingZeros(void){
    while((*digits)[size - 1] == 0){
        if(size == 1)
            break;
        size--;
    }
    vector<bool>* tmp = new vector<bool>(size, false);
    for(int i = 0; i < size; i++)
        (*tmp)[i] = (*digits)[i];
    digits = tmp;
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other){
    swap(other);
    return *this;
}

void ReallyLongInt::swap(ReallyLongInt other){
    vector<bool>* tmp_v = this->digits;
    this->digits = other.digits;
    other.digits = tmp_v;
    
    bool tmp_b = this->isNeg;
    this->isNeg = other.isNeg;
    other.isNeg = tmp_b;
    
    int tmp_s = this->size;
    this->size = other.size;
    other.size = tmp_s;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const{
    ReallyLongInt* result = new ReallyLongInt();
    int tmp_size = other.size < this->size ? this->size + 1 : other.size + 1;
    vector<bool>* tmp_vector = new vector<bool>(tmp_size, false);
    bool inc = false;
    for(int i = 0; i < tmp_size; i++){
        if(((*digits)[i] == 1 and (*other.digits)[i] == 1 and inc == 1) or
           ((*digits)[i] == 1 and (*other.digits)[i] == 0 and inc == 0) or
           ((*digits)[i] == 0 and (*other.digits)[i] == 1 and inc == 0) or
           ((*digits)[i] == 0 and (*other.digits)[i] == 0 and inc == 1))
            (*tmp_vector)[i] = 1;
        else
            (*tmp_vector)[i] = 0;
        if(((*digits)[i] == 1 and (*other.digits)[i] == 1 and inc == 1) or
           ((*digits)[i] == 1 and (*other.digits)[i] == 1 and inc == 0) or
           ((*digits)[i] == 1 and (*other.digits)[i] == 0 and inc == 1) or
           ((*digits)[i] == 0 and (*other.digits)[i] == 1 and inc == 1))
            inc = 1;
        else
            inc = 0;
    }
    result->digits = tmp_vector;
    result->size = tmp_size;
    result->isNeg = false;
    result->removeLeadingZeros();
    return *result;
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const{
    if(this->isNeg == 0 and other.isNeg == 0)
        return this->absAdd(other);
    else if(this->isNeg == 1 and other.isNeg == 1){
        ReallyLongInt tmp = this->absAdd(other);
        tmp.flipSign();
        return tmp;
    }
    else if(this->isNeg == 0 and other.isNeg == 1)
        return this->absSub(other);
    else
        return other.absSub(*this);
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const{
    ReallyLongInt* result = new ReallyLongInt();
    result->isNeg = false;
    vector<bool> larger = *digits;
    vector<bool> smaller = *other.digits;
    if(not this->absGreater(other)){
        smaller = *digits;
        larger = *other.digits;
        result->isNeg = true;
    }
    int tmp_size = other.size < this->size ? this->size: other.size;
    vector<bool>* tmp_vector = new vector<bool>(tmp_size, false);
    bool borrow = false;
    for(int i = 0; i < tmp_size; i++){
        if((smaller[i] == 1 and larger[i] == 1 and borrow == 1) or
           (smaller[i] == 1 and larger[i] == 0 and borrow == 0) or
           (smaller[i] == 0 and larger[i] == 1 and borrow == 0) or
           (smaller[i] == 0 and larger[i] == 0 and borrow == 1))
            (*tmp_vector)[i] = 1;
        else
            (*tmp_vector)[i] = 0;
        if((smaller[i] == 1 and larger[i] == 1 and borrow == 1) or
           (smaller[i] == 1 and larger[i] == 0 and borrow == 0) or
           (smaller[i] == 0 and larger[i] == 0 and borrow == 1) or
           (smaller[i] == 1 and larger[i] == 0 and borrow == 1))
            borrow = 1;
        else
            borrow = 0;
    }
    result->digits = tmp_vector;
    result->size = tmp_size;
    result->removeLeadingZeros();
    return *result;
}
ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
    if(this->isNeg == 0 and other.isNeg == 0)
        return this->absSub(other);
    else if(this->isNeg == 1 and other.isNeg == 1){
        ReallyLongInt tmp = this->absSub(other);
        tmp.flipSign();
        return tmp;
    }
    else if(this->isNeg == 0 and other.isNeg == 1)
        return this->absAdd(other);
    else{
        ReallyLongInt tmp = other.absAdd(*this);
        tmp.flipSign();
        return tmp;
    }
}

void ReallyLongInt::flipSign(){
    this->isNeg == 0 ? this->isNeg = 1 : this->isNeg = 0;
}

ReallyLongInt ReallyLongInt::operator-() const{
    ReallyLongInt tmp(*this);
    tmp.flipSign();
    return tmp;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt &other) const{
    ReallyLongInt result;
    for(int i = 0; i < other.size; i++){
        vector<bool>* tmp = new vector<bool>(this->size + i, false);
        for(int j = 0; j < this->size + i; j++){
            (*tmp)[j + i] = ((*digits)[j] == 1 and (*other.digits)[i] == 1) ? 1 : 0;
        }
        ReallyLongInt int_tmp;
        int_tmp.digits = tmp;
        int_tmp.size = this->size + i;
        int_tmp.isNeg = false;
        result = result + int_tmp;
    }
    return result;
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const{
    if((this->isNeg == 1 and  other.isNeg == 1) or (this->isNeg == 0 and  other.isNeg == 0))
        return this->absMult(other);
    ReallyLongInt tmp = this->absMult(other);
    tmp.flipSign();
    return tmp;
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
    remainder = 0;
    long long d = 0;
    ReallyLongInt other_copy(other);
    other.isNeg == 1 ? other_copy.isNeg = 0 : other_copy.isNeg = 0;
    for(int i = 0; i < this->size; i++){
        remainder = remainder * 2;
        int tmp = (*this->digits)[this->size - i - 1];
        remainder = remainder + tmp;
        d = 0;
        while(remainder.greater(other_copy) or remainder.equal(other_copy)){
            remainder = remainder.sub(other_copy);
            d++;
        }
        quotient = quotient + (pow(2,this->size - i - 1) * d);
    }
}

void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
    this->absDiv(other, quotient, remainder);
    if((this->isNeg == 1 and other.isNeg == 1) or (this->isNeg == 0 and other.isNeg == 1))
        remainder.flipSign();
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.sub(y);
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.mult(y);
}


ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y){
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    x.div(y, quotient, remainder);
    return quotient;
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y){
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    x.div(y, quotient, remainder);
    return remainder;
}

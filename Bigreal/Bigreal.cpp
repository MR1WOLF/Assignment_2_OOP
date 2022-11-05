#include <iostream>
#include "Bigreal.h"
#include "BigDecimalIntClass.cpp"

using namespace std;

Bigreal::Bigreal(string realnum){
    point = realnum.find('.');
    realnum.erase(realnum.find('.'), 1);
    integer.setNumber(realnum);
}

Bigreal::Bigreal(double realnum){
    string realnumstr = to_string(realnum);
    point = realnumstr.find('.');
    realnumstr.erase(realnumstr.find('.'), 1);
    integer.setNumber(realnumstr);
}

Bigreal::Bigreal(BigDecimalInt realnum){
    integer = realnum;
}

BigDecimalInt Bigreal::getNumber(){
    return integer;
}

int Bigreal::getPoint(){
    return point;
}

Bigreal Bigreal::operator+ (Bigreal other){
    Bigreal result;
    result.integer = this->integer + other.integer;
    if (this->integer.size() > other.integer.size()){
        result.point = this->point;
    }
    else{
        result.point = other.point;
    }
    if (result.integer.size() > this->integer.size()){
       result.point++;
    }
    return result;
}

Bigreal Bigreal::operator-(Bigreal other){
    Bigreal result;
    if (this->integer.size() > other.integer.size()){
        result.integer = this->integer - other.integer;
        cout << result.integer << endl;
        if (this->integer.size() > other.integer.size()){
            result.point = this->point;
        }
        else{
            result.point = other.point;
        }
        if (result.integer.size() < this->integer.size()){
        result.point--;
        }
    }
    else if (other.integer.size() >= this->integer.size() && other.integer > this->integer){
        result.integer = other.integer - this->integer;
        if (this->integer.size() > other.integer.size()){
            result.point = this->point;
        }
        else{
            result.point = other.point;
        }
        if (result.integer.size() < other.integer.size()){
            result.point--;
        }
        cout << '-';
    }
    else{
        result.integer = this->integer - other.integer;
        if (this->integer.size() > other.integer.size()){
            result.point = this->point;
        }
        else{
            result.point = other.point;
        }
        if (result.integer.size() < this->integer.size()){
            result.point--;
        }
    }
    return result;
}

Bigreal Bigreal::operator= (Bigreal other){
    this->integer = other.integer;
    this->point = other.point;
    return *this;
}

ostream& operator<<(ostream& os, Bigreal realnum){
    string first_part = realnum.integer.getNumber().substr(0, realnum.point);
    BigDecimalInt first_num(first_part);
    string second_part = realnum.integer.getNumber().substr(realnum.point, realnum.integer.size());
    BigDecimalInt second_num(second_part);
    cout << first_num.getNumber() + "." + second_num.getNumber();
    return os;
}


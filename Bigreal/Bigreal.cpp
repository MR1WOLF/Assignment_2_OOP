#include <iostream>
#include "Bigreal.h"
#include "BigDecimalIntClass.cpp"

using namespace std;

void removePoint(string &str1, string &str2){
    int point1 = str1.find(".");
    int point2 = str2.find(".");
    if (point1 != -1){
        str1.erase(point1, 1);
    }
    if (point2 != -1){
        str2.erase(point2, 1);
    }
    
}

int digitsAfterPoint(Bigreal num1, Bigreal num2){
    int point1 = num1.bigreal.find('.');
    int point2 = num2.bigreal.find('.');
    int size1 = num1.bigreal.length() - point1;
    int size2 = num2.bigreal.length() - point2;

    return size1 - size2;
}

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

Bigreal Bigreal::operator+ (Bigreal& other){
    Bigreal result;
    if (this->point == 0 && other.point == 0){
        BigDecimalInt num1(this->bigreal);
        BigDecimalInt num2(other.bigreal);

        result.integer = num1 + num2;
        string temp = result.integer.getNumber();
        result.bigreal = temp;
        return result;
    }
    int digits_after = abs(digitsAfterPoint(*this, other));
    if (this->bigreal.length() > other.bigreal.length() && digits_after > 0){
        for (int i = 0; i < digits_after; i++){
            other.bigreal += "0";
        }
    }
    else if (this->bigreal.length() < other.bigreal.length() && digits_after > 0){
        for (int i = 0; i < digits_after; i++){
            this->bigreal += "0";
        }
    }
    else if (this->bigreal.length() == other.bigreal.length() && digits_after > 0){
        if (digitsAfterPoint(*this, other) < 0){
            for (int i = 0; i < digits_after; i++){
                this->bigreal += "0";
            }
        }
        else{
            for (int i = 0; i < digits_after; i++){
                other.bigreal += "0";
            }
        }
    }

    removePoint(this->bigreal, other.bigreal);
    
    BigDecimalInt num1(this->bigreal);
    BigDecimalInt num2(other.bigreal);

    if (num1.size() > num2.size() && num1.sign() != 0){
        result.integer = num1 + num2;
        result.point = this->point;
    }
    else if (num1.sign() == 0){
        result.integer = num1 + num2;
        result.point = this->point - 1;
    }
    else if(num2.sign() == 0){
        result.integer = num1 + num2;
        result.point = other.point - 1;
    }
    else{
        result.integer = num1 + num2;
        result.point = other.point;
    }


    if (result.integer.size() > num1.size() && num1.size() > num2.size()){
       result.point++;
    }
    else if(result.integer.size() > num2.size() && num2.size() > num1.size()){
        result.point++;
    }
    else if (result.integer.size() > num1.size() && num1.size() == num2.size() && num2.sign()){
        result.point++;
    }
    string temp = result.integer.getNumber();
    temp.insert(temp.begin() + result.point, '.');
    result.bigreal = temp;

    return result;
}

Bigreal Bigreal::operator-(Bigreal& other){
    Bigreal result;

    if (this->point == 0 && other.point == 0){
        BigDecimalInt num1(this->bigreal);
        BigDecimalInt num2(other.bigreal);

        result.integer = num1 - num2;
        string temp = result.integer.getNumber();
        result.bigreal = temp;
        return result;
    }

    int digits_after = abs(digitsAfterPoint(*this, other));
    if (this->bigreal.length() > other.bigreal.length() && digits_after > 0){
        for (int i = 0; i < digits_after; i++){
            other.bigreal += "0";
        }
    }
    else if (this->bigreal.length() < other.bigreal.length() && digits_after > 0){
        for (int i = 0; i < digits_after; i++){
            this->bigreal += "0";
        }
    }
    else if (this->bigreal.length() == other.bigreal.length() && digits_after > 0){
        if (digitsAfterPoint(*this, other) < 0){
            for (int i = 0; i < digits_after; i++){
                this->bigreal += "0";
            }
        }
        else{
            for (int i = 0; i < digits_after; i++){
                other.bigreal += "0";
            }
        }
    }

    removePoint(this->bigreal, other.bigreal);
    
    BigDecimalInt num1(this->bigreal);
    BigDecimalInt num2(other.bigreal);

    if (num1.size() > num2.size()){
        result.integer = num1 - num2;
        if (num1.sign() == 0){
            result.point = this->point - 1;
        }
        else{
            result.point = this->point;
        }
        if (result.integer.size() < num1.size()){
            result.point--;
        }
        if (result.integer.size() > num1.size()){
            result.point++;
        }
        if (num1 > num2 && num1.sign() == 0){
            cout << '-';
        }
        else if (num2 > num1){
            cout << '-';
        }
    }
    else if (num2.size() >= num1.size()){
        result.integer = num1 - num2;
        if (num2.sign() == 0){
            result.point = other.point - 1;
        }
        else{
            result.point = other.point;
        }
        if (result.integer.size() < num2.size()){
            result.point--;
        }
        if (result.integer.size() > num2.size()){
            result.point++;
        }
        if (num1 > num2 && num1.sign() == 0){
            cout << '-';
        }
        else if (num2 > num1){
            cout << '-';
        }
    }
    else{
        result.integer = num1 - num2;
        if (num1.size() > num2.size()){
            result.point = this->point;
        }
        else{
            result.point = other.point;
        }
        if (result.integer.size() < num1.size()){
            result.point--;
        }
    }

    string temp = result.integer.getNumber();
    temp.insert(temp.begin() + result.point, '.');
    result.bigreal = temp;

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


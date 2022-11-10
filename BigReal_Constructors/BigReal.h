//
// Created by DELL.SXS01 on 11/5/2022.
//

#ifndef UNTITLED21_BIGREAL_H
#define UNTITLED21_BIGREAL_H
#include <iostream>
#include <regex>

using namespace std;

class BigReal{
private:
    string str;
    int point;
    char sign;
    BigDecimalInt integer;

public:

    BigReal();
    BigReal(double realnum);
    BigReal(string realnum);
    BigReal(BigDecimalInt bigInteger);
    BigReal (const BigReal& other);
    BigReal (BigReal&& other);
    BigReal& operator= (BigReal& other);
    BigReal& operator= (BigReal&& other);
    Bigreal operator+ (Bigreal& other);
    Bigreal operator- (Bigreal& other);
    bool checkValidInput(string input);
    void print();
    void setSign();
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    BigReal operator= (BigReal anotherReal);
    int size();
    int sign();
    friend istream& operator >> (istream& input, BigReal& b);
};
#endif //UNTITLED21_BIGREAL_H

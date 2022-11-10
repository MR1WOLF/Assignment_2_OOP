#include <iostream>
#include <regex>
#include "BigDecimalIntClass.h"
#include "BigReal.h"
using namespace std;

void BigReal::setSign(){
   if(integer.sign()==0){
       sign='-';
   }
   else{sign='+';}
}
                                            // Empty constructor
BigReal::BigReal(){
    integer.setNumber("0");
    //str="0";
    setSign();
}

                                        // Default constructor
BigReal::BigReal(double realnum){
    string realnumstr= to_string(realnum);
    point = realnumstr.find('.');
    realnumstr.erase(realnumstr.find('.'),1);
    //str=realnum;
    integer.setNumber(realnumstr);
    setSign();
}

BigReal::BigReal(string realnum) {
    if (realnum.empty()) {
        integer.setNumber("0");
       // str="0";
        setSign();
    }
   
bool BigReal :: operator< (BigReal anotherReal)
{
    if (num.Sign()==0)
    {
        if (point >= anotherReal.point &&num > anotherReal.num  )
            return false;
        if (point < anotherReal.point &&num == anotherReal.num  )
            return false ;
        else
            return true;
    }
    else if (num.Sign()==1)
    {
        if (point >= anotherReal.point &&num > anotherReal.num  )
            return false;
        if (point > anotherReal.point &&num == anotherReal.num  )
            return false ;
        else
            return true;

    }
};
bool BigReal :: operator> (BigReal anotherReal)
{
    if (num.Sign()==0)
    {
        if (point >= anotherReal.point &&num > anotherReal.num  )
            return true;
        if (point < anotherReal.point &&num == anotherReal.num  )
            return true ;
        else
            return false;
    }
    else if (num.Sign()==1)
    {
        if (point >= anotherReal.point &&num > anotherReal.num  )
            return true;
        if (point > anotherReal.point &&num == anotherReal.num  )
            return true ;
        else
            return false;
    }
}
bool BigReal::operator==(BigReal anotherReal)
{
    if (point==anotherReal.point&&num==anotherReal.num)
    {
        return true ;
    }
    else
        return false ;

}
 BigReal BigReal :: operator= (BigReal anotherReal)
{
    num=anotherReal.num;
    return anotherReal;
}
int BigReal :: size()
{
    return num.size();
}
int BigReal :: sign()
{
    return num.Sign();
}

istream &operator>>(istream &input, BigReal &b) {
    input  >> b.num1;
    return input;
}

    else {
        if (checkValidInput(realnum)) {
            point = realnum.find('.');
            realnum.erase(realnum.find('.'), 1);
            //str=realnum;
            integer.setNumber(realnum);
            setSign();
        }
        else { cout << "invalid input" << endl; }

    }
}
BigReal::BigReal(BigDecimalInt bigInteger){
    integer=bigInteger;
    point=integer.size();
    setSign();
}

BigReal::BigReal (const BigReal& other){            // copy constructor

    integer=other.integer;
    point=other.point;
    setSign();
}
BigReal:: BigReal (BigReal&& other){
    integer=other.integer;
    point=other.point;
    setSign();
}
                                                    // Assignment operator
BigReal& BigReal :: operator = (BigReal& other)
{
    point = other.point;
    integer = other.integer;
    setSign();
    return *this;
}
BigReal& BigReal :: operator= (BigReal&& other){
    point = other.point;
    integer = other.integer;
    setSign();
    return *this;
}
bool BigReal :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]*[.]?[0-9]*");
    return regex_match(input, validInput);
}

void BigReal::print(){
  cout<< integer<<endl;
  cout<<point<<endl;
  cout<<sign<<endl;
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


int main() {
    BigReal r1("-159.490");
    BigDecimalInt g("1892034");
    BigReal r2(g);

   //r1=r2;
    r1.print();
    r2.print();

    return 0;
}


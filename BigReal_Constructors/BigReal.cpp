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



int main() {
    BigReal r1("-159.490");
    BigDecimalInt g("1892034");
    BigReal r2(g);

   //r1=r2;
    r1.print();
    r2.print();

    return 0;
}


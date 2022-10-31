#include <iostream>
#include <functional>
using namespace std;

double cube (double n) {
    return n * n * n;
}
double second (double d) {
    return d * d - 5 * d - 4;
}
double fun (double d) {
    return d * d - 3 * d - 4;
}

typedef double (*func)(double);

// Class Function --> the abstract class//
class Function
{

public:
    virtual double evaluateAt(double value) = 0;
};

// Class SimpleFunction to print the output of a simple function //
class SimpleFunction :public Function{

private:
    typedef double (*func)(double);
    func f2;

public:

    SimpleFunction(func f);
    double  evaluateAt(double value);
};

SimpleFunction::SimpleFunction(func f){
    f2=f;
}
double SimpleFunction:: evaluateAt(double value){

    return f2(value);
}

// Class CompositionFunction --> composite two functions //
class CompositionFunction:public Function{

private:
    typedef double (*func)(double);
    typedef double(*function)(func);
    func f1,f2;
    double result1,result2;

public:
    CompositionFunction(func f1,func f2);
    double  evaluateAt(double value);

};

CompositionFunction::CompositionFunction(func func1,func func2){
    f1=func1;
    f2=func2;
}

double CompositionFunction:: evaluateAt(double value){

    result1=f2(value);
    result2=f1(result1);
    return result2;

}

// class DerivativeFunction --> calculates the derivative of a function //
class DerivativeFunction{
private:
    func function1;
    double dx,result1,result2,result3;

public:
    DerivativeFunction(func func1, double x);
    double evaluateAt(double value);
};


DerivativeFunction::DerivativeFunction(func func1, double x){
    dx=x;
    function1=func1;
}
double DerivativeFunction:: evaluateAt(double value){
    result1=function1( value + dx);
    result2=  function1(value - dx);
    result3=(result1-result2)/(2*dx);
    return result3;
}



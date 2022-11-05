#include <iostream>
#include "Bigreal.cpp"
#include "BigDecimalIntClass.h"

using namespace std;

int main(){
    Bigreal num1("13.5744");
    Bigreal num2("12.5432");
    Bigreal num3("");
    cout << num1 - num2 << endl;
    return 0;
}
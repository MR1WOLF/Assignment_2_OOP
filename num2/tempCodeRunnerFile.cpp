#include <iostream>
#include "LabelGenerator.h"

using namespace std;

int main(){
    LabelGenerator lg("A", 1);
    cout << lg.nextLabel() << endl;
    return 0;
}
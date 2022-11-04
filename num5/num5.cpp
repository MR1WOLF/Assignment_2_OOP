#include <iostream>
#include <array>
#include <stdlib.h>
#include <algorithm>
#include "Universe.h"



using namespace std;


int main(){
    int num;
    cout << "Enter the number of generations: ";
    cin >> num;
    Universe u(num, true);
    u.run();
    return 0;
}
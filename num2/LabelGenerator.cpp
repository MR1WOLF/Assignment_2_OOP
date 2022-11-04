#include "LabelGenerator.h"
#include <iostream>

using namespace std;

LabelGenerator::LabelGenerator(string prefix,int startPoint = 0){
    this->LabelGenerator::prefix = prefix;
    this->LabelGenerator::startPoint = startPoint;
}

string LabelGenerator::nextLabel(){
    string label = prefix + to_string(startPoint);
    startPoint++;
    return label;
}
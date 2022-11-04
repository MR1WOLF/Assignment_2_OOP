#ifndef LABELGENERATOR_H
#define LABELGENERATOR_H
#include <iostream>

using namespace std;

class LabelGenerator{
    protected:
        string prefix;
        int startPoint;
    public:
        LabelGenerator(string prefix, int startPoint);
        string nextLabel();
};

#endif
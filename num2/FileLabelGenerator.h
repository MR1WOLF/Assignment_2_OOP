#ifndef FILELABELGENERATOR_H
#define FILELABELGENERATOR_H
#include "LabelGenerator.h"
#include <fstream>


class FileLabelGenerator : public LabelGenerator{
    private:
        string fileName;
        string caption;
    public:
        FileLabelGenerator(string prefix, int startPoint, string fileName);
        string nextLabel();
};

#endif
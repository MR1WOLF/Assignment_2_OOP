#include "FileLabelGenerator.h"
#include "LabelGenerator.h"
#include <fstream>
#include <iostream>

using namespace std;

FileLabelGenerator::FileLabelGenerator(string prefix, int startPoint, string fileName) : LabelGenerator(prefix, startPoint){
    if (fileName.find(".txt") != string::npos){
        this->fileName = fileName;
    } else {
        this->fileName = fileName + ".txt";
    }
}


string FileLabelGenerator::nextLabel(){
    ofstream file;
    file.open(fileName, ios::app);
    cout << "What is your caption: ";
    getline(cin, caption);
    string label = LabelGenerator::nextLabel();
    label += " " + caption;
    file << label << endl;
    file.close();
    return label;
}
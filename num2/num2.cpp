#include <iostream>
#include "LabelGenerator.cpp"
#include "FileLabelGenerator.cpp"

using namespace std;

int main(){
    LabelGenerator lg("A", 1);
    FileLabelGenerator flg("Act",5, "Book1");
    string res = "";
    for (int i = 0; i < 4; i++){
        res += flg.nextLabel();
    }

    cout << res << endl;
    return 0;
}
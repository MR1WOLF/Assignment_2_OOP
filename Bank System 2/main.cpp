#include <iostream>
#include "includes/Bankingapplication.cpp"


using namespace std;

int main(){
    Bankingapplication app;
    char cond = 'y';
    while (cond != 'n'){
        app.run();
        cout << "Do you want to continue (y/n)=========>";
        cin >> cond;
    }

    // Client c1("Ahmed", "Cairo", "01000000000", new Bankaccount("123",1000));
    // Client c2("Mohamed", "Alex", "01000000001", new SavingsBankaccount("256",2000));

    // cout << c2.getAccountID() << endl;
    // cout << c1.getAccountID() << endl;
    return 0;
}
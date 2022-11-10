#include "SavingsBankaccount.h"
#include <iostream>

using namespace std;

SavingsBankaccount::SavingsBankaccount(string ID, double balance) : Bankaccount(ID, balance){
    minimumbalance = 1000;
    try{
        if (balance < minimumbalance){
            throw balance;
        }
    }
    catch(double balance){
        cout << "Your balance is less than the minimum balance" << "minimum balance :" << minimumbalance << "Your balance is :" << balance << endl;
    }
}

void SavingsBankaccount::withdraw(double amount){
    try{
        if (amount > getBalance()){
            throw amount;
        }
        else{
            Bankaccount::withdraw(amount);
        }
    }
    catch(double amount){
        cout << "Your balance is less than the amount you want to withdraw" << " Your balance is: " << getBalance() << " Amount you want to withdraw: " << amount << endl;
    }
}

void SavingsBankaccount::deposite(double amount){
    try{
        if (amount < 100){
            throw amount;
        }
        else{
            Bankaccount::deposite(amount);
        }
    }
    catch(double amount){
        cout << "You can't deposite less than 100" << "Amount you want to deposite :" << amount << endl;
    }
}
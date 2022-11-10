#ifndef BANDACCOUNT_H
#define BANDACCOUNT_H
#include <iostream>

using namespace std;

class Bankaccount{
    private:
        string ID;
        double balance;
    public:
        Bankaccount();
        Bankaccount(string ID, double balance);
        void setID(string ID);
        void setBalance(double balance);
        string getID();
        double getBalance();
        virtual void withdraw(double amount);
        void deposite(double amount);
};


#endif
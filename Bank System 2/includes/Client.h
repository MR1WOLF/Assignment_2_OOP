#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "SavingsBankaccount.cpp"


using namespace std;

class Client{
    private:
        string name;
        string address;
        string phone;
        Bankaccount *account = NULL;
        SavingsBankaccount *saveaccount = NULL;
    public:
        Client();
        Client(string name, string address, string phone, Bankaccount *account);
        Client(string name, string address, string phone, SavingsBankaccount *saveaccount);
        string getAccountID();
        string getSaveAccountID();
        Bankaccount getAccount();
        void withdraw(double amount);
        void deposite(double amount);
        SavingsBankaccount getSaveAccount();
        void display();
        void displaySave();
        void transfer(double amount, Client *client);
};

#endif

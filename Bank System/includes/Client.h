#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "Bankaccount.h"
#include "SavingsBankaccount.h"

using namespace std;

class Client{
    protected:
        string name;
        string address;
        string phone;
        Bankaccount *account;
    public:
        Client();
        Client(string name, string address, string phone, Bankaccount *account);
        Client(string name, string address, string phone, SavingsBankaccount *account);
        ~Client(){
            delete account;
        }
        string getAccountID();
        void display();
        void transfer(double amount, Client *client);
};


#endif
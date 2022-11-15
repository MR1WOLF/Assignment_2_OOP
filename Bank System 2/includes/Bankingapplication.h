#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H
#include <iostream>
#include "Client.cpp"
#include <array>

using namespace std;

class Bankingapplication{
    private:
        static array<Client*, 100> clients;
        static int clientcount;
    public:
        void addClient(string name, string address, string phone, Bankaccount *account);
        void addClient(string name, string address, string phone, SavingsBankaccount *saveaccount);
        void displayClient(string accountID);
        void transfer(string accountID, double amount, string accountID2);
        void displayAll();
        void run();
        int getClientcount(){
            return clientcount;
        }
};


#endif
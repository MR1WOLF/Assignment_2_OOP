#include "Bankaccount.h"
#include <iostream>

using namespace std;

Bankaccount::Bankaccount(){
    ID = "0";
    balance = 0.0;
}
Bankaccount::Bankaccount(string ID, double balance){
    this->ID = ID;
    this->balance = balance;
}

void Bankaccount::setID(string ID)
{
    this->ID = ID;
}

void Bankaccount::setBalance(double balance)
{
    this->balance = balance;
}

string Bankaccount::getID()
{
    return ID;
}

double Bankaccount::getBalance()
{
    return balance;
}

void Bankaccount::withdraw(double amount)
{
        balance -= amount;
}
void Bankaccount::deposite(double amount)
{
        balance += amount;
}
#include "Client.h"

using namespace std;


// Client::Client(){
//     name = "";
//     address = "";
//     phone = "";
//     account = NULL;
//     saveaccount = NULL;
// }
Client::Client(string name, string address, string phone, Bankaccount* account){
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->account = account;
}
Client::Client(string name, string address, string phone, SavingsBankaccount* account){
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->saveaccount = account;
}

void Client::display(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Account: " << account->getID() << endl;
    cout << "Balance: " << account->getBalance() << endl;
}

void Client::displaySave(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Account: " << saveaccount->getID() << endl;
    cout << "Balance: " << saveaccount->getBalance() << endl;
}

void Client::transfer(double amount, Client *client){
    try{
        if (amount > account->getBalance()){
            throw amount;
        }
        else{
            account->withdraw(amount);
            client->account->deposite(amount);
        }
    }
    catch(double amount){
        cout << "Your balance is less than the amount you want to transfer" << endl <<" Your balance is: " << endl <<account->getBalance() << " Amount you want to transfer: " << amount << endl;
    }
}

string Client::getAccountID(){
    return account == NULL ? saveaccount->getID() : account->getID();
}



Bankaccount Client::getAccount(){
    return account == NULL ? *saveaccount : *account;
}

string Client::getSaveAccountID(){
    return saveaccount->getID();
}

SavingsBankaccount Client::getSaveAccount(){
    return *saveaccount;
}

void Client::withdraw(double amount){
    account == NULL ? saveaccount->withdraw(amount) : account->withdraw(amount);
}

void Client::deposite(double amount){
    account == NULL ? saveaccount->deposite(amount) : account->deposite(amount);
}
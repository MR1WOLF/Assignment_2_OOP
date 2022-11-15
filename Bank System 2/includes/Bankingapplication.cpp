#include "Bankingapplication.h"
#include <iostream>

using namespace std;

array<Client*, 100> Bankingapplication::clients;
int Bankingapplication::clientcount = 0;

void Bankingapplication::displayClient(string accountID){
    for (int i = 0; i < clientcount; i++){
        if (clients[i]->getAccountID() == accountID){
            if (clients[i]->getAccountID()[0] == '1'){
                clients[i]->display();
            }
            else{
                clients[i]->displaySave();
            }
        }
        
    }
}

void Bankingapplication::displayAll(){
    for (int i = 0; i < clientcount; i++){
        if (clients[i]->getAccountID()[0] == '1'){
            clients[i]->display();
        }
        else{
            clients[i]->displaySave();
        }
        cout << "---------------------------------" << endl;
    }
}

void Bankingapplication::addClient(string name, string address, string phone, Bankaccount *account){
    clients[clientcount] = new Client(name, address, phone, account);
    clientcount++;
}

void Bankingapplication::addClient(string name, string address, string phone, SavingsBankaccount *saveaccount){
    clients[clientcount] = new Client(name, address, phone, saveaccount);
    clientcount++;
}

void Bankingapplication::run(){
    cout << "Welcome to FCAI Banking Application" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Display all accounts" << endl;
    cout << "3.Withdraw money" << endl;
    cout << "4. Deposite money" << endl;

    cout << "Please Enter a choice (integer number)=========>";
    int choice;
    cin >> choice;

    switch(choice){
        case 1:{
            string name, address, phone, ID;
            double balance;
            int account_type;
            cin.ignore();
            cout << "Please Enter Client name========> ";
            getline(cin, name);
            cout << "Please Enter Client address========> ";
            getline(cin, address);
            cout << "Please Enter Client phone========> ";
            cin >> phone;
            cout << "What type of Account do you want (1) Basic (2)Saving Type 1 or 2 ========> ";
            cin >> account_type;
            if (account_type == 1){
                cout << "Please Enter Account ID========> ";
                cin >> ID;
                ID.insert(0, "1");
                cout << "Please Enter Account Balance========> ";
                cin >> balance;
                cout << endl;
                Bankaccount *account = new Bankaccount(ID, balance);
                addClient(name, address, phone, account);
                cout << "Account Created Successfully" << endl;
            }
            else if (account_type == 2){
                cout << "Please Enter Account ID========> ";
                cin >> ID;
                ID.insert(0, "2");
                cout << "Please Enter Account Balance========> ";
                cin >> balance;
                cout << endl;
                SavingsBankaccount *saveaccount = new SavingsBankaccount(ID, balance);
                addClient(name, address, phone, saveaccount);
                cout << "Account Created Successfully" << endl;
            }
            else{
                cout << "Invalid Account Type" << endl;
            }
            break;
        }
        case 2:{
            this->displayAll();
            break;
        }
        case 3:{
            string accountID;
            double amount;
            cout << "Please Enter Account ID========> ";
            cin >> accountID;
            cout << endl;
            cout << "Please Enter Amount========> ";
            cin >> amount;
            cout << endl;
            for (int i = 0; i < clientcount; i++){
                if (clients[i]->getAccountID() == accountID){
                    clients[i]->withdraw(amount);
                    // clients[i]->getAccount().withdraw(amount);
                    // cout << clients[i]->getAccount().getBalance();
                }
                cout << "Withdrawal Completed Successfully" << endl;
            }
            
            break;
        }
        case 4:{
            string accountID;
            double amount;
            cout << "Please Enter Account ID========> ";
            cin >> accountID;
            cout << endl;
            cout << "Please Enter Amount========> ";
            cin >> amount;
            cout << endl;
            for (int i = 0; i < clientcount; i++){
                if (clients[i]->getAccountID() == accountID){
                    clients[i]->deposite(amount);
                    // clients[i]->getAccount().deposite(amount);
                }
            }
            cout << "Deposite Completed Successfully" << endl;
            break;
        }
    }
    cout << "---------------------------------" << endl;
}
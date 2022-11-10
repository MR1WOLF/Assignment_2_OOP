#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H
#include "Bankaccount.h"

class SavingsBankaccount : public Bankaccount{
    private:
        double minimumbalance;
    public:
        SavingsBankaccount(string ID, double balance);
        void withdraw(double amount);
        void deposite(double amount);

};

#endif
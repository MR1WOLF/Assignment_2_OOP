#ifndef SAVINGBANKACCOUNT_h
#define SAVINGBANKACCOUNT_h
#include "Bankaccount.cpp"

class SavingsBankaccount : public Bankaccount{
    private:
        double minimumbalance;
    public:
        SavingsBankaccount(string ID, double balnance);
        void withdraw(double amount);
        void deposite(double amount);
};

#endif
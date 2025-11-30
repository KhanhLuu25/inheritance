#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
private:
    double interestRate = 0.0;
    double minBalance = 0.0;
    double serviceCharges = 0.0;
public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void setMinBalance(double minBalance);
    double getMinBalance() const;
    void setServiceCharges(double serviceCharges);
    double getServiceCharges() const;
    void postInterest() const;
    bool verifyBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;
    checkingAccount();
    checkingAccount(int accountNumber, double balance, double interestRate,
                    double minBalance, double serviceCharges);
};




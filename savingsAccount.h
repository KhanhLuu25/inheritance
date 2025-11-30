#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "bankAccount.h"

// savingsAccount inherits from bankAccount and adds
// its own interest rate and rules for withdrawals.
class savingsAccount : public bankAccount {
private:
    double interestRate{}; // Annual interest rate in percent

public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;

    // Add one day's worth of interest directly to the balance
    void postInterest();

    // Override withdraw to prevent the balance from going negative
    void withdraw(double amount);

    // Print base info plus the savings-specific interest rate
    void print() const;

    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);
};

#endif // SAVINGSACCOUNT_H

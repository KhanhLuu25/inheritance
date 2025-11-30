#include "savingsAccount.h"
#include <iomanip>
#include <iostream>

void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

double savingsAccount::getInterestRate() const {
    return interestRate;
}

void savingsAccount::postInterest() {
    if (interestRate <= 0.0) {
        std::cout << "No interest applied (rate is zero or negative)." << std::endl;
        return;
    }

    double dailyRate = interestRate / 100.0 / 365.0;
    double interest = getAccountBalance() * dailyRate;
    deposit(interest);

    std::cout << "Daily interest of " << std::fixed << std::setprecision(2)
              << interest << " USD has been added to your savings account." << std::endl;
    std::cout << "New balance: " << getAccountBalance() << " USD" << std::endl;
}

void savingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
        return;
    }

    double currentBalance = getAccountBalance();
    if (amount > currentBalance) {
        std::cout << "Insufficient funds in savings account. "
                  << "You tried to withdraw " << amount
                  << " but the current balance is " << currentBalance << "." << std::endl;
        return;
    }

    bankAccount::withdraw(amount);
    std::cout << "Withdrawal successful. New balance: "
              << getAccountBalance() << " USD" << std::endl;
}

void savingsAccount::print() const {
    bankAccount::print();
    std::cout << "Savings Interest Rate %: " << getInterestRate() << std::endl;
}

savingsAccount::savingsAccount() = default;

savingsAccount::savingsAccount(int accountNumber,
                               double balance,
                               double interestRate)
    : bankAccount(accountNumber, balance),
      interestRate(interestRate) {}

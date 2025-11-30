#include "checkingAccount.h"

#include <iomanip>
#include <iostream>

void checkingAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

double checkingAccount::getInterestRate() const {
    return interestRate;
}

void checkingAccount::setMinBalance(double minBalance) {
    this->minBalance = minBalance;
}

double checkingAccount::getMinBalance() const {
    return minBalance;
}

void checkingAccount::setServiceCharges(double serviceCharges) {
    this->serviceCharges = serviceCharges;
}

double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}

void checkingAccount::postInterest() const {
    // Daily interest = current balance * (annualRate / 100 / 365)
    std::cout << "Your daily interest is: "
              << std::fixed << std::setprecision(2)
              << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0)
              << std::endl;
}

bool checkingAccount::verifyBalance() const {
    std::cout << "Your balance is: " << getAccountBalance() << std::endl;
    return getAccountBalance() >= minBalance;
}

void checkingAccount::deposit(double amount) {
    // For now, just use the base-class deposit behavior.
    bankAccount::deposit(amount);
}

void checkingAccount::withdraw(double amount) {
    // Enforce:
    //  - amount must be positive
    //  - cannot withdraw more than current balance
    //  - if amount > 500, apply a percentage service fee

    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
        return;
    }

    double currentBalance = bankAccount::getAccountBalance();

    if (amount > currentBalance) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << currentBalance << std::endl;
        return;
    }

    // Apply service charge if amount is over $500
    if (amount > 500.0) {
        double fee = amount * (serviceCharges / 100.0);
        double total = amount + fee;

        if (total > currentBalance) {
            std::cout << "After including the service charge, there is not enough balance."
                      << std::endl;
            std::cout << "Requested: " << amount
                      << " + fee: " << fee
                      << " > balance: " << currentBalance << std::endl;
            return;
        }

        bankAccount::withdraw(total);
        std::cout << "A service fee of " << fee << " has been applied." << std::endl;
    } else {
        bankAccount::withdraw(amount);
    }

    std::cout << "Your new balance is " << bankAccount::getAccountBalance() << std::endl;
}

void checkingAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
    std::cout << "Min Balance $: " << getMinBalance() << std::endl;
    std::cout << "Service Charges %: " << getServiceCharges() << std::endl;
}

checkingAccount::checkingAccount() = default;

checkingAccount::checkingAccount(int accountNumber,
                                 double balance,
                                 double interestRate,
                                 double minBalance,
                                 double serviceCharges)
    : bankAccount(accountNumber, balance),
      interestRate(interestRate),
      minBalance(minBalance),
      serviceCharges(serviceCharges) {}

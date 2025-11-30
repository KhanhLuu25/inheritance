#include "bankAccount.h"
#include <iostream>

void bankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

int bankAccount::getAccountNumber() const {
    return this->accountNumber;
}

double bankAccount::getAccountBalance() const {
    return this->balance;
}

void bankAccount::deposit(double amount) {
    // Simple deposit: add amount to the balance.
    // Validation (e.g., rejecting negative deposits) can be done by the caller.
    balance += amount; // balance = balance + amount
}

void bankAccount::withdraw(double amount) {
    // Simple withdraw: subtract amount from the balance.
    // Overdraft protection is implemented in derived classes if needed.
    balance -= amount;
}

void bankAccount::print() const {
    std::cout << "Account Number: " << this->accountNumber << std::endl;
    std::cout << "Balance (USD): " << this->balance << std::endl;
}

bankAccount::bankAccount() = default;

bankAccount::bankAccount(int accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}

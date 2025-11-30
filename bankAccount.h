#pragma once

class bankAccount {
private:
    int accountNumber = 0;
    double balance = 0;
public:
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    double getAccountBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;
    bankAccount();
    bankAccount(int accountNumber, double balance);
};
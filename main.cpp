#include <iostream>
#include "checkingAccount.h"

int main() {
    int accountNumber, input;
    double amount, interestRate, minBalance, serviceCharges;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    std::cout << "Enter balance (in USD): ";
    std::cin >> amount;

    std::cout << "Enter interest rate (%): ";
    std::cin >> interestRate;

    std::cout << "Enter min balance (in USD): ";
    std::cin >> minBalance;

    std::cout << "Enter service charges (%): ";
    std::cin >> serviceCharges;

    // Create a checkingAccount object using the values the user entered
    checkingAccount account(accountNumber, amount, interestRate, minBalance, serviceCharges);

    do {
        std::cout << std::endl;
        std::cout << "Which service do you want to use?" << std::endl;
        std::cout << "1 <-- Deposit" << std::endl;
        std::cout << "2 <-- Withdraw" << std::endl;
        std::cout << "3 <-- Print balance status" << std::endl;
        std::cout << "4 <-- Print account details" << std::endl;
        std::cout << "5 <-- Print daily interest" << std::endl;
        std::cout << "0 <-- Exit" << std::endl;
        std::cout << "Selection: ";
        std::cin >> input;

        switch (input) {
            case 0:
                std::cout << "Thank you. Good bye." << std::endl;
                break;

            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                std::cout << "Service charge of " << account.getServiceCharges()
                          << "% applies if the withdrawal amount is more than $500 "
                          << "from the checking account." << std::endl;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                if (account.verifyBalance()) {
                    std::cout << "Your account balance is at or above the minimum balance."
                              << std::endl;
                } else {
                    std::cout << "Your account balance is lower than the minimum balance."
                              << std::endl;
                }
                break;

            case 4:
                account.print();
                break;

            case 5:
                account.postInterest();
                break;

            default:
                std::cout << "Invalid input." << std::endl;
        }
    } while (input != 0);

    return 0;
}

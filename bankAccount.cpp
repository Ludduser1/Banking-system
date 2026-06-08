#include "bankAccount.hpp"
#include <iostream>

bankAccount::bankAccount(int number, std::string name, double initialBalance) {
    accountNumber = number;
    accountName = name;
    balance = initialBalance;
}

void bankAccount::deposit(double amount) {
     balance += amount;
}

void bankAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "No funds" << std::endl;
    }
}

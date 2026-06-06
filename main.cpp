#include <iostream>
#include <string>
#include <vector>

class transaction {
public:
    std::string type;
    double amount;

    transaction(std::string t, double a) {
        type = t;
        amount = a;
    }
};

class bankAccount {
public:
    int accountNumber;
    std::string AccountName;
    double balance;
    std::vector<transaction> history;

    bankAccount (int number, std::string name, double initialDeposit) {
        accountNumber = number;
        AccountName = name;
        balance = initialDeposit;
        history.push_back(transaction("Initial Deposit", initialDeposit));
    }
};

int main() {
    

    return 0;
}
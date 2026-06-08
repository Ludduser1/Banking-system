#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
#include <vector>

struct transaction {
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
    std::string accountName;
    double balance;                   // <-- Måste finnas här!
    std::vector<transaction> history;

    bankAccount(int number, std::string name, double initialBalance);
    
    // DE HÄR TRE RADERNA MÅSTE FINNAS MED:
    void deposit(double amount);
    void withdraw(double amount);
    void showHistory(); 
};

#endif

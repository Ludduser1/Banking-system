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
    std::string accountName;
    double balance;
    std::vector<transaction> history;

    bankAccount (int number, std::string name, double initialDeposit) {
        accountNumber = number;
        accountName = name;
        balance = initialDeposit;
        history.push_back(transaction("Initial Deposit", initialDeposit));
    }
};

int main() {

    std::vector<bankAccount> bank;
    bank.push_back(bankAccount(1001, "person1", 500));
    bank.push_back(bankAccount(1002, "person2", 750));

    int choice = 0;

    do {

    std::cout << "============ BANK SYSTEM ============" << std::endl;
        std::cout << "1. Account Status" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Transaction History" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        //crashsafety
        if (std::cin.fail()) {
            std::cin.clear();
            std::string garbage;
            std::cin >> garbage;
            std::cout << "Invalid input." << std::endl;
            choice = 0;
            continue;
        }
    

    switch (choice) {
        case 1:
            std::cout << "Accounts" << std::endl;
            for (int i = 0; i < bank.size(); i++) {
                std::cout << "Account" << bank[i].accountNumber << std::endl;
                std::cout << "Owner: " << bank[i].accountName << std::endl;
                std::cout << "Balance: " << bank[i].balance << std::endl;

            }
            break;



    }

    }
    

    return 0;
}
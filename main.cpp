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
    bank.push_back(bankAccount(1, "person1", 500));
    bank.push_back(bankAccount(1, "person2", 750));

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

        case 2: {
                std::cout << "--- DEPOSIT ---" << std::endl;
                int accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;

                bool found = false;
                for (int i = 0; i < bank.size(); i++) {
                    if (bank[i].accountNumber == accNum) {
                        found = true;
                        if (amount <= 0) {
                            std::cout << "Invalid amount!" << std::endl;
                        } else {
                            bank[i].balance += amount;
                            bank[i].history.push_back(transaction("Deposit", amount));
                            std::cout << "Success! New balance: $" << bank[i].balance << std::endl;
                        }
                        break;
                    }
                }
                if (!found) std::cout << "Account not found!" << std::endl;
                break;
            }    
        
        case 3: {
                std::cout << "\n--- WITHDRAWAL ---" << std::endl;
                int accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;

                bool found = false;
                for (int i = 0; i < bank.size(); i++) {
                    if (bank[i].accountNumber == accNum) {
                        found = true;
                        if (amount <= 0) {
                            std::cout << "Invalid amount!" << std::endl;
                        } else if (amount > bank[i].balance) {
                            std::cout << "Declined! Insufficient funds." << std::endl;
                        } else {
                            bank[i].balance -= amount;
                            bank[i].history.push_back(transaction("Withdrawal", amount));
                            std::cout << "Success! New balance: $" << bank[i].balance << std::endl;
                        }
                        break;
                    }
                }
                if (!found) std::cout << "Account not found!" << std::endl;
                break;
            }    

            case 4: {
                std::cout << "\n--- TRANSACTION HISTORY ---" << std::endl;
                int accNum;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (int i = 0; i < bank.size(); i++) {
                    if (bank[i].accountNumber == accNum) {
                        found = true;
                        std::cout << "History for " << bank[i].accountName << ":" << std::endl;
                        for (int j = 0; j < bank[i].history.size(); j++) {
                            std::cout << " - " << bank[i].history[j].type << ": $" << bank[i].history[j].amount << std::endl;
                        }
                        break;
                    }
                }
                if (!found) std::cout << "Account not found!" << std::endl;
                break;
            }

            

    return 0;
}
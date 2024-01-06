#include<iostream>
#include<string>
#include<limits>
#include<cstdio>
#include<map>
using namespace std;

class bank {

    private: 
        std::string name;
        std::string address;
        std::string accountType;
        std::map<std::string, std::string> accountTypeMapping = {
            {"1", "Savings"},
            {"2", "Checking"},
            {"3", "Credit"}
        };
        int balance;

    public:
        void openAccount();
        void depositeSum();
        void withdrawSum();
        void displayAccountDetails();
};




void bank ::openAccount () {
    std::cout << "Name: ";
    std::cin >> std::ws;
    std::getline(std::cin, name);

    std::cout << "Address: ";
    std::cin >> std::ws;
    std::getline(std::cin, address);

    std::cout << "Account type: ";
    std::cout << "1. Savings \n";
    std::cout << "2. Checking \n";
    std::cout << "3. Credit \n";

    while(true) {
        std::cout << "Select account type: ";
        std::cin >> accountType;

        if (accountTypeMapping.find(accountType) != accountTypeMapping.end()) {
            accountType += accountTypeMapping[accountType];
            break;
        } else {
            std::cout << "Invalid choice. Please enter a valid number. \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }


    std::cout << "Balance: ";
    std::cin >> balance;

    std::cout << "Account created. \n ";
}


void bank::depositeSum () {
    int temp;

    std::cout << "Deposit: enter amount: ";
    std::cin >> temp;
    balance += temp;
    std::cout << "Balance: \t" << balance;
}


void bank::withdrawSum () {
    float temp;

    std::cout << "Withdraw: enter amount: ";
    std::cin >> temp;
    if (temp > balance) {
        std::cout << "404. Not enough money in your account.";
    }

    balance -= temp;
    std::cout << "Balance: \t" << balance;
}

void bank::displayAccountDetails () {
    std::cout << "Name: \t" << name << std::endl;
    std::cout << "Address: \t" << address << "\n";
    std::cout << "Account type: \t" << accountType << "\n";
    std::cout << "Current balance: \t" << balance << "\n";
}




int main() {
    int choice;
    bank bankObject;

        std::cout << "1. Open account \n";
        std::cout << "2. Deposite \n";
        std::cout << "3. Withdraw \n";
        std::cout << "4. Account Details \n";
        std::cout << "5. Exit \n";

        std::cin >> choice;
        
        switch (choice) {
        case 1:  
            bankObject.openAccount();
            bankObject.displayAccountDetails();
            break;
        case 2:
            bankObject.depositeSum();
            bankObject.displayAccountDetails();
            break;
        case 3:
            bankObject.withdrawSum();
            bankObject.displayAccountDetails();
            break;
        case 4:
            bankObject.displayAccountDetails();
            break;
        case 5:
            exit(1);
            break;
        default:
            exit(1);
            break;
        }

    
    return 0;
}
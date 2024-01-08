#include "bank_logic/bank.hpp"
#include "bank_logic/bank.cpp"
#include "open_account/openAccount.hpp"
#include "open_account/openAccount.cpp"

#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


void displayMenu() {
    std::cout << "Internal Banking System" << std::endl;
    std::cout << "Please select an option: " << std::endl;

    std::cout << "1. Open Account" << std::endl;
    std::cout << "2. Deposit Amount" << std::endl;
    std::cout << "3. Withdraw Amount" << std::endl;
    std::cout << "4. Check Balance" << std::endl;
    std::cout << "5. Update Records" << std::endl;
    std::cout << "6. Delete Account" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

void showChanges(const std::string & prompt) {
    clearInputBuffer();
    clearScreen();
    std::cout << prompt << std::endl;
}

void returnMenu () {
    std::cout << "\nPress Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    clearScreen();
    displayMenu();
}


int main(int argc, char * argv[]) {
    int key;
    displayMenu();
    Bank newAccount;

    do {
        std::cin >> key;

        if (key == 1) {
            clearInputBuffer();

            std::string firstName = getOpenAccountInput("First name: ");
            std::string lastName = getOpenAccountInput("Last name: ");
            std::string address = getOpenAccountInput("Address: ");
            std::string phone = getOpenAccountInput("Phone number: ");
            double balance = getOpenAccountInputBalance("Balance: ");

            newAccount = Bank(firstName, lastName, address, phone, balance);

            std::cout << std::endl;
            clearScreen();
            newAccount.displayInfo();

            
            returnMenu();
        } else if (key == 2) {
            clearInputBuffer();

            newAccount.addToDeposit("Add amount: ");
            showChanges("Amount added");
            newAccount.displayInfo();

            returnMenu();
        } else if (key == 3) {
            clearInputBuffer();

            newAccount.withdrawDeposit("Withdraw amount: ");
            showChanges("Amount withdrawn");
            newAccount.displayInfo();

            returnMenu();
        } else if (key == 4) {
            clearInputBuffer();
            clearScreen();
            newAccount.displayBalance();
            returnMenu();
        } else if (key == 5) {
            clearInputBuffer();
        }
    } while (key != 7);

    
    return 0;
}
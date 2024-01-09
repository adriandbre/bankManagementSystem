#include "bank.hpp"
#include <iostream>
#include <limits>

Bank::Bank() {};

Bank::Bank(std::string first, std::string last, std::string address, std::string phone, double balance) : 
            p_firstName(first),
            p_lastName(last),
            p_address(address),
            p_phoneNumber(phone),
            p_balance(balance) // initializer list 
            {}

void Bank::displayInfo() const {
    std::cout << "Name: " << p_firstName << " " << p_lastName << std::endl;
    std::cout << "Address: " << p_address << std::endl;
    std::cout << "Phone Number: " << p_phoneNumber << std::endl;
    std::cout << "Balance: " << p_balance << std::endl;
}

void Bank::displayBalance() const {
    std::cout << "Current balance: " << p_balance;
}

void Bank::addToDeposit(const std::string & prompt) {
    double amountToAdd;

    while (true) {
        std::cout << prompt;

        if (std::cin >> amountToAdd) {
            p_balance += amountToAdd;
            std::cout << "Amount added successfully." << std::endl;
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
        }
    }
}

void Bank::withdrawDeposit(const std::string & prompt) {
    double amountToWithdraw;

    while (true) {
        std::cout << prompt;

        if (std::cin >> amountToWithdraw) {
            if (amountToWithdraw > p_balance) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Insufficient funds. Please enter a valid number." << std::endl;    
            } else {
                p_balance -= amountToWithdraw;
                std::cout << "Amount withdrawn successfully." << std::endl;
                break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
        }
    }
}

void Bank::updateFirstName(std::string newValue) {
    p_firstName = newValue;
}

std::string Bank::getFirstName() {
    return p_firstName;
}
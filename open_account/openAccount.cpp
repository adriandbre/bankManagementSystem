#include "openAccount.hpp"
#include <iostream>
#include <limits>
#include <sstream>

std::string getOpenAccountInput(const std::string & prompt) {

    std::string userInput;

    std::cout << prompt;
    std::getline(std::cin, userInput);


    return userInput;
}

double getOpenAccountInputBalance(const std::string & prompt) {
    std::string userInput;
    double resault;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, userInput);

        std::istringstream iss(userInput);

        if (iss >> resault) {
            break;
        } else {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
        }
    }

    return resault;   
}
#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>

class Bank {
    private:
        std::string p_firstName;
        std::string p_lastName;
        std::string p_address;
        std::string p_phoneNumber;
        double p_balance;


    public:
        Bank();

        Bank(std::string first, std::string last, std::string address, std::string phone, double balance);

        void displayInfo() const;
        void displayBalance() const;
        void addToDeposit(const std::string & prompt);
        void withdrawDeposit(const std::string & prompt);
        void updateFirstName(std::string);

        std::string getFirstName();
};

#endif // BANK_HPP
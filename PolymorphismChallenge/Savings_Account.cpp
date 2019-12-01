#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

bool Savings_Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Savings_Account::deposit(double amount) {
    
    if (amount < 0) 
        return false;
    else {
        amount += amount * (int_rate/100);
        balance += amount;
        return true;
    }
}


void Savings_Account::print(std::ostream &os) const {
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}
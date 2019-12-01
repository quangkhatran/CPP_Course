#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}
bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
   
}

void Checking_Account::print(std::ostream &os) const {
    os << "[Checking_Account: " << name << ": " << balance  << "]";
}




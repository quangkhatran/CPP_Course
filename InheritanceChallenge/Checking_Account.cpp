#include "Checking_Account.h"

Checking_Account::Checking_Account()
{
}

Checking_Account::~Checking_Account()
{
}

bool Checking_Account::withdraw(double amount) {
    if (balance - amount - withdrawal_fee >=0) {
        balance -= (amount + withdrawal_fee);
        return true;
    } else
        return false;
}


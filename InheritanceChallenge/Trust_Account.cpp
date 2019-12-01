#include "Trust_Account.h"

Trust_Account(std::string name, double balance, double int_rate, double bonus_threshold, double bonus_amount
                            int max_withdrawal_per_year, double max_percent_withdrawal_each_time):
    Savings_Account(name, balance, int_rate), 
    bonus_threshold{ bonus_threshold }, 
    bonus_amount { bonus_amount },
    max_withdrawal_per_year{max_withdrawal_per_year}, 
    max_percent_withdrawal_each_time{max_percent_withdrawal_each_time},
    current_num_withdrawals{0}
{
}

Trust_Account::~Trust_Account()
{
}

bool Trust_Account::deposit(double amount)
{
        if( amount > bonus_threshold ){
            amount += bonus_amount;
        }
        return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
        if( current_num_withdrawals >= max_withdrawal_per_year ) {
            std::cout << "Withdrawal failed because you have reached the maxinum number of withdrawals per year" << std::endl;
            return false;
        }
        if( amount >= (max_percent_withdrawal_each_time*balance/100) ) {
            cout << "Withdrawal failed because the withdrawal amount has exceeded the allowance: " <<  max_percent_withdrawal_each_time*balance/100 << "$" << std::endl;
            return false;
        }
        return Account::withdraw(amount);
}



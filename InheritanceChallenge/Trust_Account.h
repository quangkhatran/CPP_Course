#ifndef _TRUST_ACCOUNT_H
#define _TRUST_ACCOUNT_H
#include "Savings_Account.h"

class Trust_Account: public Savings_Account
{
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_bonus_threshold = 5000.0;
    static constexpr double def_bonus_amount = 50.0;
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int def_max_withdrawal_per_year = 3;
    static constexpr double def_max_percent_withdrawal_each_time = 20;
    
protected: 
    double bonus_threshold;
    double bonus_amount;
    double max_withdrawal_per_year;
    double max_percent_withdrawal_each_time;
    int current_num_withdrawals;
    
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate,
double bonus_threshold = def_bonus_threshold, double bonus_amount = def_bonus_amount,
int max_withdrawal_per_year = def_max_withdrawal_per_year, double max_percent_withdrawal_each_time = def_max_percent_withdrawal_each_time );
    ~Trust_Account();
    bool withdraw(double amount);
    bool deposit(double amount); 
};

#endif // _TRUST_ACCOUNT_H

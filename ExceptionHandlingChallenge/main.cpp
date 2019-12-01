#include <iostream>
#include <memory>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

int main(){
    try{
        std::unique_ptr<Savings_Account> s_ptr = std::make_unique<Savings_Account>("TQK", 1000.0, 10.0 );
        std::cout << *s_ptr << std::endl;
        std::unique_ptr<Checking_Account> c_ptr = std::make_unique<Checking_Account>("TDCN", 1000.0 );
        std::cout << *c_ptr << std::endl;
        std::unique_ptr<Trust_Account> t_ptr = std::make_unique<Trust_Account>("TDON", 1000.0, 10.0 );
        std::cout << *t_ptr << std::endl;
        s_ptr -> withdraw(400);
        std::cout << *s_ptr << std::endl;
        s_ptr -> withdraw(900);
        std::cout << *s_ptr << std::endl;
    }
    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }
    catch(const InsufficientFundsException &ex){
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

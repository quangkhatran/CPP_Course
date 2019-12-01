#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
    
    // Savings_Accounts
    Account *p1 = new Savings_Account{"Superman"};
    Account *p2 = new Savings_Account{"Batman", 2000};
    Account *p3 = new Savings_Account{"Wonderwoman", 5000, 5.0};
    vector<Account *> saving_accounts {p1,p2,p3};
    display(saving_accounts);
    deposit(saving_accounts, 1000);
    withdraw(saving_accounts, 2000);
    delete p1;
    delete p2;
    delete p3;
    
    
    // Checking_Accounts
    Account *p4= new Checking_Account {"Kirk"};
    Account *p5 = new Checking_Account {"Spock", 2000}; 
    Account *p6 = new Checking_Account {"Bones", 5000};
    vector<Account *> checking_accounts {p4,p5,p6};
    display(checking_accounts);
    deposit(checking_accounts, 1000);
    withdraw(checking_accounts, 2000);
    delete p4;
    delete p5;
    delete p6;
    
    Account *p7= new Trust_Account {"Athos", 10000, 5.0};
    Account *p8 = new Trust_Account {"Porthos", 20000, 4.0};
    Account *p9 = new Trust_Account {"Aramis", 30000};
    vector<Account *> trust_accounts {p7,p8,p9};
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
        
    delete p7;
    delete p8;
    delete p9;
/*   

    // Trust
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
*/    

    
    return 0;
}

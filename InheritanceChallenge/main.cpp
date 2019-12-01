#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


using namespace std;

int main(){
    Savings_Account savings_account { "TQK", 10000.0, 10};
    savings_account.deposit(1000);
    cout << savings_account << endl;
    
    Checking_Account checking_account { "TDPN", 1001.5 };
    checking_account.withdraw(100);
    cout << checking_account << endl;
    
    Trust_Account trust_account1 { "TDCN", 100000.0, 10 };
    trust_account1.withdraw(1000.0);
    trust_account1.withdraw(1000.0);
    trust_account1.withdraw(1000.0);
    trust_account1.withdraw(1000.0);
    cout << trust_account1 << endl;
    
    Trust_Account trust_account2 { "DTHN", 100000.0, 10 };
    trust_account2.withdraw(1000.0);
    trust_account2.withdraw(21000.0);
    trust_account2.withdraw(1000.0);
    trust_account2.withdraw(1000.0);
    cout << trust_account2 << endl;
    
    Trust_Account trust_account3 { "TDON", 1000.0, 10 };
    trust_account3.deposit(5000);
    cout << trust_account3 << endl;
    
    return 0;
}

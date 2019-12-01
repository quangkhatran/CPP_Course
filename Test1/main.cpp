#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout << "Enter the total number of cents" << endl;
    int total_cents{};
    cin >> total_cents;
    
    int dollar {};
    int quarter {};
    int dime {};
    int nickel {};
    int penny {};
    
    const int dollar_to_cent = 100;
    const int quarter_to_cent = 25;
    const int dime_to_cent = 10;
    const int nickel_to_cent = 5;
    const int penny_to_cent = 1;
    dollar = total_cents / dollar_to_cent;
    
    int remaining_cents {};
    
    remaining_cents = total_cents - dollar * dollar_to_cent;
    quarter = remaining_cents / quarter_to_cent;
    
    remaining_cents = remaining_cents - quarter * quarter_to_cent;
    dime = remaining_cents / dime_to_cent;
    
    remaining_cents = remaining_cents - dime * dime_to_cent;
    nickel = remaining_cents / nickel_to_cent;
    
    remaining_cents = remaining_cents - nickel * nickel_to_cent;
    penny = remaining_cents / penny_to_cent;
    
    cout << "Dollars: " << dollar << endl;
    cout << "Quarters: " << quarter << endl;
    cout << "Dimes: " << dime << endl;
    cout << "Nickels: " << nickel << endl;
    cout << "Pennies: " << penny << endl;
    
    
    return 0;
}

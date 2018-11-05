/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calcula- tions, assume that every month has 30 days. Checking accounts yield interest of 3 percent monthly on balances over $1,000. Savings accounts yield interest of 6 per- cent on the entire balance. Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
 */

#include "savings.hpp"

Savings::Savings() : Account(){
    name = "";
    balance = 0.0;
    days = 0;
    days_no_interest = 0;
}
Savings::Savings(double initial) : Account(initial){
    name = "";
    balance = initial;
    days = 0;
    days_no_interest = 0;
}
Savings::Savings(double initial, std::string n) : Account(n, initial){
    name = n;
    balance = initial;
    days = 0;
}
void Savings::set_name(std::string n){
    name = n;
}
void Savings::withdraw(double w){
    balance -= w;
}
void Savings::deposit(double d){
    balance += d;
}
void Savings::add_days(int d){
    days += d;
}
void Savings::daily_interest(){
    int months = days_no_interest/30;
    if (months == 0){
        return;
    }
    int x = pow(balance*(1+SAVINGS::interest), months);
    balance = x;
    days_no_interest -= (days_no_interest/30)*30;
}
double Savings::get_balance() const{
    return balance;
}
void Savings::display_fields() const{
    std::cout << "Savings Balance = $" << balance << std::endl;
}

/*
private:
std::string name;
double balance;
int days;
*/

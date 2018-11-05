/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calcula- tions, assume that every month has 30 days. Checking accounts yield interest of 3 percent monthly on balances over $1,000. Savings accounts yield interest of 6 per- cent on the entire balance. Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
 */

#include "checkings.hpp"

Checkings::Checkings() : Account(){
    name = "";
    balance = 0.0;
    days = 0;
    days_no_interest = 0;
}
Checkings::Checkings(double initial) : Account(initial) {
    name = "";
    balance = initial;
    days = 0;
    days_no_interest = 0;
}
Checkings::Checkings(double initial, std::string n) : Account(n, initial) {
    name = n;
    balance = initial;
    days = 0;
    days_no_interest = 0;
}
void Checkings::set_name(std::string n){
    name = n;
}
void Checkings::withdraw(double w){
    balance -= w;
}
void Checkings::deposit(double d){
    balance += d;
}
void Checkings::add_days(int d){
    days += d;
}
void Checkings::daily_interest(){
    if (balance >= 1000){
        int months = days_no_interest/30;
        if (months == 0){
            return;
        }
        double x = pow((1+CHECKINGS::interest)*balance, months);
        balance = x;
        days_no_interest -= (days_no_interest/30)*30;
    }
}
double Checkings::get_balance() const{
    return balance;
}
void Checkings::display_fields() const{
    std::cout << "Checkings Balance = $" << balance << std::endl;
}

/*
private:
double balance;
std::string name;
int days;
int days_no_interest;
*/

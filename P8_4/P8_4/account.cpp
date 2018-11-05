/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking.
 In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calcula- tions, assume that every month has 30 days.
 Checking accounts yield interest of 3 percent monthly on balances over $1,000.
 Savings accounts yield interest of 6 percent on the entire balance.
 Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
 */

#include "account.hpp"

Account::Account(){
    name = "";
    balance = 0.0;
    interest = 0.05; // default interest rate
    days = 0;
}
Account::Account(double initial_balance){
    name = "";
    balance = initial_balance;
    interest = 0.05; // default interest rate
    days = 0;
}
Account::Account(std::string n, double initial_balance){
    name = n;
    balance = initial_balance;
    interest = 0.05; // default interest rate
    days = 0;
}
void Account::withdraw(double w){
    balance -= w;
}
void Account::deposit(double d){
    balance += d;
}
void Account::set_interest(double i){
    interest = i;
}
void Account::set_name(std::string n){
    name = n;
}
void Account::daily_interest(){
    double total = pow(((1+interest)*balance), 1);
    balance = total;
    days_no_interest -= 1;
}
void Account::daily_interest(int num_of_days){
    double total = pow(((1+interest)*balance), num_of_days);
    balance = total;
    days += num_of_days;
    days_no_interest -= num_of_days;
}
void Account::add_days(int d){
    if (d > 1){
        days += 1;
    } else { days++; }
}
int Account::get_days() const{
    return days;
}
int Account::get_days_no_interest() const{
    return days_no_interest;
}
double Account::get_balance() const{
    return balance;
}
void Account::display_fields() const{
    std::cout << "Account Balance = $" << balance << std::endl;
}
/*
private:
    std::string name;
    double balance;
    double interest;
    int days;
*/

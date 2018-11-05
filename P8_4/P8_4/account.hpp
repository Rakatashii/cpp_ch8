/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calculations, assume that every month has 30 days. Checking accounts yield interest of 3 percent monthly on balances over $1,000. Savings accounts yield interest of 6 per- cent on the entire balance. Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
 */

#ifndef account_hpp
#define account_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

class Account{
public:
    Account();
    Account(double initial_balance);
    Account(std::string n, double initial_balance);
    virtual void withdraw(double w);
    virtual void deposit(double d);
    
    virtual void set_name(std::string n);
    
    virtual void set_interest(double i);
    virtual void daily_interest();
    virtual void daily_interest(int num_of_days);
    
    virtual void add_days(int d = 1);
    virtual int get_days() const;
    virtual int get_days_no_interest() const;
    virtual double get_balance() const;
    virtual void display_fields() const;
    
    virtual bool type_account() const {return true;};
    virtual bool type_savings() const {return false;};
    virtual bool type_checkings() const {return false;};
private:
    std::string name;
    double balance;
    double interest;
    int days;
    int days_no_interest;
};

#endif /* account_hpp */

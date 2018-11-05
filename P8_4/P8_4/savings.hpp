/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calculations, assume that every month has 30 days. Checking accounts yield interest of 3 percent monthly on balances over $1,000. Savings accounts yield interest of 6 percent on the entire balance. Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
 */

#ifndef savings_hpp
#define savings_hpp

#include <stdio.h>

#include "account.hpp"

namespace SAVINGS{
    const double interest = 0.06;
}

class Savings : public Account{
public:
    Savings();
    Savings(double initial);
    Savings(double initial, std::string n);
    
    virtual void set_name(std::string n);
    
    virtual void withdraw(double w);
    virtual void deposit(double d);
    
    virtual void add_days(int d = 1);
    virtual void daily_interest();
    
    virtual int get_days() const {return days;};
    virtual int get_days_no_interest() const {return days_no_interest;};
    
    virtual double get_balance() const;
    virtual void display_fields() const;
    
    virtual bool type_account() const {return false;};
    virtual bool type_savings() const {return true;};
    virtual bool type_checkings() const {return false;};
private:
    double balance;
    std::string name;
    int days;
    int days_no_interest;
    int interest;
};

#endif /* savings_hpp */

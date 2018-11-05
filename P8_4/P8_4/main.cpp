/*
 Exercise P8.4.
 Implement a base class Account and derived classes Savings and Checking. In the base class, supply member functions deposit and withdraw. Provide a function daily_interest that computes and adds the daily interest. For calculations, assume that every month has 30 days. Checking accounts yield interest of 3 percent monthly on balances over $1,000. Savings accounts yield interest of 6 percent on the entire balance. Write a driver program that makes a month’s worth of deposits and withdrawals and calculates the interest every day.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "account.hpp"
#include "checkings.hpp"
#include "savings.hpp"

using namespace std;

void print_accounts_simple(vector<Account*> v, int num_accounts, int num_days);
void print_accounts_detailed(vector<Account*> v, int num_accounts, int num_days);

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int number_of_accounts = rand()%12+1;
    double b;
    vector<Account*> accounts;
    
    for (int i = 0; i < number_of_accounts; i++){
        double rand1 = rand()%100;
        double rand2 = rand()%1000;
        b = (rand1 * rand2);
        if (i % 3 == 0){
            accounts.push_back(new Account(b));
        } else if (i % 2 == 0){
            accounts.push_back(new Savings(b));
        } else {
            accounts.push_back(new Checkings(b));
        }
    }

    int number_of_days = 33;
    
    //print_accounts_detailed(accounts, number_of_accounts, number_of_days);
    print_accounts_simple(accounts, number_of_accounts, number_of_days);
    
    return 0;
}

void print_accounts_simple(vector<Account*> v, int num_accounts, int num_days){
    int number_of_accounts = num_accounts;
    int number_of_days = num_days;
    
    for (int i = 1; i <= number_of_days; i++){
        for (int j = 0; j < number_of_accounts; j++){
            double with = rand()%1000;
            double dep = rand()%1000;
            //v[j]->display_fields();
            v[j]->deposit(dep);
            if (v[j]->get_balance() > with){
                v[j]->withdraw(with);
            }
            //v[j]->display_fields();
            v[j]->add_days();
            v[j]->daily_interest();
            //v[j]->display_fields();
        }
        if (i == 1){
            cout << "DAY 1:" << endl;
            for (int j = 0; j < number_of_accounts; j++){
                v[j]->display_fields();
            }
            cout << "\n";
        } else if (i == number_of_days){
            cout << "DAY " << number_of_days << endl;
            for (int j = 0; j < number_of_accounts; j++){
                v[j]->display_fields();
            }
            cout << "\n";
        }
    }
}

void print_accounts_detailed(vector<Account*> v, int num_accounts, int num_days){
    int number_of_accounts = num_accounts;
    int number_of_days = num_days;
    
    for (int i = 0; i < number_of_days; i++){
        for (int j = 0; j < number_of_accounts; j++){
            if (v[j]->type_account()){
                cout << "type ACCOUNT";
            } else if (v[j]->type_savings()){
                cout << "type SAVINGS";
            } else if (v[j]->type_checkings()){
                cout << "type CHECKINGS";
            }
            cout << " - Day " << i;
            cout << " - j = " << j << endl;
            double with = rand()%1000;
            double dep = rand()%1000;
            cout << "   before changes " << endl;
            v[j]->display_fields();
            v[j]->deposit(dep);
            if (v[j]->get_balance() > with){
                v[j]->withdraw(with);
            }
            cout << "   after daily desposits/withdrawals " << endl;
            v[j]->display_fields();
            v[j]->add_days();
            cout << "   after computing interest " << endl;
            v[j]->daily_interest();
            v[j]->display_fields();
            cout << endl;
        }
    }
}









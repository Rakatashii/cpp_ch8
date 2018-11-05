/*
 Exercise P8.5.
 Measure the speed difference between a statically bound call and a dynamically bound call. Use the Time class to measure the time spent in one loop of virtual function calls and another loop of regular function calls.
*/

#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>

#include "programmer.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<Employee*> all;
    all.push_back(new Employee("Dan Sweet", 239482));
    all.push_back(new Programmer("Handsome Jack", 987234));
    all.push_back(new Employee("Guy Harvey", 238942));
    all.push_back(new Programmer("Guy Fieri", 872378));
    all.push_back(new Employee("Steve Jabs", 682349));
    all.push_back(new Programmer("Michael Hardman", 7239934));
    vector<Employee*> employees;
    employees.push_back(new Employee("Dan Sweet", 239482));
    employees.push_back(new Employee("Guy Harvey", 238942));
    employees.push_back(new Employee("Steve Jabs", 682349));
    vector<Programmer*> programmers;
    programmers.push_back(new Programmer("Handsome Jack", 987234));
    programmers.push_back(new Programmer("Guy Fieri", 872378));
    programmers.push_back(new Programmer("Michael Hardman", 7239934));
    
    
    clock_t start = clock();
    // STATIC CALLS:
    for (int i = 0; i < all.size(); i++){
        if (i >= employees.size()){
            break;
        } else{
            cout << "name of employees[" << i << "]: " << employees[i]->get_employee_name() << endl;
            cout << "name of programmers[" << i << "]: " << programmers[i]->get_programmer_name() << endl;
        }
    }
    clock_t end = clock() - start;
    float time_diff1 = ((float)end)/CLOCKS_PER_SEC;
    cout << "\n";
    
    start = clock();
    // DYNAMIC CALLS:
    for (int i = 0; i < employees.size(); i++){
        if (i >= employees.size()){
            break;
        } else {
            cout << "name of all[" << i << "]: " << all[i]->get_name() << endl;
        }
    }
    end = clock() - start;
    float time_diff2 = ((float)end)/CLOCKS_PER_SEC;
    cout << "\n";
    
    cout << fixed << setprecision(8) << "time_diff1 (STATIC CALLS) = " << time_diff1 << endl;
    cout << fixed << setprecision(8) << "time_diff2 (DYNAMIC CALLS) = " << time_diff2 << endl;
    // Why does it take longer to execute the static calls?
    
    cout << "\n";
    return 0;
}


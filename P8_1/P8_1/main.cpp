/*
 Exercise P8.1.
 Derive a class Programmer from Employee. Supply a constructor Programmer(string name, double salary) that calls the base-class constructor. Supply a function get_name that returns the name in the format "Hacker, Harry (Programmer)".
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include "employee.hpp"
#include "programmer.hpp"

using namespace std;

int main() {
    vector<Employee*> e;

    e.push_back(new Employee("Dale Goodheart", 234923));
    e.push_back(new Employee("Jake", 2394.2));
    e.push_back(new Employee("Handome Jack", 92349.0));
    e.push_back(new Programmer("Handsome Jack", 98234.0));
    e.push_back(new Employee("Jane Rivers", 78234.5));
    e.push_back(new Programmer("Houstin Rockets", 12093.23));
    
    // Strange that e[i] = new Object() does not work... only push_back's. Why? Does this have anything to do with the type that the vector is storing?
    
    cout << left << setw(30) << "Employee Name" << left << setw(15) << "Employee Salary" << endl;
    for (int i = 0; i < e.size(); i++){
        cout << left << setw(30) << e[i]->get_name() << left << setw(0) << "$" << e[i]->get_salary() << left << endl;
    }
    cout << "\n";
    
    return 0;
}

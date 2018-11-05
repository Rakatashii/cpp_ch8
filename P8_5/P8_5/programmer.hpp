/*
 Exercise P8.1.
 Derive a class Programmer from Employee. Supply a constructor Programmer(string name, double salary) that calls the base-class constructor. Supply a function get_name that returns the name in the format "Hacker, Harry (Programmer)".
*/

#ifndef programmer_hpp
#define programmer_hpp

#include <stdio.h>
#include "employee.hpp"

class Programmer : public Employee {
public:
    Programmer(std::string n, double s);
    virtual std::string get_name() const;
    std::string get_programmer_name() const;
private:
    std::string name;
    double salary;
};

#endif /* programmer_hpp */

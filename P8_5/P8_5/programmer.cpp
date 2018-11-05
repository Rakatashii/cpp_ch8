/*
 Exercise P8.1.
 Derive a class Programmer from Employee. Supply a constructor Programmer(string name, double salary) that calls the base-class constructor. Supply a function get_name that returns the name in the format "Hacker, Harry (Programmer)".
*/

#include "programmer.hpp"

Programmer::Programmer(std::string n, double s) : Employee(n, s) {
    name = n;
    salary = s;
}
std::string Programmer::get_name() const{
    return name;// + " (Programmer)";
}
std::string Programmer::get_programmer_name() const{
    return name;
}

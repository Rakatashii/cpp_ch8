#include "executive.hpp"

Executive::Executive() : Manager(){
    name = "";
    department = "";
    salary = 0.0;
}
Executive::Executive(std::string n, std::string d, long double s) : Manager(n, d, s){
    name = n;
    department = d;
    salary = s;
}
std::string Executive::get_name() const{
    return (name + " (Executive)");
}
std::string Executive::get_department() const{
    return department;
}
long double Executive::get_salary() const{
    return salary;
}
void Executive::display_fields() const{
    std::cout << "Executive: \n";
    Manager::display_fields();
}

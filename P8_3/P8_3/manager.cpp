//
//  manager.cpp
//  P8_3
//
//  Created by Christian Meyer on 11/3/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "manager.hpp"

Manager::Manager() : Employee(){
    name = "";
    department = "";
    salary = 0.0;
}
Manager::Manager(std::string n, std::string d, long double s) : Employee(n, s){
    name = n;
    department = d;
    salary = s;
}
std::string Manager::get_name() const{
    return (name + " (Manager)");
}
std::string Manager::get_department() const{
    return department;
}
long double Manager::get_salary() const{
    return salary;
}
void Manager::display_fields() const{
    std::ostringstream ostr;
    int p = std::numeric_limits<double>::digits10 + 1;
    ostr << std::setprecision(p) << salary;
    std::string sal = ostr.str();
    std::cout << "     " << name << "    " << department << "    " << sal << std::endl;
}

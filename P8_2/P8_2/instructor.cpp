//
//  instructor.cpp
//  P8_2
//
//  Created by Christian Meyer on 11/3/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "instructor.hpp"

Instructor::Instructor() : Person(){
    salary = 0.0;
}
Instructor::Instructor(std::string n, std::string b, double s) : Person(n, b){
    salary = s;
}
std::string Instructor::get_name() const{
    return (Person::get_name() + " (Instructor)");
}
std::string Instructor::get_birthday() const{
    return Person::get_birthday();
}
double Instructor::get_salary() const{
    return salary;
}

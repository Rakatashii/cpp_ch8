//
//  person.cpp
//  P8_2
//
//  Created by Christian Meyer on 11/3/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "person.hpp"

Person::Person(){
    name = "";
    birthday = "";
}
Person::Person(std::string n){
    name = n;
    birthday = "";
}
Person::Person(std::string n, std::string b){
    name = n;
    birthday = b;
}
std::string Person::get_name() const{
    return name;
}
std::string Person::get_birthday() const{
    return birthday;
}

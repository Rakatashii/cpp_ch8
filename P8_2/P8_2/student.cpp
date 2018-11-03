//
//  student.cpp
//  P8_2
//
//  Created by Christian Meyer on 11/3/18.
//  Copyright © 2018 Christian Meyer. All rights reserved.
//

#include "student.hpp"

Student::Student() : Person() {
    
}
Student::Student(std::string n, std::string b, std::string m) : Person(n, b){
    name = n;
    //birthday = b;
    // so n and b are still private data in a person object, they must explicity be set the private data fields of the student class in order to 'return name;' rather than 'return Person::get_name();'
    major = m;
}
std::string Student::get_name() const{
    return (name + " (Student)");
}
// Not difference in return types here. See previous comment.
std::string Student::get_birthday() const{
    return Person::get_birthday();
}
std::string Student::get_major() const{
    return major;
}

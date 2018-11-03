/*
 Exercise P8.2.
 Implement a base class Person. Derive classes Student and Instructor from Person. A person has a name and a birthday. A student has a major, and an instructor has a salary. Write the class definitions, the constructors, and the member functions print() for all classes.
 */

#ifndef instructor_hpp
#define instructor_hpp

#include <stdio.h>
#include "person.hpp"

class Instructor : public Person{
public:
    Instructor();
    Instructor(std::string n, std::string b, double s);
    virtual std::string get_name() const;
    virtual std::string get_birthday() const;
    double get_salary() const;
private:
    std::string name, birthday;
    double salary;
};

#endif /* instructor_hpp */

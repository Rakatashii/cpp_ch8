/*
 Exercise P8.2.
 Implement a base class Person. Derive classes Student and Instructor from Person. A person has a name and a birthday. A student has a major, and an instructor has a salary. Write the class definitions, the constructors, and the member functions print() for all classes.
 */

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "person.hpp"

class Student : public Person{
public:
    Student();
    Student(std::string n, std::string b, std::string m);
    virtual std::string get_name() const;
    virtual std::string get_birthday() const;
    std::string get_major() const;
private:
    std::string name, birthday, major;
};

#endif /* student_hpp */

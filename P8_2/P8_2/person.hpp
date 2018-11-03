/*
 Exercise P8.2.
 Implement a base class Person. Derive classes Student and Instructor from Person. A person has a name and a birthday. A student has a major, and an instructor has a salary. Write the class definitions, the constructors, and the member functions print() for all classes.
 */

#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <string>

class Person{
public:
    Person();
    Person(std::string n);
    Person(std::string n, std::string b);
    virtual std::string get_name() const;
    virtual std::string get_birthday() const;
private:
    std::string name, birthday;
};

#endif /* person_hpp */

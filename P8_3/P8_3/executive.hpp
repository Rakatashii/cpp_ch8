/*
 Exercise P8.3.
 Derive a class Manager from Employee. Add a data field, named department, of type string. Supply a function print that prints the manager’s name, department, and salary. Derive a class Executive from Manager. Supply a function print that prints the string Executive, followed by the information stored in the Manager base object.
 */

#ifndef executive_hpp
#define executive_hpp

#include "manager.hpp"

class Executive : public Manager{
public:
    Executive();
    Executive(std::string n, std::string d, long double s);
    virtual std::string get_name() const;
    virtual std::string get_department() const;
    virtual long double get_salary() const;
    virtual void display_fields() const;
private:
    std::string name, department;
    long double salary;
};

#endif /* executive_hpp */

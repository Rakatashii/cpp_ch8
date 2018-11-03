/*
 Exercise P8.2.
 Implement a base class Person. Derive classes Student and Instructor from Person. A person has a name and a birthday. A student has a major, and an instructor has a salary. Write the class definitions, the constructors, and the member functions print() for all classes.
*/

#include <iostream>
#include <vector>
#include <iomanip>

#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

using namespace std;

void display_people(vector<Person*> people);
void display_all(vector<Person*> people);

int main(int argc, const char * argv[]) {
    vector<Person*> people;
    people.push_back(new Person("Dan Jones", "2-29-1989"));
    people.push_back(new Student("Gail Earnheart", "3-17-2001", "Philosophy"));
    people.push_back(new Instructor("David Kaplan", "11-01-1912", 107823.5));
    people.push_back(new Person("Handsome Jack", "12-5-234"));

    display_people(people);
    return 0;
}

void display_people(vector<Person*> people){
    cout << left << setw(30) << "Name" << left << setw(15) << "Birthday" << endl;
    for (int i = 0; i < people.size(); i++){
        cout << left << setw(30) << people[i]->get_name() << left << setw(15) << people[i]->get_birthday() << endl;
    }
}
void display_all(vector<Person*> people){
    cout << left << setw(15) << "Name" << left << setw(15) << "Birthday" << left << setw(15) << "Major" << left << setw(15) << "Salary" << endl;
    for (int i = 0; i < people.size(); i++){
        //cout << left << setw(15) << people[i]->get_name() << left << setw(15) << people[i]->get_birthday() << left << setw(15) << people[i]->get_major() << left << setw(15) << people[i]->get_salary() << endl;
    }
    // This does not work.
    // Because the vector is of type Person*, there is no way to access member function of the derived classes such as Student#get_major() and Instructor#get_salary()
}

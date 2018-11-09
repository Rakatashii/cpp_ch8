#ifndef appointment_hpp
#define appointment_hpp

/*
 Exercise P8.7.
 Implement a base class Appointment and derived classes Onetime, Daily, Weekly, and Monthly.
 - An appointment has a description (for example, “see the den- tist”) and a date and time.
 - Write a virtual function occurs_on(int year, int month, int day) that checks whether the appointment occurs on that date.
 For example:
 for a monthly appointment, you must check whether the day of the month matches. Then fill a vector of Appointment* with a mixture of appointments. Have the user enter a date and print out all appointments that happen on that date.
 
 Exercise P8.8.
 Improve the appointment book program of Exercise P8.7.
 - Give the user the option to add new appointments.
 The user must specify the type of the appointment, the description, and the date and time.
 
 Exercise P8.9.
 Improve the appointment book program of Exercises P8.7 and P8.8 by letting the user save the appointment data to a file and reload the data from a file.
 - The saving part is straightforward:
 Make a virtual function save. Save out the type, description, date, and time.
 The loading part is not so easy.
 You must first determine the type of the appointment to be loaded, create an object of that type with its default constructor, and then call a virtual load function to load the remainder.
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include "appointment.hpp"

class Appointment {
public:
    Appointment();
    Appointment(std::string d, int M, int D, int Y, int h = -1, int m = -1, bool new_vector = false);
    void add_appt(Appointment* A);
    void add_appt_vector(Appointment* A);
    Appointment* operator[](int index) { return appointments[index]; };
    
    virtual void set_reoccurring(int num_months) { /* DO NOTHING IN BASE CLASS */ };
    
    virtual Appointment* occurs_on(int M, int D, int Y, int h, int m);
    std::vector<Appointment*> occurring_on(int M, int D, int Y, int h, int m, std::ostream &out = std::cout, bool detailed_output = false);
        
    void output_vector(std::vector<Appointment*> appts, std::ostream& out = std::cout);
    
    virtual void set_time_given(bool tg);
    virtual bool get_time_given() const { return time_given; };
    virtual int size() const { return appointments.size(); };
    virtual std::string get_description() const { return description; };
    virtual int get_month() const { return month; };
    virtual int get_day() const { return day; };
    virtual int get_year() const { return year; };
    virtual int get_hour() const { return hour; };
    virtual int get_minute() const { return minute; };
    virtual std::string get_date() const { return date_str; };
    virtual std::string get_time() const { return time_str; };
    virtual std::vector<Appointment*> get_appointments() const { return appointments; };
    
    virtual void make_fields_string();
    virtual std::string get_fields_string();
    void save(std::string file_name, std::ostream& out = std::cout);
    std::vector<std::vector<std::string> > load(std::string file_name, bool cout_output = false);
    
private:
    std::string description;
    int year, month, day, hour, minute;
    std::vector<Appointment*> appointments;
    std::vector<std::string> fields_string;
    bool time_given;
    std::string date_str, time_str;
    std::string period;
};

#endif /* appointment_hpp */

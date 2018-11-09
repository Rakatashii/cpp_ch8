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

#ifndef onetime_hpp
#define onetime_hpp

#include <stdio.h>
#include "appointment.hpp"

class OneTime : public Appointment {
public:
    OneTime(std::string d, int M, int D, int Y, int h = -1, int m = -1);
    
    virtual Appointment* occurs_on(int M, int D, int Y, int h, int m);
    
    virtual void set_time_given(bool tg) { time_given = tg; };
    virtual bool get_time_given() const { return time_given; };
    virtual int size() const { return appointments.size(); };
    virtual std::string get_description() const { return "(OneTime) " + description; };
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
    
private:
    std::string description;
    int year, month, day, hour, minute;
    std::vector<Appointment*> appointments;
    std::vector<std::string> fields_string;
    bool time_given;
    std::string date_str, time_str;
    std::string period;
};

#endif /* onetime_hpp */

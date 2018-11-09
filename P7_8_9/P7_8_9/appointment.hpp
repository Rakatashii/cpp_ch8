/*
 Exercise P8.7.
 Implement a base class Appointment and derived classes Onetime, Daily, Weekly, and Monthly.
 - An appointment has a description (for example, “see the dentist”) and a date and time.
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

#ifndef appointment_hpp
#define appointment_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

class Appointment{
public:
    Appointment();
    Appointment(std::string desc, int Y, int M, int D);
    Appointment(std::string desc, int Y, int M, int D, int h, int m);
    virtual void display_date(std::ostream& out = std::cout) const;
    virtual void display_time(std::ostream& out = std::cout) const;
    virtual void display_description(std::ostream& out = std::cout) const;
    virtual void display_appt(std::ostream& out = std::cout) const;
    virtual void display_bare_appt(std::ostream& out = std::cout) const;
    virtual Appointment* occurs_on(int y, int m, int d, bool show_details = false, std::ostream& out = std::cout);
    virtual bool time_given() const { return appt_time_given; };
private:
    std::string description;
    int year, month, day, hour, minute;
    std::string am_pm;
    bool appt_time_given;
};

#endif /* appointment_hpp */

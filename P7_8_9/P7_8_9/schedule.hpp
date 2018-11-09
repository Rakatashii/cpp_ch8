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

#ifndef schedule_hpp
#define schedule_hpp

#include <vector>
#include <string>
#include "appointment.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

const std::string keepfile = "/Users/christianmeyer/cpp/ch8/P7_8_9/P7_8_9/keepfile.txt";

class Schedule{
public:
    Schedule();
    Schedule(std::string n);
    Schedule(std::string n, Appointment* app);
    void add_appointment(Appointment* app);
    Appointment* operator[](int i) { return appointments[i]; };
    std::vector<Appointment*> get_all_appointments();
    std::vector<Appointment*> occurs_on(int y, int m, int d, bool show_details = false, std::ostream& out = std::cout);
    // no need to make ^ virtual since no inheritance
    void store_all(std::ostream& out = std::cout);
    void save_appointments(std::vector<Appointment*> appts, bool file_empty = true, std::string search_tag = "TEMP");
    void get_saved_appointments(int index);
    std::string get_saved_file_name(int index);
    std::string get_keepfile_name(int index, bool include_past_saves = false);
    int get_keepfile_size();
    int get_keepfile_base_index() const;
    std::vector<std::vector<std::string> > get_saved_fields(int index);
private:
    std::string name;
    std::vector<Appointment*> appointments;
    int number_of_appointments;
    std::vector<std::string> saved_files;
    std::vector<std::vector<Appointment*> > saved_appointments;
    std::vector<std::vector<std::vector<std::string> > > saved_appointment_fields;
    int keepfile_base_index;
};

#endif /* schedule_hpp */

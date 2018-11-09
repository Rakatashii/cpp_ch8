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

#include <iostream>
#include <sstream>
#include "appointment.hpp"
#include "onetime.hpp"
#include "monthly.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Appointment main("go to dentist", 3, 29, 1994, 8, 30, true); // Note true here means that this appointment will be the only one to initiate and continue to fill a vector of Appointment pointers.
    main.add_appt(new Appointment("go see Kelly", 9, 18, 2001, 12, 15));
    main.add_appt(new Appointment("find Martin's file", 9, 18, 2001, 12, 15));
    main.add_appt(new Appointment("help Chris", 9, 18, 2001, 12, 15));
    main.add_appt(new OneTime("Pick up Jim", 9, 18, 2001, 12, 15));
    main.add_appt(new OneTime("Grocery Store", 9, 18, 2001, 12, 15));
    main.add_appt(new Appointment("help Dorathy", 9, 18, -1, 12, 15));
    main.add_appt(new OneTime("Pick up David", 9, 18, -1, 12, 15));
    main.add_appt(new OneTime("Grocery Store", 9, 18, -1, 12, 15));
    main.add_appt(new Appointment("find Jake's file", 9, -1, -1, 12, 15));
    main.add_appt(new Appointment("help Chris", 9, -1, -1, 12, 15));
    main.add_appt(new OneTime("Pick up David", 9, -1, -1, 12, 15));
    main.add_appt(new Appointment("find Steve's file", 9, -1, 2001, 12, 15));
    main.add_appt(new Appointment("help Chris", 9, -1, 2001, 12, 15));
    main.add_appt(new OneTime("Pick up David", 9, -1, 2001, 12, 15));
    main.add_appt(new OneTime("Grocery Store", 9, -1, 2001, 12, 15));
    main.add_appt(new Monthly("find Jacob's file", 9, -1, -1, 12, 15));
    main.add_appt(new Monthly("get on app", 9, -1, -1, 12, 15));
    main.add_appt(new Monthly("Pick up Doran", 9, -1, -1, 12, 15));
    main.add_appt(new Monthly("find Jim's file", 9, -1, 2001, 12, 15));
    main.add_appt(new Monthly("Apple appt", 9, -1, 2001, 12, 15));
    main.add_appt(new Monthly("Pick up Margeret", 9, -1, 2001, 12, 15));
    main.add_appt(new Monthly("Mall", 9, -1, 2001, 12, 15));
    
    Appointment* m0 = main[0];
    Appointment* m1 = main[1];
    string m0_str = m0->get_fields_string();
    string m1_str = m1->get_fields_string();
    cout << m0_str << endl;
    cout << m1_str << endl;
    cout << "\n";
    
    /*
    vector<Appointment*> aug18 = main.occurring_on(9, 18, 2001, 12, 15);
    cout << "Appts on aug 18: " << endl;
    for (int i = 0; i < aug18.size(); i++){
        cout << aug18[i]->get_fields_string();
    }
    */
    //main.output_vector(main.occurs_on(3, 29, 1994, 8, 30), std::cout);
    //main.occurring_on(9, 18, 2001, 12, 15, cout, true);
    
    // The -1 condition for any of the date fields indicates that those fields should not be considrered int he #occurring_on base member func. For this reason, the output reads 'Appointments on date 09/2001' rather than 'date 09/-1/2001' or 'date 09/00/2001'.
    main.occurring_on(9, -1, 2001, 12, 15, cout, true);
    cout << "\n";
    
    // After reconsidering the point of a monthly derived class, the derived class was given the ability to make several Monthly appointments for a set number of reoccurring months (i.e., Monthly#set_reoccurring(int); The following code tests whether those appointments are contained in the #appointments data member of the base class, and whether the base#occurring_on() func is able to point out that a reoccurring appt date matched the date specified in the parameters.
    main[main.size()-1]->set_reoccurring(4);
    vector<Appointment*> monthly_appts = main[main.size()-1]->get_appointments();
    for (int i = 0; i < monthly_appts.size(); i++){
        cout << "monthly[" << i << "]: " << monthly_appts[i]->get_fields_string() << endl;
    }
    cout << "\n";
    
    // Month incremented by 1 (see above comment).
    main.occurring_on(10, -1, 2001, 12, 15, cout, true);
    
    string savefile = "/Users/christianmeyer/cpp/ch8/P8_7_8_9_REDO/P8_7_8_9_REDO/savefile.txt";
    main.save(savefile);

    // prints data fields for all appointments stored in main. The 'true' parameter is used to tell the #load func to output the vector contents to the console.
    vector<vector<string> > all = main.load(savefile, true);
    
    cout << "\n";
    return 0;
}










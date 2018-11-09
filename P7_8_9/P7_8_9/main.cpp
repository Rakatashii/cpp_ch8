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
#include "schedule.hpp"
#include "appointment.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Schedule S("Dave Kaplan");
    S.add_appointment(new Appointment("dentist", 2018, 03, 23));
    S.add_appointment(new Appointment("get Lenny from school", 2016, 05, 15));
    S.add_appointment(new Appointment("get Joey from karate", 201, 5, 1));
    S.add_appointment(new Appointment("massage", 34, 4, 9));
    S.add_appointment(new Appointment("go buy candles", 2016, 05, 15, 1, 0));
    S.add_appointment(new Appointment("head to school", 206, 6, 11, 16, 5));
    S.add_appointment(new Appointment("go buy candles", 2016, 05, 15, 1, 0));
    vector<Appointment*> appts = S.get_all_appointments();
    for (int i = 0; i < appts.size(); i++){
        vector<Appointment*> matched;
        // using #occurs_on and #display_appt from appointment.hpp
        if (S[i]->occurs_on(2016, 05, 15, true)){
            S[i]->display_appt();
        }
    }
    cout << "\n";
    // using occurs_on from schedule.hpp
    S.occurs_on(2016, 05, 15, true);
    cout << "\n";
    
    ofstream fout;
    fout.open("/Users/christianmeyer/cpp/ch8/P7_8_9/P7_8_9/test_output.txt", std::ios::in | std::ios::out);
    S.occurs_on(2016, 05, 15, false, fout);
    fout.close();
    fout.open("/Users/christianmeyer/cpp/ch8/P7_8_9/P7_8_9/all_appts.txt", fstream::in | fstream::out | fstream::trunc);
    S.store_all(fout);
    fout.close();
    
    /*
    const char *prefix = "/Users/christianmeyer";
    const char *dir = "cpp/ch8/P7_8_9/P7_8_9/TEMP";
    vector<char*> file_names;
    char *file;
    for (int i = 0; i < 10; i++){
        file = tempnam(prefix, dir);
        file_names.push_back(file);
    }
    for (int i = 0; i < 10; i++){
        cout << "file" << i << ": " << file_names[i] << endl;
    }
    fout.open(file_names[0], fstream::in | fstream::out | fstream::trunc);
    S.store_all(fout);
    fout.close();
     */
    
    vector<Appointment*> all = S.get_all_appointments();
    S.save_appointments(all, true, "Jeremy");
    S.get_saved_appointments(0);
    
    string f_name = S.get_saved_file_name(0);
    vector<vector<string> > appts0 = S.get_saved_fields(0);
    for (int i = 0; i < appts0.size(); i++){
        cout << "appts0[" << i << "][0] (date): " << appts0[i][0] << endl;
        cout << "appts0[" << i << "][1] (time): " << appts0[i][1] << endl;
        cout << "appts0[" << i << "][2] (desc): " << appts0[i][2] << endl;
    }
    
    cout << "keepfile_base_index: " << S.get_keepfile_base_index() << endl;
    cout << "keepfile_size      : " << S.get_keepfile_size() << endl;
    
    vector<string> current_keepfiles;
    for (int i = S.get_keepfile_base_index()-1; i < S.get_keepfile_size(); i++){
        string keepfile = S.get_keepfile_name(i, true);
        current_keepfiles.push_back(keepfile);
    }
    for (int i = 0; i < current_keepfiles.size(); i++){
        cout << "current_keepfiles[" << i << "]: " << current_keepfiles[i] <<endl;
    }
    
    system("pwd");
    cout << "\n";
    return 0;
}

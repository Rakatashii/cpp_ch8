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

#include "appointment.hpp"

Appointment::Appointment(){
    appointments = {};
}
Appointment::Appointment(std::string d, int M, int D, int Y, int h, int m, bool new_vector){
    appointments = {};
    description = d;
    month = M; day = D; year = Y;
    hour = h; minute = m;
    
    if (h == -1 && m == -1){
        time_given = false;
    } else if (h == -1){
        h = 0;
        time_given = true;
    } else if (m == -1){
        m = 0;
        time_given = true;
    } else {
        time_given = true;
    }
    if (hour <= 12){
        period = "am";
        if (hour == 12){
            period = "pm";
        }
    } else if (hour > 12){
        period = "pm";
        hour -= 12;
    }
    
    this->make_fields_string();
    
    if (new_vector){
        appointments.push_back(new Appointment(d, M, D, Y, h, m));
    }
}
void Appointment::add_appt(Appointment* A){
    appointments.push_back(A);
}
void Appointment::add_appt_vector(Appointment* A){
    std::vector<Appointment*> A_appts = A->get_appointments();
    if (A_appts.size() > 0){
        for (int i = 0; i < A_appts.size()-1; i++){
            appointments.push_back(A_appts[i]);
        }
    }
}
Appointment* Appointment::occurs_on(int M, int D, int Y, int h, int m){
    if (this->year == Y || Y == -1){
        if (this->month == M || M == -1){
            if (this->day == D || h == -1){
                if (this->hour == h || h == -1){
                    if (this->minute == m || m == -1){
                        return this;
                    }
                }
            }
        }
    }
    return NULL;
}

std::vector<Appointment*> Appointment::occurring_on(int M, int D, int Y, int h, int m, std::ostream &out, bool detailed_output){
    Appointment* A = new Appointment("", M, D, Y, h, m);
    std::vector<Appointment*> appts;
    for (int i = 0; i < appointments.size(); i++){
        if (appointments[i]->size() > 0){
            add_appt_vector(appointments[i]);
        }
        if (appointments[i]->occurs_on(M, D, Y, h, m) != NULL){
            appts.push_back(appointments[i]);
        }
    }
    if (detailed_output && appts.size() > 0){
        std::string print_string = A->get_date();
        if (A->get_year() == -1){
            print_string = A->get_date().substr(0, A->get_date().size()-3);
            if (A->get_month() == -1){
                print_string = A->get_date().substr(3, A->get_date().size()-3);
                out << "Appointments on day " << print_string << ":" << std::endl;
            } else if (A->get_day() == -1){
                print_string = A->get_date().substr(0, 2);
                out << "Appointments on month " << print_string << ":" << std::endl;
            } else {
                out << "Appointments on date " << print_string << ":" << std::endl;
            }
        } else if (A->get_month() == -1){
            print_string = A->get_date().substr(3, A->get_date().size()-3);
            out << "Appointments on date " << print_string << ":" << std::endl;
        } else if (A->get_day() == -1){
            //std::string first_half = A->get_date().substr(0, 2);
            //std::string second_half = A->get_date().substr(5, 5);
            print_string = A->get_date().substr(0, 2) + A->get_date().substr(5, 5);
            out << "Appointments on date " << print_string << ":" << std::endl;
        }
        if (detailed_output){
            for (int i = 0; i < appts.size(); i++){
                if (appts[i]->get_time_given()){
                    std::string appt_time = appts[i]->get_time();
                    if (appts[i]->get_hour() == -1){
                        appt_time = std::to_string(appts[i]->get_minute());
                    } else if (appts[i]->get_minute() == -1){
                        appt_time = std::to_string(appts[i]->get_hour());
                    }
                    out << "   " << std::left << std::setw(30) << appts[i]->get_description();
                    out << " - " << std::left << std::setw(10) << appts[i]->get_time() << std::endl;
                } else{
                    out << "   " << appts[i]->get_description() << std::endl;
                }
            }
        }
    } else if (detailed_output){
        out << "No Appointments on " << A->get_date() << "." << std::endl;
    }
    return appts;
}
void Appointment::output_vector(std::vector<Appointment*> appts, std::ostream& out){
    if (appts.size() > 0){
        for (int i = 0; i < appts.size(); i++){
            out << appts[i]->get_fields_string();
        }
    }
}
void Appointment::set_time_given(bool tg){
    time_given = tg;
}
void Appointment::make_fields_string(){
    fields_string = {};
    std::vector<std::string> date_vect = {};
    std::vector<std::string> time_vect = {};
    std::string descr = this->get_description();
    std::string M_str = std::to_string(this->get_month()); date_vect.push_back(M_str);
    std::string D_str = std::to_string(this->get_day()); date_vect.push_back(D_str);
    std::string Y_str = std::to_string(this->get_year()); date_vect.push_back(Y_str);
    std::string date = "";
    std::string time = "";
    
    descr += "|";
    fields_string.push_back(descr);
    
    for(int i = 0; i < date_vect.size(); i++){
        if (date_vect[i].size() < 2){
            date_vect[i] = "0"+date_vect[i];
            //std::cout << "fields[" << i << "]: " << date_vect[i] << std::endl;
        }
        if (i != date_vect.size()-1){
            date += date_vect[i] + "\\";
        } else {
            date += date_vect[i];
        }
    }
    
    date_str = date;
    date += "|";
    fields_string.push_back(date);
    if (this->get_time_given()){
        std::string h_str = std::to_string(this->get_hour()); time_vect.push_back(h_str);
        std::string m_str = std::to_string(this->get_minute()); time_vect.push_back(m_str);
        for(int i = 0; i < time_vect.size(); i++){
            if (time_vect[i].size() < 2){
                time_vect[i] = "0"+time_vect[i];
            }
            if (i != time_vect.size()-1){
                time += time_vect[i] + ":";
            } else{
                time += time_vect[i];
            }
        }
        time += period;
        time_str = time;
        fields_string.push_back(time);
    }
}
std::string Appointment::get_fields_string(){
    std::string line;
    if (fields_string.size() > 0){
        for (int i = 0; i < fields_string.size(); i++){
            line += fields_string[i];
        }
    }
    return line;
}
void Appointment::save(std::string file_name, std::ostream& out){
    if (&out == &std::cout){
        std::ofstream fout;
        fout.open(file_name.c_str());
        for (int i = 0; i < appointments.size(); i++){
            fout << appointments[i]->get_fields_string() << std::endl;
        }
        fout.close();
    } else {
        for (int i = 0; i < appointments.size(); i++){
            out << appointments[i]->get_fields_string() << std::endl;
        }
    }
}
std::vector<std::vector<std::string> > Appointment::load(std::string file_name, bool cout_output){
    std::ifstream ins(file_name.c_str());
    
    std::vector<std::vector<std::string> > all;
    std::string desc, date, time;
    
    int i = 0;
    while (getline(ins, desc, '|')){
        std::vector<std::string> appt;
        std::getline(ins, date, '|');
        std::getline(ins, time, '\n');
        appt.push_back(desc);
        appt.push_back(date);
        appt.push_back(time);
        all.push_back(appt);
        i++;
    }
    
    if (cout_output){
        for (int i = 0; i < all.size(); i++){
            std::cout << "all[" << i << "]: " << std::endl;
            for (int j = 0; j < all[i].size(); j++){
                std::string print_string = all[i][j];
                for (int k = 0; k < all[i][j].length(); k++){
                    if (all[i][j][k] == '-'){
                        print_string[k] = '0';
                        print_string[k+1] = '0';
                    }
                }
                std::cout << "   all[" << i << "][" << j << "]: " << print_string << std::endl;
            }
        }
    }
    
    return all;
}


/*
private:
std::string description;
std::vector<Appointment*> appointments;
int year, month, day, hour, minute;
 */

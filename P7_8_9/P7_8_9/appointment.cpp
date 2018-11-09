#include "appointment.hpp"

Appointment::Appointment(){
    description = "";
    year = 0; month = 0; day = 0; hour = 0; minute = 0;
    appt_time_given = false;
}
Appointment::Appointment(std::string desc, int Y, int M, int D){
    description = desc;
    year = Y; month = M; day = D; hour = 0; minute = 0; am_pm = "am";
    appt_time_given = false;
}
Appointment::Appointment(std::string desc, int Y, int M, int D, int h, int m){
    description = desc;
    year = Y; month = M; day = D; hour = h; minute = m; am_pm = "am";
    if (h == 12){
        h = 12;
        am_pm = "pm";
    } else if (h > 12){
        h -= 12;
        am_pm = "pm";
    }
    appt_time_given = true;
}
void Appointment::display_date(std::ostream& out) const{
    out << std::setfill('0') << std::setw(2) << this->month << "/" << std::setw(2) << this->day << "/" << std::setw(4) << this->year;
    if (time_given()){
        out << " - ";
        this->display_time(out);
    }
    if (&out == &std::cout){
        out << std::endl;
    }
}
void Appointment::display_time(std::ostream& out) const{
    if (time_given()){
        out << std::setfill('0') << std::setw(2) << this->hour << ":" << std::setfill('0') << std::setw(2) << this->minute << this->am_pm;
    }
}
void Appointment::display_appt(std::ostream& out) const{
    out << "Date: ";
    this->display_date(out);
    out << "       \u2022 " << (this->description).c_str() << std::endl;
}
void Appointment::display_bare_appt(std::ostream& out) const{
    this->display_date(out);
    out << " | ";
    out << this->description;
    out << std::endl;
}
void Appointment::display_description(std::ostream& out) const{
    if (this->time_given()) {
        out << "       \u2022 [";
        this->display_time(out);
        out << "] " << this->description;
    } else {
        out << "       \u2022 " << this->description;
    }
    if (&out == &std::cout){
        std::cout << std::endl;
    }
}
Appointment* Appointment::occurs_on(int y, int m, int d, bool show_details, std::ostream& out){
    if (y == this->year && m == this->month && d == this->day){
        if (show_details){
            if (&std::cout == &out){
                out << "appointment found on ";
                this->display_date(std::cout);
            }
        }
        return this;
    }
    return NULL;
}

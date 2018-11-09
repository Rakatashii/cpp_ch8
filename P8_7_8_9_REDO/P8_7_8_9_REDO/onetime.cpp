#include "onetime.hpp"

OneTime::OneTime(std::string d, int M, int D, int Y, int h, int m) : Appointment(d, M, D, Y, h, m){
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
}
Appointment* OneTime::occurs_on(int M, int D, int Y, int h, int m){
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

void OneTime::make_fields_string(){
    fields_string = {};
    std::vector<std::string> date_vect = {};
    std::vector<std::string> time_vect = {};
    std::string M_str = std::to_string(this->get_month()); date_vect.push_back(M_str);
    std::string D_str = std::to_string(this->get_day()); date_vect.push_back(D_str);
    std::string Y_str = std::to_string(this->get_year()); date_vect.push_back(Y_str);
    std::string date = "";
    std::string time = "";
    
    std::string descr = this->get_description();
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
std::string OneTime::get_fields_string(){
    std::string line;
    if (fields_string.size() > 0){
        for (int i = 0; i < fields_string.size(); i++){
            line += fields_string[i];
        }
    }
    return line;
}

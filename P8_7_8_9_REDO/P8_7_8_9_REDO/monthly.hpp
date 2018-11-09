#ifndef monthly_hpp
#define monthly_hpp

#include <stdio.h>
#include "appointment.hpp"

class Monthly : public Appointment {
public:
    Monthly(std::string d, int M, int D, int Y, int h = -1, int m = -1);
    virtual Appointment* occurs_on(int M, int D, int Y, int h, int m);
    virtual void set_reoccurring(int num_months);
    
    virtual void set_time_given(bool tg) { time_given = tg; };
    virtual bool get_time_given() const { return time_given; };
    virtual int size() const { return appointments.size(); };
    virtual std::string get_description() const { return "(Monthly) " + description; };
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

#endif /* monthly_hpp */

/*
 Exercise P8.6.
 Write a base class Worker and derived classes HourlyWorker and SalariedWorker. Every worker has a name and a salary rate. Write a virtual function compute_pay(int hours) that computes the weekly pay for every worker. An hourly worker gets paid the hourly wage for the actual number of hours worked, if hours is at most 40. If the hourly worker worked more than 40 hours, the excess is paid at time and a half. The salaried worker gets paid the hourly wage for 40 hours, no mat- ter what the actual number of hours is.
 */

#include "hourlyworker.hpp"

HourlyWorker::HourlyWorker(){
    name = "";
    salary_rate = 0;
}
HourlyWorker::HourlyWorker(std::string n, double r) : Worker(n, r){
    name = n;
    salary_rate = r;
}
double HourlyWorker::compute_pay(int hours){
    int full_paid_hours = 0;
    int half_paid_hours = 0;
    if (hours >= WORKER::hours_per_week){
        full_paid_hours = WORKER::hours_per_week;
        half_paid_hours = hours - WORKER::hours_per_week;
    } else {
        full_paid_hours = hours;
    }
    double pay = (full_paid_hours*salary_rate) + (half_paid_hours*(0.5*salary_rate));
    return pay;
}

/*
 Exercise P8.6.
 Write a base class Worker and derived classes HourlyWorker and SalariedWorker. Every worker has a name and a salary rate. Write a virtual function compute_pay(int hours) that computes the weekly pay for every worker. An hourly worker gets paid the hourly wage for the actual number of hours worked, if hours is at most 40. If the hourly worker worked more than 40 hours, the excess is paid at time and a half. The salaried worker gets paid the hourly wage for 40 hours, no mat- ter what the actual number of hours is.
*/

#ifndef hourlyworker_hpp
#define hourlyworker_hpp

#include <stdio.h>
#include "worker.hpp"

class HourlyWorker : public Worker{
public:
    HourlyWorker();
    HourlyWorker(std::string n, double r);
    virtual double compute_pay(int hours);
    
private:
    std::string name;
    double salary_rate;
};

#endif /* hourlyworker_hpp */

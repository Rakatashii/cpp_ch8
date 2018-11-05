/*
 Exercise P8.6.
 Write a base class Worker and derived classes HourlyWorker and SalariedWorker. Every worker has a name and a salary rate. Write a virtual function compute_pay(int hours) that computes the weekly pay for every worker. An hourly worker gets paid the hourly wage for the actual number of hours worked, if hours is at most 40. If the hourly worker worked more than 40 hours, the excess is paid at time and a half. The salaried worker gets paid the hourly wage for 40 hours, no mat- ter what the actual number of hours is.
 */

#include "worker.hpp"

Worker::Worker(){
    name = "";
    salary_rate = 0.0;
}
Worker::Worker(std::string n, double r){
    name = n;
    salary_rate = r;
}
void Worker::set_salary_rate(double r){
    salary_rate = r;
}
std::string Worker::get_name() const{
    return name;
}
double Worker::get_salary_rate() const{
    return salary_rate;
}
double Worker::compute_pay(int hours){
    return hours*salary_rate;
}

/*
private:
std::string name;
double salary_rate;
*/

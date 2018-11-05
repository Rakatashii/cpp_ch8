/*
 Exercise P8.6.
 Write a base class Worker and derived classes HourlyWorker and SalariedWorker. Every worker has a name and a salary rate. Write a virtual function compute_pay(int hours) that computes the weekly pay for every worker. An hourly worker gets paid the hourly wage for the actual number of hours worked, if hours is at most 40. If the hourly worker worked more than 40 hours, the excess is paid at time and a half. The salaried worker gets paid the hourly wage for 40 hours, no mat- ter what the actual number of hours is.
 */

#include "salaryworker.hpp"

SalaryWorker::SalaryWorker() : Worker(){
    name = "";
    salary_rate = 0.0;
}
SalaryWorker::SalaryWorker(std::string n, double r) : Worker(n, r){
    name = n;
    salary_rate = r;
}
void SalaryWorker::set_salary_rate(double r){
    //Worker::set_salary_rate(r);
    salary_rate = r;
}
double SalaryWorker::get_salary_rate() const{
    return salary_rate;;
}
double SalaryWorker::compute_pay(int hours){
    double salary = WORKER::hours_per_week * salary_rate;
    return salary;
}

/*
private:
std::string name;
double salary;
*/

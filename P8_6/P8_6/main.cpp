/*
 Exercise P8.6.
 Write a base class Worker and derived classes HourlyWorker and SalariedWorker. Every worker has a name and a salary rate. Write a virtual function compute_pay(int hours) that computes the weekly pay for every worker. An hourly worker gets paid the hourly wage for the actual number of hours worked, if hours is at most 40. If the hourly worker worked more than 40 hours, the excess is paid at time and a half. The salaried worker gets paid the hourly wage for 40 hours, no matter what the actual number of hours is.
*/

#include <iostream>
#include "hourlyworker.hpp"
#include "salaryworker.hpp"
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL)); // this works without time.h?
    vector<Worker*> workers;
    workers.push_back(new Worker("Tom Jones", 11.52));
    workers.push_back(new HourlyWorker("Jim Jones", 11.52));
    workers.push_back(new SalaryWorker("Jake Smith", 11.52));
    workers.push_back(new Worker("Dave Guy", 22.07));
    workers.push_back(new HourlyWorker("Gosh Harvey", 22.07));
    workers.push_back(new SalaryWorker("Guy Fieri", 22.07));
    
    for (int i = 0; i < workers.size(); i++){
        int overtime_hours = rand()%21;
        int work_time = WORKER::hours_per_week + overtime_hours;
        //workers[i]->compute_pay(work_time);
        cout << fixed << setprecision(2) << "worker" << i+1 <<" (" << workers[i]->get_name() << ") worked " << work_time << " hours, and earned $" << workers[i]->compute_pay(work_time) << endl;
    }

    cout << "\n";
    return 0;
}

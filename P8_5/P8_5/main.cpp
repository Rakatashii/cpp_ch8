/*
 Exercise P8.5.
 Measure the speed difference between a statically bound call and a dynamically bound call. Use the Time class to measure the time spent in one loop of virtual function calls and another loop of regular function calls.
*/

#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <chrono>

#include "programmer.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<Employee*> all;
    all.push_back(new Employee("Dan Sweet", 239482));
    all.push_back(new Programmer("Handsome Jack", 987234));
    all.push_back(new Employee("Guy Harvey", 238942));
    all.push_back(new Programmer("Guy Fieri", 872378));
    all.push_back(new Employee("Steve Jabs", 682349));
    all.push_back(new Programmer("Michael Hardman", 7239934));
    vector<Employee*> employees;
    employees.push_back(new Employee("Dan Sweet", 239482));
    employees.push_back(new Employee("Guy Harvey", 238942));
    employees.push_back(new Employee("Steve Jabs", 682349));
    vector<Programmer*> programmers;
    programmers.push_back(new Programmer("Handsome Jack", 987234));
    programmers.push_back(new Programmer("Guy Fieri", 872378));
    programmers.push_back(new Programmer("Michael Hardman", 7239934));
    
    chrono::high_resolution_clock::time_point static_hrc_start = chrono::high_resolution_clock::now();
    clock_t start = clock();
    // STATIC CALLS:
    for (int i = 0; i < all.size(); i++){
        if (i >= employees.size()){
            break;
        } else{
            cout << "name of employees[" << i << "]: " << employees[i]->get_employee_name() << endl;
            cout << "name of programmers[" << i << "]: " << programmers[i]->get_programmer_name() << endl;
        }
    }
    chrono::high_resolution_clock::time_point static_hrc_end = chrono::high_resolution_clock::now();
    clock_t end = clock() - start;
    float time_diff1 = ((float)end)/CLOCKS_PER_SEC;
    auto static_hrc_diff = chrono::duration_cast<chrono::microseconds>(static_hrc_end-static_hrc_start).count();
    cout << "\n";
    
    chrono::high_resolution_clock::time_point dynamic_hrc_start = chrono::high_resolution_clock::now();
    start = clock();
    // DYNAMIC CALLS:
    for (int i = 0; i < employees.size(); i++){
        if (i >= employees.size()){
            break;
        } else {
            cout << "name of all[" << i << "]: " << all[i]->get_name() << endl;
        }
    }
    chrono::high_resolution_clock::time_point dynamic_hrc_end = chrono::high_resolution_clock::now();
    end = clock() - start;
    float time_diff2 = ((float)end)/CLOCKS_PER_SEC;
    auto dynampic_hrc_diff = chrono::duration_cast<chrono::microseconds>(dynamic_hrc_end-dynamic_hrc_start).count();
    cout << "\n";
    
    cout << fixed << setprecision(8) << "time_diff1 (STATIC CALLS) = " << time_diff1 << endl;
    cout << fixed << setprecision(8) << "time_diff2 (DYNAMIC CALLS) = " << time_diff2 << endl;
    cout << fixed << setprecision(8) << "static_hrc_diff (\u00B5s) = " << static_hrc_diff << endl;
    cout << fixed << setprecision(8) << "dynamic_hrc_diff (\u00B5s) = " << dynampic_hrc_diff << endl;
    // NOTE, when using chrono::seconds or chrono::milliseconds, the value is rounded to 0
    
    // Why does it take longer to execute the static calls?
    /* decent, although a little obscure, explanation from StackExchange:
     
     Static linking produces a larger executable file than dynamic linking because it has to compile all of the library code directly into the executable. The benefit is a reduction in overhead from no longer having to call functions from a library, and anywhere from somewhat to noticeably faster load times.
     
     A dynamically linked executable will be smaller because it places calls at runtime to shared code libraries. There are several benefits to this, but the ones important from a speed or optimization perspective are the reduction in the amount of disk space and memory consumed, and improved multitasking because of reduced total resource consumption (particularly in Windows).
     
     So it's a tradeoff: there are arguments to be made why either one might be marginally faster. It would depend on a lot of different things, such as to what extent speed-critical routines in the program relied on calls to library functions. But the important point to emphasize in the above statement is that it [statically linked executable] might be marginally faster. The speed difference will be nearly imperceptible, and difficult to distinguish even from normal, expected fluctuations
     */
    
    cout << "\n";
    return 0;
}


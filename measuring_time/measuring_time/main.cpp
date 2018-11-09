#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include <limits>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    time_t t_start = time(NULL);
    cout << "start time: " << t_start << endl;
    this_thread::sleep_for(chrono::seconds(0));
    this_thread::sleep_for(chrono::milliseconds(0));
    time_t t_end = time(NULL);
    cout << "end time: " << t_end << endl;
    double t_diff = difftime(t_end, t_start);
    cout << "difftime diff = " << t_diff << endl << endl;
    // #difftime(time_t end_time, time_t start_time)
    // seems to measure in seconds onl
    
    clock_t c_start = clock();
    cout << "c_start: " << c_start << endl;
    this_thread::sleep_for(chrono::seconds(1));
    this_thread::sleep_for(chrono::seconds(0));
    clock_t c_end = clock();
    cout << "c_end: " << c_end << endl;
    double c_diff = ((double)(c_end - c_start))/CLOCKS_PER_SEC;
    // CLOCKS_PER_SEC: The value of this macro is the number of clock ticks per second measured by the clock function
    cout << fixed << setprecision(std::numeric_limits<double>::max())<<  "clock_t subtraction diff = " << c_diff << endl << endl;
    
    c_start = clock();
    for (int i = 0; i < 1000; i++){
        for (int i = 0; i < 1000; i++){ }
    }
    c_end = clock();
    c_diff = ((double)(c_end-c_start))/CLOCKS_PER_SEC;
    cout << fixed << setprecision(std::numeric_limits<double>::max())<<  "clock_t subtraction diff = " << c_diff << endl << endl;
    // These clock times seem to become more meaningful dealing with this nested for loop than when using the sleep_for calls - maybe the clock is not 'ticking' during those calls.
    
    //cout << "std::numeric_limits<double>::max() = " << std::numeric_limits<double>::max() << endl << endl;
    // std::numeric_limits<int>::max() would be the largest possible value of an integer
    // several stackexchange posts use setprecision( std::numeric_limits<double>::max()+1 ), why?
    
    time_t t0 = time(NULL);
    struct tm *rawtime = localtime(&t0);
    fputs (asctime (rawtime), stdout);
    // char* asctime(const tm* time_ptr) converts given calendar time std::tm to a textual representation of the following fixed 25-character form: Www Mmm dd hh:mm:ss yyyy\n
    const int bufsize = 256;
    char buffer[bufsize];
    strftime (buffer, bufsize, "Today is %A, %B %d.\n", rawtime);
    fputs (buffer, stdout);
    strftime (buffer, bufsize, "The time is %I:%M %p.\n", rawtime);
    fputs (buffer, stdout);
    cout << "\n";
    
    /*
     struct tm {
     int tm_sec;   // seconds of minutes from 0 to 61
     int tm_min;   // minutes of hour from 0 to 59
     int tm_hour;  // hours of day from 0 to 24
     int tm_mday;  // day of month from 1 to 31
     int tm_mon;   // month of year from 0 to 11
     int tm_year;  // year since 1900
     int tm_wday;  // days since sunday
     int tm_yday;  // days since January 1st
     int tm_isdst; // hours of daylight savings time
     }
     */
    // So can call:
    cout << "hh-mm-ss: " << rawtime->tm_hour << ":" << rawtime->tm_min << ":" << rawtime->tm_sec << endl;
    this_thread::sleep_for(chrono::seconds(2));
    t0 = time(NULL);
    rawtime = localtime(&t0);
    cout << "hh-mm-ss: " << rawtime->tm_hour << ":" << rawtime->tm_min << ":" << rawtime->tm_sec << endl;
    // since the smallest unit is sec, as with dealing with #difftime, clock_t may be a better way to measure a difference in processing time.
    cout << "\n";
    
    // BEST WAY TO MEASURE EXECUTION TIME (so far)
    chrono::high_resolution_clock::time_point hrc_start = chrono::high_resolution_clock::now();
    this_thread::sleep_for(chrono::milliseconds(10));
    chrono::high_resolution_clock::time_point hrc_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>( hrc_end - hrc_start ).count();
    cout << "duration = " << duration << " microseconds";
    // keep in mind chrono::microseconds as well
    
    cout << "\n";
    return 0;
}

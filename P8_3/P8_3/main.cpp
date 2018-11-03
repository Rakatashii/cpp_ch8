/*
 Exercise P8.3.
 Derive a class Manager from Employee. Add a data field, named department, of type string. Supply a function print that prints the manager’s name, department, and salary. Derive a class Executive from Manager. Supply a function print that prints the string Executive, followed by the information stored in the Manager base object.
*/

#include <iostream>
#include <vector>
#include "executive.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<Manager*> m;
    m.push_back(new Manager("Dave Kaplan", "Finance", 108923));
    m.push_back(new Executive("Handsome Jack", "Coorporate", 23944838));
    m.push_back(new Manager("Dennis Reynolds", "Business Stuff", 23948));
    m.push_back(new Executive("Frank Reynolds", "Business Stuff", 538482));
    for (int i = 0; i < m.size(); i++){
        m[i]->display_fields();
    }
    cout << "\n";
    return 0;
}

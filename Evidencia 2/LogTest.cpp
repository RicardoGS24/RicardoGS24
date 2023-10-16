#include <iostream>
using namespace std;
#include "Log.h"

int main() {

    Log log1("2023", "Aug", "11", "13:59:18", "10.14.197.202", "SQL injection");
    Log log2("2023", "May", "04", "06:58:06", "10.14.1.21", "Load balancing issues");

    // 6601: Aug 31 2023 15:26:24 10.14.51.41 Broken authentication and session management
    // 6602: Aug 31 2023 18:53:59 10.14.50.152 Human error

    // cout << log1.keyFH << endl;
    // cout << log2.keyFH << endl;

    cout << log1.keyIP << endl;
    cout << log2.keyIP << endl;

    cout << log1.getIP() << endl;
    cout << log2.getIP() << endl;

    // long double x = 0.1234531;
    // long double y = 145.166887;
    // long double z = x+y;

    // cout << z << endl;

    // if (log1.keyFH > log2.keyFH) {
    //     cout << "Log 1 es menor a log 2" << endl;
    // } else {
    //     cout << "Log 1 es mayor o igual a log 2" << endl;
    // }

    cout << "--------------------" << endl;

    string s1 = "202308311526241014051041";
    string s2 = "202308311853591014050152";
    if (s1 > s2) {
        cout << "Log 1 es mayor a log 2" << endl;
    } else {
        cout << "Log 2 es mayor o igual a log 1" << endl;
    }
    
    // cout << log1.year << " " << log1.time << endl;
    // cout << log2.year << " " << log2.time << endl;

    return 0;
}
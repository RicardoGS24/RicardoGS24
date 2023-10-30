#include <iostream>
using namespace std;

#include "contadorIP.h"

int main()
{
    vector<contadorIP> list;
    list.push_back(contadorIP("10.14.05.0",4));
    list.push_back(contadorIP("10.14.05.20",4));

    list[0] > list [1] ? cout << "list[0]" << endl : cout << "list[1]" << endl;  

    return 0;
}

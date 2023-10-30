#include <iostream>
using namespace std;

int main()
{
    int x,total = 0;
    cin >> x;

    while (x>= 5){
        if (x >= 500){
            x -= 500;
            total += 1000;
        } else {
            x -= 5;
            total += 5;
        }
    }

    cout << total;
    return 0;
}

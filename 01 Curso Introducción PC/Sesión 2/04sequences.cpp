#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    string n;
    cin >> n;
    if(n.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    int left = 0;
    int right = 1;
    int largest = -100000000;
    int currentLargest = 1;
    while(right < n.size()){
        if(n[right-1] == n[right]){
            currentLargest = right - left + 1;
        } else{
            left = right;
            largest = max(largest, currentLargest);
            currentLargest = 1;
        }
        right++;
    }
    largest = max(largest, currentLargest);
    cout << largest << endl;
    return 0;
}
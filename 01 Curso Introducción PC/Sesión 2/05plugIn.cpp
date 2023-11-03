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
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    string n;
    cin >> n;
    unordered_map<char, int> map;
    for(int i = 0; i<n.size(); i++){
        if(map.find(n[i]) == map.end()){
            map[n[i]] = 1;
        } else {
            map[n[i]]++;
        }
    }

    for(int i = 0; i<n.size(); i++){
        if(map[n[i]] == 1){
            cout << n[i];
        }
    }
    
    return 0;
}
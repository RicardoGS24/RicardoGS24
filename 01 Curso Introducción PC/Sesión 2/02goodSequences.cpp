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
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    unordered_map<int, int> map;
    for(int i = 0; i<n; i++){
        if(map.find(v[i]) == map.end()){
            map[v[i]] = 1;
        } else {
            map[v[i]]++;
        }
    }
    int remove = 0;
    for(auto x : map){
        if(x.first < x.second){
            remove += x.second - x.first;
        } else if(x.first > x.second){
            remove += x.second;
        }
    }
    cout << remove << endl;
    return 0;
}
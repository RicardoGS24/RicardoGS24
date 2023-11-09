#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    long long moves = 0;
    for(int i = 1; i<n; i++){
        if(v[i] < v[i-1]){
            moves += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout << moves << endl;
    return 0;
}
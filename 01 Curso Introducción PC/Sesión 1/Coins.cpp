#include <iostream>
using namespace std;

// #include <bits/stdc++.h>

int main()
{
    int n; cin>>n;

    vector<int> coins;

    coins.push_back(n);

    for(int i= n-1;i>=2;i--){
        if(n%i == 0){
            coins.push_back(i);
            n = i;
        }
    }
    
    coins.push_back(1);

    for (int i : coins)
        cout << i << ' ';

    return 0;
}

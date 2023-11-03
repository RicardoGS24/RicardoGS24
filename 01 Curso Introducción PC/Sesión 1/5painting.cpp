#include <iostream>
using namespace std;

// #include <bits/stdc++.h>

int main() {
    int h,w,n;
    int ans = 0;
    cin>> h >> w >> n;
    
    // Funcion en c++
    int m = max(h,w);

    // Iterativa
    while (n > 0){
        n -= m;
        ans++;
    }

    // Formula
    //ans = ceil(n/m);

    // Formula
    // ans = min()

    cout << ans;

    return 0;
}

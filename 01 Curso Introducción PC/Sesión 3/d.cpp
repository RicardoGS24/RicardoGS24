#include <iostream>
using namespace std;

using ll = long long;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int lcmMultiple(vector<ll> v, int n) {
    int result = v[0];
    for (int i = 1; i < n; i++)
        result = lcm(result, v[i]);
    return result;
}

int main() {
    
    int t;
    cin >> t; 

    vector<ll> results;

    for(int i=0; i<t; i++){
        int n; cin >> n;
        vector<ll> divisors;
        for(int k=0;k<n;k++){
            ll d; cin >> d;
            divisors.push_back(d);
        }
        int x = sizeof(divisors) / sizeof(divisors[0]);
        int result = lcmMultiple(divisors, x);
        results.push_back(result);        
    }

    for(int i=0;i<results.size();i++){
        if (results[i] > 0) {
            cout << results[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// using ll = long long;

// int main()
// {
    // int t;
    // cin >> t; 

    // vector<ll> results;

    // for(int i=0; i<t; i++){
    //     int n; cin >> n;
    //     vector<ll> divisors;
    //     for(int k=0;k<n;k++){
    //         ll d; cin >> d;
    //         divisors.push_back(d);
    //     }

    //     // Encontrar mas grande el numero en el vector

    //     // Mientras no 
        

    // }
    
//     return 0;
// }

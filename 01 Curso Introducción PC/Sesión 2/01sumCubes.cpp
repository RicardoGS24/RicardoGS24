#include <iostream>
#include "stdc.h"

using namespace std;

//typedef long long ll;
//#define ll long long;
using ll = long long;

const ll max_base = 1e4; // 10^4

void precalculate(map<ll, ll>& map){
    for(ll i = 1; i < max_base; i++){
        mp[i*i*i]++;
    }
}

map<ll,ll> mp;
precalculate(mp);

// Tratar de hacerlo con busqueda binaria
// 1 <= 10^4
// mid -> a 

int main()
{
    ll t; cin >> t;

    while(t--){
        ll x; cin >> x;
        bool possible = false;

        for(ll a = 1; a < max_base; ){
            ll b = cbrt(x - a*a*a);

            if (b > 0 and b*b*b + a*a*a == x){
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;

    }

    return 0;
}

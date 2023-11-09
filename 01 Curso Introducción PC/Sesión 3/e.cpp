#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const ll MAX = 1000000;
bool prime[MAX + 1];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (ll p = 2; p * p <= MAX; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}

bool isPrime(long long number) {
    if (number < 2) return false;
    return prime[number];
}

int main()
{
    sieve();
    ll n, k;
    cin >> n >> k;
    if(isPrime(n) && k>2){
        cout << -1 << endl;
    } else if(isPrime(n) && k == 2){
        cout << n << endl;
    } else {
        ll divisors = 0;
        for(ll i = 1; i<n; i++){
            if(n%i == 0){
                divisors++;
            }
            if(divisors == k){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
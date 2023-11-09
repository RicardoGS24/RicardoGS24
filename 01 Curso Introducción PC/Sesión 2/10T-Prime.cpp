#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 1000000; // Maximum number to check for primes
bool prime[MAX + 1];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= MAX; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}

bool isTPrime(long long number) {
    if (number < 4) return false;
    long long squareRoot = static_cast<long long>(sqrt(number));
    return squareRoot * squareRoot == number && prime[squareRoot];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // Generate primes up to MAX

    int totalNumbers;
    cin >> totalNumbers;

    while (totalNumbers--) {
        long long number;
        cin >> number;
        cout << (isTPrime(number) ? "YES\n" : "NO\n");
    }

    return 0;
}


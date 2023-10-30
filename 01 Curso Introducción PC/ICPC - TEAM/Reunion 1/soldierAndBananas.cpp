#include <iostream>
using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int sum = 0;
    for(int i = 1; i<=w; i++)
    {
        sum += k*i;
    }
    sum -= n;
    sum > 0 ? cout << sum << endl : cout << 0 << endl;
    return 0;
}
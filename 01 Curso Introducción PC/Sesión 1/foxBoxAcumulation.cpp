#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> x(n);

    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x.begin(), x.end());

    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.top() <= x[i]) {
            x[i] = q.top() + 1;
            q.pop();
            q.push(x[i]);
        } else
            q.push(1);
    }

    cout << q.size() << endl;
}
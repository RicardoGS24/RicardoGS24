#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> tasks;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        tasks.push(x);
    }

    int time = 0;
    int posicion = 1;

    while (!tasks.empty()) {
        int task = tasks.front();
        tasks.pop();
        
        while (task != posicion) {
            time++;
            if (n == posicion) {
                posicion = 1;
            } else {
                posicion++;
            }
        }
    }

    cout << time;
    return 0;
}
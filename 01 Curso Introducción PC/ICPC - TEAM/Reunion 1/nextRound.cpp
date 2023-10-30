#include <iostream>
using namespace std;

#include <vector>

int main()
{
    int k, n, count=0;
    cin >> n >> k;
    vector<int> scores;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        scores.push_back(x);
    }

    for (int i=0;i<n;i++){
        if (scores[i] >= scores[k-1] && scores[i] > 0){
            count++;
        }
    }

    cout << count;
    return 0;
}

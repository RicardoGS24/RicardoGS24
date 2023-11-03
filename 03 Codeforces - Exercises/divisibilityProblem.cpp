#include <iostream>
using namespace std;

#include <vector>

int main()
{
    int t=0;
    cin >> t;

    vector<int> results;

    while(t--){
        int a,b,count=0;
        cin>> a >> b; 

        if (a%b != 0){
            count = ((((a/b)+1) * b) - a);
        }        
        results.push_back(count);
    }

    for(int l : results){
        cout << l << endl;
    }
    
    return 0;
}

// Primera operción
    // while (a%b != 0){
    //     //a += 1;
    //     //count++;
    //     if 

    // }
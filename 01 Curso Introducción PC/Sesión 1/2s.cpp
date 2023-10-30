#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, a, b, c;
    vector<string> listR;
    cin >> t;

    for (int i = 0; i < t;i++){
        cin >> a >> b >> c;

        if (a+b == c || a+c == b || b+c == a){
            listR.push_back("YES");
        } else {
            listR.push_back("NO");
        }
    }

    for(string l : listR){
        cout << l << endl;
    }
    
    return 0;
}

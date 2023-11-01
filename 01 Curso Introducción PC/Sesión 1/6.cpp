#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // Diferencia de --n a n--
    // --n : primero le resta uno y te da el valor
    
    while(n--){
        string s; cin >> s;
        if (s.size() > 10){
            int countInter = s.size()-2;
            cout << s[0] << countInter << s[s.size() - 1] << endl;
        } else {
            cout << s << endl;
        }
    }
    
    return 0;
}

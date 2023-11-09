#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    // string n;
    // cin >> n;
    // unordered_map<char, int> map;
    // for(int i = 0; i<n.size(); i++){
    //     if(map.find(n[i]) == map.end()){
    //         map[n[i]] = 1;
    //     } else {
    //         map[n[i]]++;
    //     }
    // }

    // for(int i = 0; i<n.size(); i++){
    //     if(map[n[i]] == 1){
    //         cout << n[i];
    //     }
    // }

    string n;
    cin >> n;
    string result;

    // Iterar sobre cada caracter
    for (char c : n) {
        // Verificar que el string result no está vacía y si el ultimo valor guardo
        // en el string result es igual al valor actual del string ingresado
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else { // Sino no se cumple los ultimos 2 valores no son los mismos
            result.push_back(c); 
        }
    }

    cout << result << endl;

    return 0;
}
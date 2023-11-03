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
#include <unordered_map>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        stack<char> stack;
        unordered_map<char, char> closeToOpen = {{')', '('}, {'}', '{'}, {']', '['}};
        if(s.size() % 2 != 0){
            cout << "NO" << endl;
            continue;
        }
        for(char c : s){
            if(closeToOpen.find(c) != closeToOpen.end()){
                if(!stack.empty() && stack.top() == closeToOpen[c]){
                    stack.pop();
                } else {
                    cout << "NO" << endl;
                    return 0;
                }
            } else {
                stack.push(c);
            }
        }

        if(stack.empty()){
            cout << "YES" << endl;  
        } else {
            cout << "NO" << endl;
        }   
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;


int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> vertices;
    stack<int> st;

    string s; 
    int v;

    cin >> s >> v;
    st.push(v);

    for(int i=0; i < n*2 - 1 ;i++){
        cin >> s >> v;
        
        if(s == "in"){
            //vertices.push_back(make_pair(st.top(), v));
            vertices.push_back({st.top(), v});
            st.push(v);
        } else {
            st.pop();
        }
    }

    for(auto i : vertices){
        cout << i.first << ' ' << i.second << endl;
    }
    
    return 0;
}

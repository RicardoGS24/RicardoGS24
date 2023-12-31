#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<char> list;

    cin >> s;

    for (int i = 0; i<s.size();i++){
        if (s[i] != '+'){
            list.push_back(s[i]);
        }
    }


    // 'l' -> codigo ASCII -> 49
    // for (auto c : s){
    //     if (c != '+'){
    //         list.push_back(c - '0');
    //     }
    // }

    //O (n log(n))
    //sort(begin(list),end(list));
    sort(list.begin(),list.end());

    for (int i = 0; i<list.size();i++){
        if (i == list.size()-1){
            cout<<list[i]<<endl;
        } else {
            cout<<list[i]<<"+";
        }
    }
     
    return 0;
}

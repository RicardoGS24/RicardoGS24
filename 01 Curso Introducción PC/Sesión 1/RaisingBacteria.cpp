#include <iostream>
using namespace std;

int main()
{
    int x,count=0;
    cin >> x;

    // while(x > 0){
    //     if (x%2 == 1){
    //         x -= 1;
    //         count++;
    //     }
    //
    //     x /= 2;
    // }
    
    // cout << count;
    
    // cout << __builtin_popcount(x);
    //
    // >>, recorrer un bit a la derecha
    // &, comparador AND

    while (x){
        if(x & 1)
            count++;
        
        x>>=1;
        //x = x >> 1;
    }
    cout << count;
    return 0;
}



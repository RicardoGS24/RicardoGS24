#include <iostream>
#include <vector>
using namespace std;

// Función iterativa
// De orden: O(n)
int returnImpar(vector <int> a){
    int suma = 0;
    for(int i =0; i<a.size(); i++){
        if (a[i] % 2 != 0){  
            suma += a[i];
        }
    }
    return suma;
}

// Función recursiva
// De orden: O(n)
int returnImparRecur(vector <int> a,int b){
    if (b < a.size()){
        if (a[b] % 2 != 0){
            return a[b] + returnImparRecur(a,b+1);
        }
        else{
            return returnImparRecur(a,b+1);
        }
    }
    return 0;
}

int main()
{
    vector <int> intVector = {1,2,3,4,5,6,7,8,9};
    // Suma iterativa
    cout << "La suma iterativa de números impares es: " << returnImpar(intVector) << endl;
    // Suma Recursiva
    cout << "La suma recursiva de números impares es: " << returnImparRecur(intVector,0) << endl;
    return 0;
}

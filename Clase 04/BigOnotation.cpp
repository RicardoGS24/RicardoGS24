#include <iostream>
#include <vector>
using namespace std;

// Función iterativa
int returnImpar(vector <int> a){
    int suma = 0;
    for(int i =0; i<a.size(); i++){ // O(n)
        if (a[i] % 2 != 0){  //
            suma += a[i];
        }
    }
    return suma;
}

int returnImparRecur(vector <int> a){
    int i = 0;
    if (a[0] % 2 != 0){
        return a[0] + returnImparRecur();
    }
    else{
        return returnImparRecur();
    }
}



int main()
{
    vector <int> intVector = {3,3,3,3,3};
    // Suma iterativa
    cout << "La suma de números impares es: " << returnImpar(intVector) << endl;

    return 0;
}

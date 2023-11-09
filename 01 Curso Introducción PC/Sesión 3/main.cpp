#include <iostream>
using namespace std;

// ------ Alias para definir un tipo de dato ------

// typedef long long ll; -> Sirve exclusivamente en tipos de datos.
// #define ll long long; -> Cambia las palabras a nivel del compilador. Cada que escribas ll será un long long
// #define hola 15;
using ll = long long;

const ll max_base = 1e4; // 10^4

// ------ TEORIAS DE NUMEROS ------

// ------- ARITMETICA MODULAR -----
// En c++ existe una función llamada POW
// pow(a,b) -> Trabaja con numeros flotantes
// Esto puede llevar a erros al intentar cambiar a entero por que c++ trunca los numeros
// 8.9999999 -> 8
// 9.0000001 -> 9

// Es de complejidad --> O(log2(n))
ll bineexp(ll base, ll potencia){
    if (potencia == 0){
        return 1;
    } else {
        ll root = bineexp(base, potencia/2);
        if (potencia % 2 == 0){
            return root * root;
        }
        return base * root * root;
    }
}

// OPERADOR MÓDULO
// a % b -> obtenemos el residuo de a entre b
// Un desbordamiento es cuando se exede el limite del rango según el tipo de dato
// 1. Identidad:
// (a % b) % b = a % b


// En Exponenciacion binaria

// Inverso multiplicativo

// ------- NUMEROS PRIMOS -----
// ¿Cómo averiguar si un numero es primo?
bool esPrimo(ll num){
    for(ll i = 2; i<num;i++){
        if(num % i == 0)
        return false;
    }
    return true;
}


// Criba de Eratóstenes (Sieve)
// Es un algoritmo que nos permite hallar todos los numeros primos de 1 a n
// 1.- Tomar el primer candidato a primo disponible > 1 y agregarlo a la lista de primos
// 2.- Eliminar los numeros devisibles entre el primo que agregamos a la lista

int n = 100;
bool criba[n+1];

// O(n*log(log(n)))
// for(int i = 0; i < 0; i++){
//     arr[i] = true;
// }
// Inicializar un vector:
// vector<bool> (n,false); // O(n)


int main()
{
    
    
    
    return 0;
}

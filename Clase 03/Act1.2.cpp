#include <iostream>
using namespace std;

// Función de suma iterativa
int sumIterative(int n) {
    int sum = 0;
    for (int i=1;i<=n;i++){
        sum = sum + i;
    }
    return sum;
}

// Función suma de recursión
int sumRecursion(int n) {
    //Condición de control
    if (n > 1){
        return n + sumRecursion(n-1);
    }
    else{
        return 1;
    }
}

// Función de Fórmula
int sumFormula(int n){
    return n * (n+1)/2;
}

// Suma Fibonacci Iterativa
int fibonacciIterative(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int f1 = 1;
        int f2 = 1;
        for (int i=3; i<=n; i++) {
            int aux = f2;
            f2 = f1 + f2;
            f1 = aux;
        }
        return f2;
    }
}

// Suma Fibonacci Recursiva
int fibonacciRecursive(int n) {
    if (n == 1 || n== 2) {
        return 1;
    } else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

// Suma bacterias Iterativa
int bacteriasIterative(int days) {
    int bacterias = 1;
    float rate = 1.44;
    for (int i=1; i<=days; i++) {
        bacterias = bacterias + bacterias * rate;
    }
    return bacterias;
}

// Suma bacterias Recursiva
int bacteriasRecursive(int days) {
    if (days>0) {
        int bacterias = bacteriasRecursive(days-1);
        float born = bacterias*1.44;
        return bacterias + born;
    } else {
        return 1;
    }
}

// Cálculo saldo de inversión Iterativa
float investmentIterative(float balance, int months) {
    float interestRate = 18.75;
    float newBalance = balance;
    for (int i=1; i<=months; i++) {
        // newBalance = newBalance + newBalance * interestRate / 100;
        newBalance = newBalance * ( 1 + interestRate / 100);
    }
    return newBalance;
}

// Cálculo saldo de inversión Recursiva
float investmentRecursive(float balance, int months) {
    if (months > 0) {
        return investmentRecursive(balance, months -1) * (1 + 18.75/100);
    } else {
        return balance;
    }
}

// Cálculo de potencia Iterativa
int powIterative(int n, int y) {
    if (n > 0 && y > 0) {
        int sum = n;
        for (int i=1; i<= y-1; i++){
            sum = sum*n;
        }
        return sum;
    }
    else {
        return 1;
    }
}

// Cálculo de potencia Recursiva
int powRecursive(int n, int y) {
    if (n > 0 && y > 0) {
        return n*powRecursive(n,y-1);
    }
    else {
        return 1;
    }
}

int main()
{
    // Suma iterativa
    int sum1 = sumIterative(5);
    cout << "La suma de 1 al 5 es: " << sum1 << endl;
    // Suma Recursiva
    int sum2 = sumRecursion(5);
    cout << "La suma de 1 al 5 es: " << sum2 << endl;
    // Suma con Fórmula
    int sum3 = sumFormula(5);
    cout << "La suma de 1 al 5 es: " << sum3 << endl;
    // Fibonacci Iterativo
    cout << "El número fibonacci de 10 es: " << fibonacciIterative(10) << endl;
    // Fibonacci Recursivo
    cout << "El número fibonacci de 10 es: " << fibonacciRecursive(10) << endl;
    // Bacterias iterativo
    cout << "El núnero de bacterias en 10 días es: " << bacteriasIterative(10) << endl;
    // Bacterias recursivo
    cout << "El núnero de bacterias en 10 días es: " << bacteriasRecursive(10) << endl;
    // Potencia iterativo
    cout << "El núnero 2 elevado a las 4 potencia es: " << powIterative(2,3) << endl;
    // Potencia recursivo
    cout << "El núnero 2 elevado a las 4 potencia es: " << powRecursive(2,3) << endl;

    return 0;
}

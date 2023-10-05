#include <iostream>
using namespace std;

#include "Stack.h"

int main(){
    Stack<int> pila;
    int option;

    while(option !=4){
        cout << "MENU DE OPERACIONES - Stack de tipo _INT_"  << endl;
        cout << "1) Borrar el ultimo elemento agregado al Stack" << endl; 
        cout << "2) Agregar un elemento al Stack" << endl;
        cout << "3) Consultar el ultimo elemento agregado al Stack" << endl;
        cout << "4) Salir" << endl;
        cout << "Elija una opción: "; cin >> option; cout << endl;

        while (option < 1 || option > 4){
            cout << "OPCION INVALIDA" << endl;
            cout << "1) Borrar el ultimo elemento agregado al Stack" << endl; 
            cout << "2) Agregar un elemento al Stack" << endl;
            cout << "3) Consultar el ultimo elemento agregado al Stack" << endl;
            cout << "4) Salir" << endl;
            cout << "Elija una opción: "; cin >> option; cout << endl;
        }

        if (option == 1){
            try {
                cout << "METODO POP" << endl;
                cout << "Pila anterior: "; pila.print();
                pila.pop();
                cout << "El ultimo elemento ha sido borrado" << endl; 
                cout << "Pila actual: "; pila.print();
                cout << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl << endl << endl;
            }
        } else if (option == 2){
            int n = 0;
            cout << "METODO PUSH" << endl;
            cout << "Ingresa el elemento: "; cin >> n;
            cout << "Pila anterior: "; pila.print();
            pila.push(n);
            cout << "Pila actual: "; pila.print();
            cout << endl;            
        } else if (option == 3){
            try {
                int aux;
                aux = pila.top();
                cout << "METODO TOP" << endl;
                cout << "El ultimo agregado elemento es: " << aux;
                cout << endl << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl << endl << endl;
            }
        }    
    }
    return 0;
}
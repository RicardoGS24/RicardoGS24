#include <iostream>
using namespace std;

#include "Queue.h"

int main() {
    Queue<int> fila;
    int option;

    while(option !=4){
        cout << "MENU DE OPERACIONES - Fila de tipo _INT_"  << endl;
        cout << "1) Borrar el primer elemento agregado al Queue" << endl; 
        cout << "2) Agregar un elemento al Queue" << endl;
        cout << "3) Consultar el primer elemento agregado al Queue" << endl;
        cout << "4) Salir" << endl;
        cout << "Elija una opción: "; cin >> option; cout << endl;

        while (option < 1 || option > 4){
            cout << "OPCION INVALIDA" << endl;
            cout << "1) Borrar el primer elemento agregado al Queue" << endl; 
            cout << "2) Agregar un elemento al Queue" << endl;
            cout << "3) Consultar el primer elemento agregado al Queue" << endl;
            cout << "4) Salir" << endl;
            cout << "Elija una opción: "; cin >> option; cout << endl;
        }

        if (option == 1){
            try {
                cout << "METODO POP" << endl;
                cout << "Lista anterior: "; fila.print();
                fila.pop();
                cout << "El primer elemento ha sido borrado" << endl; 
                cout << "Lista actual: "; fila.print();
                cout << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl << endl << endl;
            }
        } else if (option == 2){
            int n = 0;
            cout << "METODO PUSH" << endl;
            cout << "Ingresa el elemento: "; cin >> n;
            cout << "Lista anterior: "; fila.print();
            fila.push(n);
            cout << "Lista actual: "; fila.print();
            cout << endl;            
        } else if (option == 3){
            try {
                int aux;
                aux = fila.front();
                cout << "METODO FRONT" << endl;
                cout << "El primer elemento es: " << aux;
                cout << endl << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl << endl << endl;
            }
        } 
        
    }

    return 0;
}
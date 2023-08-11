#include <iostream>
#include <stdio.h>
#include <vector>
#include "Lista.h"

int main()
{
 
    Lista<int> intLista;
    intLista.insert(1);
    intLista.insert(2);

    // IMPRESIÓN DEL VECTOR
    intLista.print();

    //cout << "Cantidad de datos: " << intLista.getSize() << endl;
    //cout << "Elemento solicitado: " << intLista.getData(0) << endl;

    try {
    intLista.removeLast();
    intLista.removeLast();
    intLista.removeLast();
    } catch (out_of_range& e){
        cout << e.what() << endl;
    }

    intLista.print();

    // IMPRIMIR EL VALOR MAYOR
    //cout << "El valor máximo es: " << intLista.getMax() << endl;

    intLista.insert(5);
    intLista.insert(10);

    try {
        cout << "El valor de la posición 0 es: "<< intLista.getData(0) << endl;
        cout << "El valor de la posición 1 es: "<< intLista.getData(1) << endl;
        cout << "El valor de la posición 2 es: "<< intLista.getData(2) << endl;
        cout << "El valor de la posición 3 es: "<< intLista.getData(3) << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}

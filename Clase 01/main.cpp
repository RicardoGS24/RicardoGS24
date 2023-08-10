#include <iostream>
#include <stdio.h>
#include <vector>
#include "Lista.h"

int main()
{
 
    Lista<int> intLista;
    intLista.insert(1);
    intLista.insert(2);
    intLista.insert(3);
    intLista.insert(4);
    intLista.insert(5);

    cout << "Cantidad de datos: " << intLista.getSize() << endl;
    cout << "Elemento solicitado: " << intLista.getData(5) << endl;

    // IMPRESIÓN DEL VECTOR
    intLista.print();

    // IMPRESIÓN DEL VECTOR MODIFICADO
    intLista.removeLast();    
    intLista.print();

    // IMPRIMIR EL VALOR MAYOR
    cout << "El valor máximo es: " << intLista.getMax() << endl;

    return 0;
}

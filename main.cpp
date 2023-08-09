#include <iostream>
#include <stdio.h>
#include <vector>
#include "Lista.h"

int main()
{
    Lista<int> intLista;
    intLista.insert(15);
    intLista.insert(23);
    intLista.insert(50);
    intLista.insert(54);
    intLista.insert(56);
    intLista.print();

    Lista<string> stringLista;
    stringLista.insert("Ricardo");
    stringLista.print();
    intLista.printHello();

    system("pause");
    return 0;
}

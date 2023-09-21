#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<string> list;
    try {
        list.insert(2,"Vaso");
    } catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
    list.addLast("Cuchara");
    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    list.print();
    list.addLast("Cuchara");
    try {
        list.insert(2,"Vaso");
    } catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
    cout << "Tamaño de la list: " << list.getSize() << endl;
    list.print();

    return 0;
}

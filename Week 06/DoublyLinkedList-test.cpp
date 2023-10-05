#include <iostream>
using namespace std;
#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<string> list;

    // cout << list.findData("Cuchara") << endl;
    // try {
    //     list.insert(2,"Vaso");
    // } catch (out_of_range &e) {
    //     cout << e.what() << endl;
    // }
    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    list.addLast("Cuchara");
    list.print("a");
    list.addLast("Cuchara");
    list.print("a");

    // try {
    //     list.insert(2,"Vaso");
    // } catch (out_of_range &e) {
    //     cout << e.what() << endl;
    // }
    // cout << "Tamaño de la lista: " << list.getSize() << endl;
    // list.print();
    // cout << list.findData("Cuchar") << endl;
    // cout << list[1] << endl;
    // list[1] = "Tarro";
    // list.print();
    // list.deleteData("Plato");
    // list.print();
    // list.deleteData("Cuchara");
    // list.print();
    // list.deleteAt(0);
    // list.print();
    // list.deleteAt(2);
    // list.print();
    return 0;
}
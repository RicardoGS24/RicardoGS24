#include <iostream>
#include "Node.h"
using namespace std;

int main()
{
    // int a = 5;
    // int *p; // 1) p es una apuntador 2) El nombre del apuntador es p
    //         // 3) p es un apuntador que hace referencia a un valor entero
    
    // p = new int; // new int genera un espacio de memoria de tipo entero, en p se almacena la dirección de memoria asignada
    // *p = a;      // A la dirección de memoria almacenada en p le asigno el valor de la variable a
    // cout << "a: " << a << endl;
    // cout << "p: " << p << endl;     // Mostrará una dirección de memoria
    // cout << "&a: " << &a << endl;   // Dirección de memoria donde está almacenada la variable a
    // cout << "&p: " << &p << endl;   // Dirección de memoria donde está almacenada la variable p
    // cout << "*p: " << *p << endl;
    // a = *p + 2;
    // cout << "a: " << a << endl;
    
    // delete p;
    // cout << "*p: " << *p << endl;
    // cout << "&p: " << &p << endl;
    // a = *p + 4; 
    // cout << "a: " << a << endl;

    Node<int> node1;
    cout << node1.next << endl;
    int a = 5;
    int b = 10;
    Node<int> node2(a);
    cout << node2.data << " " << node2.next << endl;
    Node<int> node3(b, &node2);
    cout << node3.data << " " << node3.next;
    cout << " " << node3.next->data << endl; // "->" se usa para acceder al atributo del objeto tipo NODO


    return 0;
}

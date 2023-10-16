#include <iostream>
using namespace std;

#include "BST.h"

int main(){
    
    // Definir el arbol de busqueda binaria
    BST<int> tree;

    // Prueba de metodo INSERT
    tree.insert(21);
    tree.insert(13);
    tree.insert(33);
    tree.insert(10);
    tree.insert(18);
    tree.insert(25);
    tree.insert(40);

    // Prueba de metodo DELETE
    //tree.remove(10);
    //tree.remove(40);
    //tree.remove(13);


    // Prueba de metodo PRINT
    tree.print();
    cout << endl;

    // Prueba de metodo FIND
    //tree.find(25) ? cout << "Si" << endl : cout << "No" << endl;
    //cout << "El valor se encuantra (1-TRUE , 0-FALSE): " << tree.find(19) << endl;

    // Prueba de metodo VISIT
    // for (int i= 1; i<5;i++){
    //     tree.visit(i);
    //     cout << endl;
    // }

    // Prueba de metodo HEIGHT
    // cout << tree.getHeight() << endl;

    // Prueba de metodo ANCESTORS
    //tree.ancestors(23);
    //tree.ancestors(40);

    // Prueba de metodo WHAT_LEVEL_AM_I
    //cout << tree.whatLevelAmI(24) << endl;

    return 0;
}

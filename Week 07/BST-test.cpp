#include <iostream>
using namespace std;

#include "BST.h"

void start(){
    // Definir el arbol de busqueda binaria
    BST<int> tree;
    int option = 0;

    while (option != 9){
        int x = 0;

        cout << "----------- MENU PRINCIPAL - BST INT -----------" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Print" << endl;
        cout << "4) Find" << endl;
        cout << "5) Visit" << endl;
        cout << "6) Height" << endl;
        cout << "7) Ancestors" << endl;
        cout << "8) whatLevelAmI" << endl;
        cout << "9) Salir" << endl;
        cout << "Ingresa la opcion: "; cin >> option;
        cout << endl;

        while (option < 1 || option > 9){
            cout << endl << "----------- RESPUESTA NO VALIDA  -----------" << endl;
            cout << "-------------- MENU PRINCIPAL --------------" << endl;
            cout << "1) Insert" << endl;
            cout << "2) Delete" << endl;
            cout << "3) Print" << endl;
            cout << "4) Find" << endl;
            cout << "5) Visit" << endl;
            cout << "6) Height" << endl;
            cout << "7) Ancestors" << endl;
            cout << "8) whatLevelAmI" << endl;
            cout << "9) Salir" << endl;
            cout << "Ingresa la opcion: "; cin >> option;
            cout << endl;
        }

        if (option == 1){
            cout << "Inserta un dato nuevo en el BST." << endl;
            cout << "Ingresa el valor: "; cin >> x;
            cout << "El BST anterior:";
            tree.print();
            tree.insert(x);
            cout << "El BST actual:";
            tree.print();
        } else if (option == 2){
            cout << "Elimina un dato del BST." << endl;
            cout << "Ingresa el valor: "; cin >> x;
            cout << "El BST anterior:";
            tree.print();
            tree.remove(x);
            cout << "El BST actual:";
            tree.print();            
        } else if (option == 3){
            cout << "Imprime todos los nodos del BST." << endl;
            cout << "La BST actual es:";
            tree.print();
        } else if (option == 4){
            cout << "Encontrar un dato en el BST." << endl;
            cout << "Ingresa el valor: "; cin >> x;
            cout << "Se encuentra el " << x << "?  ";
            tree.find(x) ? cout << "Si" << endl << endl : cout << "No" << endl << endl;
        } else if (option == 5){
            cout << "Desplejar cada uno de los datos en el BST" << endl;
            cout << "1. Preorder" << endl;
            cout << "2. Inorder" << endl;
            cout << "3. Postorder" << endl;
            cout << "4. Level by level" << endl;
            cout << "Ingresa la opcion: "; cin >> x;
            tree.visit(x); cout << endl << endl;
        } else if (option == 6){
            cout << "Regresar la altura del BST." << endl;
            cout << "La altura es: " << tree.getHeight() << endl << endl;
        } else if (option == 7){
            cout << "Desplegar los ancestros del BST." << endl;
            cout << "Ingresa el dato: "; cin >> x;
            tree.ancestors(x); cout << endl << endl;
        } else if (option == 8){
            cout << "Nivel en el que se encuentra un dato." << endl;
            cout << "Ingresa el dato: "; cin >> x;
            cout << "El nivel es: " << tree.whatLevelAmI(x) << endl << endl;
        }
    }
}

int main(){

    start();

    return 0;
}

// JESUS RICARDO GUERRERO SILVESTRE
// A00835912

#include <iostream>
using namespace std;

#include "LinkedList.h"


// CREA UNA LISTA ALEATORIA DE ENTEROS
void createListInt(LinkedList<int> &list, int quantity){
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.addLast(num);
  }
}

// GENERA UN STRING DE CIERTA LONGITUD
string generarStringAleatorio(int longitud) {
    string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string resultado;
    for (int i = 0; i < longitud; i++) {
        int indiceAleatorio = rand() % caracteres.length();
        resultado += caracteres[indiceAleatorio];
    }
    return resultado;
}

// CREA UNA LISTA ALEATORIA DE PALABRAS
void createListString(LinkedList<string> &list,int quantity,int longitud){
    for (int i = 0; i < quantity; i++) {
        string nuevoString = generarStringAleatorio(longitud);
        list.addLast(nuevoString);
    }
}

// --------------------------------------------
// -----------------------------------------------------------------------------------------
// --------------------------------------------

// MENU PARA CREAR LA LISTA DE TIPO INT
LinkedList<int> capturarDatosListInt(){
    int n = 0;
    LinkedList<int> listInt;
    cout << "Selecciona una opcion" << endl;
    cout << "1) Lista con datos aleatorios" << endl;
    cout << "2) Lista con datos capturados" << endl;
    cout << "Ingresa la opcion: ";
    cin >> n; cout << endl;

    while (n != 1 && n != 2){
        cout <<"OPCION NO VALIDA"<< endl << endl;
        cout << "Selecciona una opcion" << endl;
        cout << "1) Lista con datos aleatorios" << endl;
        cout << "2) Lista con datos capturados" << endl;
        cin >> n; cout << endl;
    }
           
    if (n == 1) {
        int x = 0;
        cout << "Datos Aleatorios"; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;
        createListInt(listInt,x);
        return listInt;
    } else if (n == 2) {
        int x = 0, n = 0;
        cout << "Datos Capturados"; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento" << i << " : ";
           cin >> n; 
           listInt.addLast(n);
        }
        return listInt;
    }
    throw out_of_range("ERROR");
}

// MENU PARA CREAR LA LISTA DE TIPO STRING
LinkedList<string> capturarDatosListString(){
    int n = 0;
    LinkedList<string> listString;

    cout << "Selecciona una opcion" << endl;
    cout << "1) Lista con datos aleatorios" << endl;
    cout << "2) Lista con datos capturados" << endl;
    cin >> n; cout << endl;


    while (n == 1 || n == 2){
        cout <<"OPCION NO VALIDA"<< endl << endl;
        cout << "Selecciona una opcion" << endl;
        cout << "1) Lista con datos aleatorios" << endl;
        cout << "2) Lista con datos capturados" << endl;
        cin >> n; cout << endl;
    }

    if (n == 1) {
        int x = 0,longString = 0;
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x; cout << endl;
        cout << "Ingresa el numero de caracteres en cada string: "; 
        cin >> longString; cout << endl;
        createListString(listString,x,longString);
        return listString;
    } else if (n == 2) {
        int x = 0;
        string n = 0;
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x; cout << endl;                
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento" << i << " : ";
           cin >> n; 
           listString.addLast(n);
        }
    }
    throw out_of_range("ERROR");
}

// // MENU GENERAL PARA CREAR LISTA
// template <class T>
// void menuCreacionLista(LinkedList<T> &list){
//     int option = 0;
//     cout << "CREAR UNA LISTA" << endl;
//     cout << "1) Lista de enteros" << endl;
//     cout << "2) Lista de strings" << endl;
//     cout << "3) Salir" << endl;  
//     cin >> option;

//     while (option != 3){
//         if (option == 1){
//             LinkedList<int> listInt;
//             try {
//                 listInt = capturarDatosListInt();
//                 list = listInt;
//             } catch(out_of_range &e)
//             {
//                 cout << e.what() << endl;
//             }

//         } else if (option == 2){
//             LinkedList<string> listString;
//             try {
//                 listString = capturarDatosListString();
//                 list = listString;
//             } catch(out_of_range &e)
//             {
//                 cout << e.what() << endl;
//             }
//         }
//     }
// }

// --------------------------------------------
// -----------------------------------------------------------------------------------------
// --------------------------------------------

template <class T>
void menuOperaciones(LinkedList<T> &list){
    return;
}

// --------------------------------------------
// -----------------------------------------------------------------------------------------
// --------------------------------------------


void start(){
    int option = 0;
    LinkedList<int> listInt;
    LinkedList<string> listString;

    while (option != 3){
        cout << "MENÚ PRINCIPAL" << endl;
        cout << "1) Crear una lista _INT_" << endl;
        cout << "2) Crear una lista _STRING_" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa la opcion: ";
        cin >> option; cout << endl;

        while (option != 1 && option != 2 && option != 3){
            cout <<"OPCION NO VALIDA"<< endl << endl;
            cout << "Selecciona una opcion" << endl;
            cout << "1) Crear una lista _INT_" << endl;
            cout << "2) Crear una lista _STRING_" << endl;
            cout << "3) Salir" << endl;
            cout << "Ingresa la opcion: ";
            cin >> option; cout << endl;
        }   

        if(option == 1){
            try {
                listInt = capturarDatosListInt();
                cout << "La lista es: ";
                listInt.print(); cout << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 2){
            try {
                listString = capturarDatosListString();
                listString.print(); cout << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        }

    }
}

int main()
{
    start();

    // LinkedList<string> list;    
    // list.addLast("Cuchara");
    // list.addFirst("Olla");
    // list.addFirst("Estufa");
    // list.addFirst("Jarra");
    // list.addFirst("Plato");
    // list.addLast("Cuchara");
    // list.print();

    // TEST PARA OBTENER EL TAMAÑO DE LA LISTA
    // cout << "Tamaño de la list: " << list.getSize() << endl;
    // list.print();


    // TEST PARA INSERTAR UN NUEVO ELEMENTO
    // try {
    // list.deleteAt(0);
    //     list.insert(2,"Vaso");
    // } catch(out_of_range &e)
    // {
    //     cout << e.what() << endl;
    // }

    // TEST PARA ELIMINAR ELEMENTOS
    // list.deleteData("Plato");
    // list.print();
    // list.print();
    
    // TEST PARA OBTENER UN DATO EN CIERTA INDEX
    //cout << list.getData(0) << endl;
    //     //list.updateData("Tenedor","Plato");

    // TEST PARA CAMBIAR UN DATO POR SU DATO
    // try {
    //     list.updateData("Plato","Tenedor");        
    //     list.print();
    // } catch(out_of_range &e)
    // {
    //     cout << e.what() << endl;
    // }

    // TEST PARA CAMBIAR UN DATO POR SU INDICE
    // try {
    //     list.updateAt(1,"Tenedor");        
    //     list.updateAt(0,"Tenedor");        
    //     list.print();
    // } catch(out_of_range &e)
    // {
    //     cout << e.what() << endl;
    // }

    // TEST PARA ENCONTRAR EL INDICE DE UNA DATO
    // cout << "El índice de Olla es: " << list.findData("Olla") << endl; 
    // } catch(out_of_range &e)

    // TEST PARA LA SOBRECARGA DEL OPERADOR "[]"
    // try {
    //     cout << list[2] << endl;
    //     list[2] = "Richar";
    //     list.print();
    // {
    //     cout << e.what() << endl;
    // }

    // TEST PARA LA SOBRECARGA DEL OPERADOR "="
    // LinkedList<string> list2;

    // list2.addFirst("Jarra");    
    // list2.addFirst("Plato");
    // list2.addFirst("Taza");
    // list2.print();
    // list = list2;
    // list.print();


    return 0;
}
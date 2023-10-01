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
        cout << "Datos Aleatorios" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;
        createListInt(listInt,x);
        return listInt;
    } else if (n == 2) {
        int x = 0, n = 0;
        cout << "Datos Capturados" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento " << i << " : ";
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
        int x = 0,longString = 0;
        cout << "Datos Aleatorios" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;
        cout << "Ingresa el numero de caracteres en cada string: "; 
        cin >> longString;
        createListString(listString,x,longString);
        return listString;
    } else if (n == 2) {
        int x = 0;
        string n;
        cout << "Datos Capturados" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;               
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento " << i << " : ";
           cin >> n; 
           listString.addLast(n);
        }
        return listString;
    }
    throw out_of_range("ERROR");
}

// --------------------------------------------
// -----------------------------------------------------------------------------------------
// --------------------------------------------

template <class T>
void menuOperaciones(LinkedList<T> &list){
    int option = 0;
    
    while (option != 14){
        T data;
        int index = 0;
        cout << "OPERACIONES EN LA LISTA" << endl;
        cout << "1) Agregar un elemento al principio de la lista" << endl;
        cout << "2) Agregar un elemento al final de la lista" << endl;
        cout << "3) Insertar un elemento después del índice dado" << endl;
        cout << "4) Borrar un elemento dado de la lista" << endl;
        cout << "5) Borrar un elemento en una posición de la lista" << endl;
        cout << "6) Obtener el elemento de una posición dada de la lista" << endl;
        cout << "7) Actualizar un elemento dado de la lista" << endl;
        cout << "8) Actualizar un elemento que se encuentra en una posición dada de la lista" << endl;
        cout << "9) Encuentra un elemento dado en la lista" << endl;
        cout << "10) Obtener el elemento de una posición de la lista" << endl;
        cout << "11) Actualizar el elemento de una posición de la lista" << endl;
        cout << "12) Iguala una lista con los datos de otra lista" << endl;
        cout << "13) Imprimir la lista" << endl;
        cout << "14) Salir" << endl;
        cout << "Ingresa la opcion: "; 
        cin >> option; cout << endl;

        while (option < 1 || option > 14) {
            cout <<"OPCION NO VALIDA"<< endl;
            cout << "Selecciona una opcion válida" << endl;
            cout << "1) Agregar un elemento al principio de la lista" << endl;
            cout << "2) Agregar un elemento al final de la lista" << endl;
            cout << "3) Insertar un elemento después del índice dado" << endl;
            cout << "4) Borrar un elemento dado de la lista" << endl;
            cout << "5) Borrar un elemento en una posición de la lista" << endl;
            cout << "6) Obtener el elemento de una posición dada de la lista" << endl;
            cout << "7) Actualizar un elemento dado de la lista" << endl;
            cout << "8) Actualizar un elemento que se encuentra en una posición dada de la lista" << endl;
            cout << "9) Encuentra un elemento dado en la lista" << endl;
            cout << "10) Obtener el elemento de una posición de la lista" << endl;
            cout << "11) Actualizar el elemento de una posición de la lista" << endl;
            cout << "12) Iguala una lista con los datos de otra lista" << endl;
            cout << "13) Imprimir la lista" << endl;
            cout << "14) Salir" << endl;
            cout << "Ingresa la opcion: "; 
            cin >> option; cout << endl << endl;        
        }

        if (option == 1){
            cout << "Agregar elemento al principio" << endl;
            cout << "Ingresa el elemento: ";
            cin >> data; cout << endl;
            list.addFirst(data);
        } else if (option == 2){
            cout << "Agregar elemento al final" << endl;
            cout << "Ingresa el elemento: ";
            cin >> data; cout << endl;
            list.addLast(data);
        } else if (option == 3){
            cout << "Insertar elemento por el indice" << endl;
            cout << "Ingresa el elemento: ";        
            cin >> data;
            cout << "Ingresa el indice: ";
            cin >> index; cout << endl;
            try {
                list.insert(index,data);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 4){
            cout << "Borrar un elemento de la lista" << endl;
            cout << "Ingresa el elemento: ";        
            cin >> data; cout << endl;
            list.deleteData(data);
        } else if (option == 5){
            cout << "Borrar un elemento de la lista por su indice" << endl;
            cout << "Ingresa el indice: "; cin >> index; cout << endl;
            list.deleteAt(index);
        } else if (option == 6){
            cout << "Obtener un elemento de la lista por su indice" << endl;
            cout << "Ingresa el indice: "; cin >> index;
            cout << "El elemento es: " << list.getData(index) << endl << endl;
        } else if (option == 7){ // ------------------ ARREGLAR ----------------
            T data1; 
            T data2;
            cout << "Actualizar un elemento dado de la lista" << endl;
            cout << "Ingresa el elemento existente: "; cin >> data1;
            cout << "Ingresa el nuevo elemento: "; cin >> data1;
            try {
                list.updateData(data1,data2);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 8){
            cout << "Actualizar un elemento de la lista según su indice" << endl;
            cout << "Ingresa el indice: "; cin >> index;
            cout << "Ingresa el nuevo elemento: "; cin >> data;
            try {
                list.updateAt(index,data);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl << endl;
            }
        } else if (option == 9){
            cout << "Encontrar un elemento de la lista" << endl;
            cout << "Ingresa el elemento existente: "; cin >> data;
            index = list.findData(data);
            cout << "El index del elemento es: " << index << endl << endl;
        } else if (option == 10){
            cout << "Obtener el elemento de una posición de la lista" << endl;
            cout << "Ingresa el índice del elemento: "; cin >> index;
            cout << "El elemento es: " << list[index] << endl << endl;
        } else if (option == 11){
            cout << "Actualizar el elemento de una posición de la lista" << endl;
            cout << "Ingresa el índice del elemento: "; cin >> index;
            cout << "Ingresa el nuevo elemento: "; cin >> data;
            // Sobrecarga del operador []
            list[index] = data;
            cout << endl;
        } // else if (option == 12){ ------------------------------------- ARREGLAR
        //     int oS = 0;
        //     LinkedList<int> listInt2;
        //     LinkedList<string> listString2;
            
        //     cout << "Igualar una lista con los datos de otra" << endl;
        //     cout << "Elige el tipo de la nueva lista" << endl;
        //     cout << "1) INT" << endl;
        //     cout << "2) STRING"<< endl; 
        //     cout << "Ingresa la opcion: "; cin >> oS; cout << endl;

        //     if (oS == 1 && list){
        //         listInt2 = capturarDatosListInt();
        //         cout << "La lista original es: ";
        //         list.print(); cout << endl;
        //         cout << "La segundo lista es: ";
        //         listInt2.print(); cout << endl;
        //         // Sobrecarga del operador =
        //         list = listInt2;   
        //     } else if (oS == 2){
        //         listString2 = capturarDatosListString();
        //         cout << "La lista original es: ";
        //         list.print(); cout << endl;
        //         cout << "La segundo lista es: ";
        //         listString2.print(); cout << endl;
        //         // Sobrecarga del operador =
        //         list = listString2;   
        //     }

        //     cout << "La nueva lista es: ";
        //     list.print(); cout << endl;

        // } 
        else if (option == 13){
            cout << "La lista es: ";
            list.print(); cout << endl << endl;
        }
    }
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
                // Obtener los datos de la lista
                listInt = capturarDatosListInt();
                cout << "La lista es: ";
                listInt.print(); cout << endl;
                // Realizar operaciones en la lista
                menuOperaciones(listInt);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 2){
            try {
                // Obtener los datos de la lista
                listString = capturarDatosListString();
                cout << "La lista es: ";
                listString.print(); cout << endl;
                // Realizar operaciones en la lista
                menuOperaciones(listString);
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

    return 0;
}
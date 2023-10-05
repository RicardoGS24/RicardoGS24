#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"


// --------------------------------------------
// ---------------- CREAR LISTAS --------------
// --------------------------------------------

// CREA UNA LISTA ALEATORIA DE LETRAS
void createListChar(DoublyLinkedList<char> &list,int quantity){
    for (int i = 0; i < quantity; i++) {
        int numeroAleatorio = rand() % 26;
        char letraAleatoria = 'a' + numeroAleatorio;
        list.addLast(letraAleatoria);
    }
}

// CREA UNA LISTA ALEATORIA DE ENTEROS
void createListInt(DoublyLinkedList<int> &list, int quantity){
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
void createListString(DoublyLinkedList<string> &list,int quantity,int longitud){
    for (int i = 0; i < quantity; i++) {
        string nuevoString = generarStringAleatorio(longitud);
        list.addLast(nuevoString);
    }
}

// CREA UNA LISTA ALEATORIA DE BOOLEANOS
void createListBoolean(DoublyLinkedList<bool> &list, int quantity) {
    for (int i = 0; i < quantity; i++) {
        bool valorAleatorio = rand() % 2 == 0;
        list.addLast(valorAleatorio);
    }
}

// CREA UNA LISTA ALEATORIA DE FLOAT
void createListFloat(DoublyLinkedList<float> &list, int quantity, float max, float min){
    for (int i = 0; i < quantity; i++) {
        int randNum = rand();
        float valorAleatorio = min + static_cast<float>(randNum) / RAND_MAX * (max - min);
        list.addLast(valorAleatorio);
    }
}

// --------------------------------------------
// -------------- MENUS PARA LISTAS -----------
// --------------------------------------------

// MENU PARA CREAR LA LISTA DE TIPO INT
DoublyLinkedList<int> capturarDatosListInt(){
    int n = 0;
    DoublyLinkedList<int> listInt;
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
DoublyLinkedList<string> capturarDatosListString(){
    int n = 0;
    DoublyLinkedList<string> listString;
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

// MENU PARA CREAR LA LISTA DE TIPO CHAR
DoublyLinkedList<char> capturarDatosListChar(){
    int n = 0;
    DoublyLinkedList<char> listChar;
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
        createListChar(listChar,x);
        return listChar;
    } else if (n == 2) {
        int x = 0;
        char optionChar;
        cout << "Datos Capturados" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento " << i << " : ";
           cin >> optionChar; 
           listChar.addLast(optionChar);
        }
        return listChar;
    }
    throw out_of_range("ERROR");
}

// MENU PARA CREAR LA LISTA DE TIPO BOOL
DoublyLinkedList<bool> capturarDatosListBool(){
    int n = 0;
    DoublyLinkedList<bool> listBool;
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
        createListBoolean(listBool,x);
        return listBool;
    } else if (n == 2) {
        int x = 0, n = 0;
        cout << "Datos Capturados" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento " << i << " : ";
           cin >> n; 
           listBool.addLast(n);
        }
        return listBool;
    }
    throw out_of_range("ERROR");
}

// MENU PARA CREAR LA LISTA DE TIPO FLOAT
DoublyLinkedList<float> capturarDatosListFloat(){
    int n = 0;
    DoublyLinkedList<float> listFloat;
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
        float max, min;
        cout << "Datos Aleatorios" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; cin >> x;
        cout << "Ingresa el valor maximo para la lista (Ej. 1.5): "; cin >> max;
        cout << "Ingresa el valor minimo para la lista (Ej. 0.2): "; 
        cin >> min; cout << endl;

        while (min > max){
            cout << "OPCION NO VALIDA --- Maximo debe ser mayor a Minimo" << endl << endl;
            cout << "Datos Aleatorios" << endl; 
            cout << "Ingresa la cantidad de elemetos: "; cin >> x;
            cout << "Ingresa el valor maximo para la lista (Ej. 1.5): "; cin >> max;
            cout << "Ingresa el valor minimo para la lista (Ej. 0.2): "; 
            cin >> min; cout << endl;
        }

        createListFloat(listFloat,x,max,min);
        return listFloat;
    } else if (n == 2) {
        int x = 0;
        float optionN;
        cout << "Datos Capturados" << endl; 
        cout << "Ingresa la cantidad de elemetos: "; 
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Ingresa el elemento " << i << " (Ej. 23.739): ";
           cin >> optionN; 
           listFloat.addLast(optionN);
        }
        return listFloat;
    }
    throw out_of_range("ERROR");
}

// --------------------------------------------
// ----------- MENU PARA OPERACIONES ----------
// --------------------------------------------

template <class T>
void menuOperaciones(DoublyLinkedList<T> &list){
    int option = 0;
    
    while (option != 19){
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
        cout << "13) Limpiar la lista" << endl;
        cout << "14) Ordena la lista" << endl;
        cout << "15) Duplica la lista" << endl;
        cout << "16) Remueve los elementos duplicados" << endl;
        cout << "17) Imprimir la lista - Ascendente" << endl;
        cout << "18) Imprimir la lista - Descendente" << endl;
        cout << "19) Salir" << endl;
        cout << "Ingresa la opcion: "; 
        cin >> option; cout << endl;

        while (option < 1 || option > 19) {
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
            cout << "13) Limpiar la lista" << endl;
            cout << "14) Ordenar la lista" << endl;
            cout << "15) Duplicar la lista" << endl;
            cout << "16) Remueve los elementos duplicados" << endl;
            cout << "17) Imprimir la lista - Ascendente" << endl;
            cout << "18) Imprimir la lista - Descendente" << endl;
            cout << "19) Salir" << endl;
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
            cout << "Ingresa el indice: ";
            cin >> index;
            cout << "Ingresa el elemento: ";        
            cin >> data; cout << endl;
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
            //int indexUsario = 0;
            cout << "Obtener el elemento de una posición dada de la lista" << endl;
            cout << "Ingresa el indice: "; cin >> index;
            try {
                cout << "El elemento es: " << list.getData(index) << endl << endl;
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 7){
            T d1;
            T d2;
            cout << "Actualizar un elemento dado de la lista" << endl;
            cout << "Ingresa el elemento existente: "; cin >> d1;
            cout << "Ingresa el nuevo elemento: "; 
            cin >> d2; cout << endl;
            try {
                list.updateData(d1,d2);
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
                cout << endl << endl;
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
        } else if (option == 12){
            int x = 0;
            T n;
            DoublyLinkedList<T> list2;
            cout << "Igualar una lista con los datos de otra" << endl;
            cout << "¡¡¡ADVERTENCIA!!! Agrega elementos del mismo tipo que la lista" << endl;
            cout << "Datos Capturados - Nueva lista" << endl; 
            cout << "Ingresa la cantidad de elemetos: "; cin >> x;               

            for (int i = 0; i<x ; i++){
                cout << "Ingresa el elemento " << i << " : ";
                cin >> n; 
                list2.addLast(n);
            }
            
            cout << "La lista original es: ";
            list.print("asc");
            cout << "La segunda lista es: ";
            list2.print("asc");
            // Sobrecarga del operador =
            list = list2; 
            cout << "--- list = list2 ---" << endl;
            cout << "La nueva lista es: ";
            list.print("asc"); cout << endl;
        } else if (option == 13){
            cout << "Limpiar la lista" << endl;
            cout << "Lista anterior: ";
            list.print("asc");
            list.clear();
            cout << "Lista actual: ";
            list.print("asc");
            cout << endl << endl;            
        } else if (option == 14){
            cout << "Ordenar la lista" << endl;
            cout << "Lista anterior: ";
            list.print("asc");
            list.sort();
            cout << "Lista actual: ";
            list.print("asc");
            cout << endl << endl;
        } else if (option == 15){
            cout << "Duplicar la lista" << endl;
            cout << "Lista anterior: ";
            list.print("asc");
            list.duplicate(); 
            cout << "Lista actual: ";
            list.print("asc");
            cout << endl << endl;            
        } else if (option == 16){
            cout << "Remover los elementos duplicados" << endl;
            cout << "Lista anterior: ";
            list.print("asc");
            //list.sort();
            list.removeDuplicates(); 
            cout << "Lista actual: ";
            list.print("asc");
            cout << endl << endl;
        } else if (option == 17){
            cout << "La lista de forma ascendente: ";
            list.print("asc"); cout << endl << endl;
        } else if (option == 18){
            cout << "La lista de forma descendente: ";
            list.print("des"); cout << endl << endl;
        }
    }
}

// --------------------------------------------
// -------------- MENUS PRINCIPAL -------------
// --------------------------------------------

void start(){
    int option = 0;
    DoublyLinkedList<int> listInt;
    DoublyLinkedList<string> listString;
    DoublyLinkedList<char> listChar;
    DoublyLinkedList<bool> listBool;
    DoublyLinkedList<float> listFloat;

    while (option != 6){
        cout << "MENÚ PRINCIPAL" << endl;
        cout << "1) Crear una lista _INT_" << endl;
        cout << "2) Crear una lista _STRING_" << endl;
        cout << "3) Crear una lista _CHAR_" << endl;
        cout << "4) Crear una lista _BOOL_" << endl;
        cout << "5) Crear una lista _FLOAT_" << endl;
        cout << "6) Salir" << endl;
        cout << "Ingresa la opcion: ";
        cin >> option; cout << endl;

        while (option < 1 || option > 6){
            cout <<"OPCION NO VALIDA"<< endl << endl;
            cout << "Selecciona una opcion" << endl;
            cout << "1) Crear una lista _INT_" << endl;
            cout << "2) Crear una lista _STRING_" << endl;
            cout << "3) Crear una lista _CHAR_" << endl;
            cout << "4) Crear una lista _BOOL_" << endl;
            cout << "5) Crear una lista _FLOAT_" << endl;
            cout << "6) Salir" << endl;
            cout << "Ingresa la opcion: ";
            cin >> option; cout << endl;
        }   

        if(option == 1){
            try {
                listInt = capturarDatosListInt();
                cout << "La lista es: ";
                listInt.print("asc"); cout << endl;
                menuOperaciones(listInt);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 2){
            try {
                listString = capturarDatosListString();
                cout << "La lista es: ";
                listString.print("asc"); cout << endl;
                menuOperaciones(listString);
            } catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 3){
            try {
                listChar = capturarDatosListChar();
                cout << "La lista es: ";
                listChar.print("asc"); cout << endl;
                menuOperaciones(listChar);
            }  catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 4){
            try {
                listBool = capturarDatosListBool();
                cout << "La lista es: ";
                listBool.print("asc"); cout << endl;
                menuOperaciones(listBool);
            }  catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        } else if (option == 5){
            try {
                listFloat = capturarDatosListFloat();
                cout << "La lista es: ";
                listFloat.print("asc"); cout << endl;
                menuOperaciones(listFloat);
            }  catch(out_of_range &e)
            {
                cout << e.what() << endl;
            }
        }
    }
}


int main() {
        
    srand(time(0));
    start();

    return 0;
}
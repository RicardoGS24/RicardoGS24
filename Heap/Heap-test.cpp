#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Heap.h"
#include "MinHeap.h"

// CREA UNA LISTA ALEATORIA DE ENTEROS
void createListInt(vector<int> &list, int quantity){
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

// FUNCIÓN PARA IMPRIMIR UN VECTOR
template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

// ALGORITMO DE ORDENAMIENTO HEAP SORT
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "des") {
        Heap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    } else if (order == "asc") {
        MinHeap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    }
}


// MENU PRINCIPAL
void start(){
    vector<int> listInt;
    createListInt(listInt,20);

    Heap<int> listMax;
    MinHeap<int> listMin;
    int opcionHeap = 0;

    cout << "------- VALORES INICIALES PARA CADA HEAP -------" << endl;
    print(listInt); cout << endl;

    // Elegir el tipo de Heap
    while (opcionHeap != 3){
        int x = 0;
        cout << "----------- MENU PRINCIPAL - HEAP INT -----------" << endl;
        cout << "1) Max Heap" << endl;
        cout << "2) Min Heap" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa la opcion: "; cin >> opcionHeap;
        cout << endl;

        while (opcionHeap < 1 || opcionHeap > 3){
            cout << endl << "----------- RESPUESTA NO VALIDA  -----------" << endl;
            cout << "-------------- MENU PRINCIPAL --------------" << endl;
            cout << "1) Max Heap" << endl;
            cout << "2) Min Heap" << endl;
            cout << "3) Salir" << endl;
            cout << "Ingresa la opcion: "; cin >> opcionHeap;
            cout << endl;

        }

        // MAX HEAP
        if (opcionHeap == 1) {
            int option = 0;
            listMax = listInt;

            while (option != 8){
                int x = 0;

                cout << "----------- MENU PRINCIPAL - HEAP INT -----------" << endl;
                cout << "1) Push" << endl;
                cout << "2) Pop" << endl;
                cout << "3) Top" << endl;
                cout << "4) Empty" << endl;
                cout << "5) Size" << endl;
                cout << "6) HeapSort" << endl;
                cout << "7) Print" << endl;
                cout << "8) Salir" << endl;
                cout << "Ingresa la opcion: "; cin >> option;
                cout << endl;

                while (option < 1 || option > 8){
                    cout << endl << "----------- RESPUESTA NO VALIDA  -----------" << endl;
                    cout << "-------------- MENU PRINCIPAL --------------" << endl;
                    cout << "1) Push" << endl;
                    cout << "2) Pop" << endl;
                    cout << "3) Top" << endl;
                    cout << "4) Empty" << endl;
                    cout << "5) Size" << endl;
                    cout << "6) HeapSort" << endl;
                    cout << "7) Print" << endl;
                    cout << "8) Salir" << endl;
                    cout << "Ingresa la opcion: "; cin >> option;
                    cout << endl;
                }

                if (option == 1){
                    cout << "PUSH - Agrega un dato a la fila priorizada." << endl;
                    cout << "Ingresa el valor: "; cin >> x;
                    listMax.push(x);
                    cout << endl << endl;
                } else if (option == 2){
                    cout << "POP - Saca de la fila priorizada el dato que tiene mayor prioridad." << endl;
                    listMax.pop();
                    cout << endl << endl;
                } else if (option == 3){
                    cout << "TOP - Regresa el valor del dato que está con mayor prioridad en la fila priorizada." << endl;
                    cout << listMax.top() << endl << endl;
                } else if (option == 4){
                    cout << "EMPTY - Regresa un valor boleando diciendo si la fila priorizada está vacía o tiene datos." << endl;
                    cout << "Se encuentra vacía?  ";
                    listMax.isEmpty() ? cout << "Si" << endl << endl : cout << "No" << endl << endl;
                } else if (option == 5){
                    cout << "SIZE - Regresa la cantidad de datos que tiene la fila priorizada." << endl;
                    cout << "Total de datos es: " << listMax.getSize() << endl << endl;
                } else if (option == 6){
                    cout << "HEAP SORT - Metodo de ordenamiento." << endl;
                    cout << "1. Ascendente" << endl;
                    cout << "2. Descendente" << endl;
                    cout << "Ingresa la opcion: "; 
                    cin >> x; cout << endl;

                    while (x < 1 || x > 2){
                        cout << "HEAP SORT - Metodo de ordenamiento." << endl;
                        cout << "1. Ascendente" << endl;
                        cout << "2. Descendente" << endl;
                        cout << "Ingresa la opcion: "; cin >> x;
                    }

                    if (x == 1){
                        // Un vector auxiliar para mantener la prioridad del Max Heap 
                        heapSort(listMax.returnList(),"asc"); // Menor -> Mayor
                        listMax.print();
                        cout << endl;
                    } else if (x == 2){
                        heapSort(listMax.returnList(),"des"); // Mayor -> Menor
                        listMax.print();
                        cout << endl;
                    }
                } else if (option == 7){
                    cout << "PRINT - Imprimir los elementos del Heap" << endl;
                    listMax.print(); cout << endl << endl;
                }
            }
        } 
        
        // MIN HEAP
        else if (opcionHeap == 2) {
            int option = 0;
            listMin = listInt;

            while (option != 8){
                int x = 0;

                cout << "----------- MENU PRINCIPAL - HEAP INT -----------" << endl;
                cout << "1) Push" << endl;
                cout << "2) Pop" << endl;
                cout << "3) Top" << endl;
                cout << "4) Empty" << endl;
                cout << "5) Size" << endl;
                cout << "6) HeapSort" << endl;
                cout << "7) Print" << endl;
                cout << "8) Salir" << endl;
                cout << "Ingresa la opcion: "; cin >> option;
                cout << endl;

                while (option < 1 || option > 8){
                    cout << endl << "----------- RESPUESTA NO VALIDA  -----------" << endl;
                    cout << "-------------- MENU PRINCIPAL --------------" << endl;
                    cout << "1) Push" << endl;
                    cout << "2) Pop" << endl;
                    cout << "3) Top" << endl;
                    cout << "4) Empty" << endl;
                    cout << "5) Size" << endl;
                    cout << "6) HeapSort" << endl;
                    cout << "7) Print" << endl;
                    cout << "8) Salir" << endl;
                    cout << "Ingresa la opcion: "; cin >> option;
                    cout << endl;
                }

                if (option == 1){
                    cout << "PUSH - Agrega un dato a la fila priorizada." << endl;
                    cout << "Ingresa el valor: "; cin >> x;
                    listMin.push(x);
                    cout << endl << endl;
                } else if (option == 2){
                    cout << "POP - Saca de la fila priorizada el dato que tiene mayor prioridad." << endl;
                    listMin.pop();
                    cout << endl << endl;
                } else if (option == 3){
                    cout << "TOP - Regresa el valor del dato que está con mayor prioridad en la fila priorizada." << endl;
                    cout << listMin.top() << endl << endl;
                } else if (option == 4){
                    cout << "EMPTY - Regresa un valor boleando diciendo si la fila priorizada está vacía o tiene datos." << endl;
                    cout << "Se encuentra vacía?  ";
                    listMin.isEmpty() ? cout << "Si" << endl << endl : cout << "No" << endl << endl;
                } else if (option == 5){
                    cout << "SIZE - Regresa la cantidad de datos que tiene la fila priorizada." << endl;
                    cout << "Total de datos es: " << listMin.getSize() << endl << endl;
                } else if (option == 6){
                    cout << "HEAP SORT - Metodo de ordenamiento." << endl;
                    cout << "1. Ascendente" << endl;
                    cout << "2. Descendente" << endl;
                    cout << "Ingresa la opcion: "; 
                    cin >> x; cout << endl;

                    while (x < 1 || x > 2){
                        cout << "HEAP SORT - Metodo de ordenamiento." << endl;
                        cout << "1. Ascendente" << endl;
                        cout << "2. Descendente" << endl;
                        cout << "Ingresa la opcion: "; cin >> x;
                    }

                    if (x == 1){
                        // Un vector auxiliar para mantener la prioridad del Max Heap 
                        heapSort(listMin.returnList(),"asc"); // Menor -> Mayor
                        listMin.print();
                        cout << endl;
                    } else if (x == 2){
                        heapSort(listMin.returnList(),"des"); // Mayor -> Menor
                        listMin.print();
                        cout << endl;
                    }
                } else if (option == 7){
                    cout << "PRINT - Imprimir los elementos del Heap" << endl;
                    listMin.print(); cout << endl << endl;
                }
            }
        }
    }   
}

int main() {
    
    srand(time(0));
    start();

    return 0;
}
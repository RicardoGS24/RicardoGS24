#include <iostream>
#include <vector>
using namespace std;

// ALGORITMOS DE BÚSQUEDA
// MÉTODO: INTERCAMBIO - SWAP SORT


// Una Función para 
// "&" usar el amperson es para especificar que trabajo con el lugar de memoria del atributo
template<class T>
void swap(vector<T> &list, int a, int b){
    if (list[a] != list[b]){
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// Algoritmo de ordenamiento Swap Sort
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps){
    // Iteración de cada una de las pasadas
    for(int i=0; i<list.size()-1;i++){
        // Iteración del primer elemento con el resto
        for(int k=i+1; k<list.size();k++){
            //Incrementamos en 1 el número de comparaciones
            comparisons++;
            if (list[i] > list[k]){
                // Incrementamos el valor de intercambios
                swaps++;
                //Intercambiamos i con j
                swap(list, i, k);
            }
        }
    }
}

// Algoritmo de ordenamiento Burbuja
template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps){
    int iter = 0;
    bool control = true;
    //Iteración por cada pasada
    while(iter < list.size()-1 && control){
        control = false;
        //Comparamas en pares hasta dejar el valor mayor al final de la lista
        for (int i = 1; i<list.size()-iter;i++){
            //Incrementamos en 1 el número de comparaciones
            comparisons++;
            //Comparamos el list[i-1] y list[i]
            if (list[i-1] > list[i]){
                // Incrementamos el valor de intercambios
                swaps++;
                //Intercambiamos i con j
                swap(list, i-1, i);
                // Si hubo intercambio, cambiamos a true la variable de control
                control = true;
            }
        }
        // Incrementamos en 1 la variable iter
        iter++;    
    }
}


template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> list = {15,7,3,9,12,5,2};
    vector<int> listAux;

    int comparisons = 0;
    int swaps = 0;
    listAux = list;
    swapSort(list,comparisons,swaps);
    
    cout << "Ordenamiento de intercambio Swap-Sort: " << endl;
    print(listAux);
    print(list);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;

    comparisons = 0;
    swaps = 0;
    bubbleSort(listAux,comparisons,swaps);
    cout << endl << "Ordenamiento de intercambio de Burbuja: " << endl;
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
    
    return 0;
}
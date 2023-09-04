#include <iostream>
#include <vector>
using namespace std;


template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

// Función MERGE
template <class T>
void merge(vector<T> &list, int left, int mid, int right) {
    // Creamos lista temporal del lado izquierdo
    vector<T> listLeft;
    for (int i=left; i<=mid; i++) {
        listLeft.push_back(list[i]);
    }

    // Creamos lista temporal del lado derecho
    vector<T> listRight;
    for (int j=mid+1; j<=right; j++) {
        listRight.push_back(list[j]);
    }
    // Definimos indice auxiliar donde voy a ir ordenando lo numeros
    int auxIndex = left;
    // Comparamos las listas
    // Creamos dos índices, uno para cada lista
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < listLeft.size() && rightIndex < listRight.size()) { // compara mientras hay elementos por comparar
        // Comparamos listLeft[leftIndex] con listRight[rightIndex]
        if (listLeft[leftIndex] < listRight[rightIndex]) {
            // El valor de la izquierda es menor al de la derecha
            list[auxIndex] = listLeft[leftIndex];
            // Incrementamos el valor de leftIndex
            leftIndex++;
        } else {
            // El valor de la derecha es menor al valor de la izquieda
            list[auxIndex] = listRight[rightIndex];
            // Incrementamos el valor de leftIndex
            rightIndex++;
        }
        // Incremenramos indice auxiliar
        auxIndex++;
    }
    // Se vacían los valor pendientes que ya no se pueden comparar
    // Vaciamos los valores restantes del lado izquierdo
    while (leftIndex < listLeft.size()) {
        // El valor de la izquierda es menor al de la derecha
        list[auxIndex] = listLeft[leftIndex];
        // Incrementamos el valor de leftIndex
        leftIndex++;
        // Incremenramos indice auxiliar
        auxIndex++;
    } 
    // Vaciamos los valores restantes del lado derecho
    while (rightIndex < listRight.size()) {
        // El valor de la derecha es menor al valor de la izquieda
        list[auxIndex] = listRight[rightIndex];
        // Incrementamos el valor de leftIndex
        rightIndex++;
        // Incremenramos indice auxiliar
        auxIndex++;
    }
}

template<class T>
void mergeSort(vector<T> &list, int left, int right) {
    if (left < right) { // Condición de control
        // Vamos a calcular mid
        int mid = left + (right - left) / 2;
        // Ordenamos la lista de la izquierda
        mergeSort(list, left, mid);
        // Ordenamos la lista de la derecha
        mergeSort(list, mid+1, right);
        // Merge
        merge(list, left, mid, right);
    }
}

int main()
{
    vector<int> list = {15,7,3,9,12,5,2};
    mergeSort(list,0,list.size()-1);
    cout << "Ordenamiento por MERGE: " << endl;
    print(list);
    return 0;
}

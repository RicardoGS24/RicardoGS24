// Jesús Ricardo Guerrero Silvestre
// A00835912
// Ingenería en Robótica y Sistemas Digitales

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// FUNCIÓN PARA IMPRIMIR UN VECTOR
template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

// FUNCIÓN PARA CAMBIAR 2 ELEMENTOS DENTRO DE UN VECTOR
template<class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// CREA UNA LISTA ALEATORIA DE ENTEROS
void createListInt(vector<int> &list, int quantity){
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

// CREA UNA LISTA ALEATORIA DE LETRAS
void createListChar(vector<char> &list,int quantity){
    for (int i = 0; i < quantity; i++) {
        int numeroAleatorio = rand() % 26;
        char letraAleatoria = 'a' + numeroAleatorio;
        list.push_back(letraAleatoria);
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
void createListString(vector<string> &list,int quantity,int longitud){
    for (int i = 0; i < quantity; i++) {
        string nuevoString = generarStringAleatorio(longitud);
        list.push_back(nuevoString);
    }
}


// BÚSQUEDA SECUENCIAL
int secuencialSearch(vector<int>list,int data){
    for(int i = 0; i < list.size(); i++){
        if(data == list[i]){
            return i;
        }
    }
    return -1;
}

// BÚSQUEDA BINARIA
int binarySearch(vector<int> list, int data){
    // Inicializar left y right
    int left = 0;
    int right = list.size() - 1;

    while(left <= right){
        //Calcular el valor de en medio
        int mid = left + (right - left)/2;
        //Camparamos el valor buscadoo con el valor de la lista en el indice mid
        if (list[mid] == data){
            // Ya lo encontramos
            return mid;
        }
        else { // No son iguales
            if (data < list[mid]){ //Data se encuentra de lado izquierdo
                right = mid - 1;
            }
            else if (data > list[mid]){ //Data se encuentra de lado derecho
                left = mid + 1;
            }
        }
    }
    //throw out_of_range("No sé encontró el valor buscado");
    return -1;
}

// MÉTODO DE INTERCAMBIO
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    // Iteración de cada una de las pasadas
    for (int i=0; i<list.size()-1; i++) {
        // Iteración del primer elemento con el resto
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i] con list[j]
            if (list[i] > list[j]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i, j);
            }
        }
    }
}

// MÉTODO DE BURBUJA
template<class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    int iter = 0;
    bool control = true;
    // Iteración por cada pasada
    while (iter < list.size()-1 && control) {
        // Inicializamos la variable de control
        control = false;
        // Comparamos en pares hasta dejar el valor mayor al final de la lista
        for (int i=1; i<list.size()-iter; i++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i-1] con list[i]
            if (list[i-1] > list[i]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i-1, i);
                // Si hubo intercambio cambiamos a true la variable de control
                control = true;
            }
        }
        // Incrementamos en 1 la variable iter
        iter++;
    }
}

// MÉTODO DE SELECCIÓN DIRECTA
template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=0; i<list.size()-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<list.size(); j++) {
            // increment5amos comparaciones
            comparisons++;
            // Comparamos para encontrar el valor más pequeño
            if (list[j]<list[minIndex]) {
                // Asignamos a minInex j, que sería el nuevo valor más pequeño
                minIndex = j;
            }
        }
        // Hacemos el intercambio
        if (minIndex != i) {
            swap(list, minIndex, i);
            // Incrementamos los intercambios
            swaps++;
        }
    }
}

// MÉTODO DE INSERCIÓN
template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=1; i<list.size(); i++) {
        int j=i-1;
        while (j>=0) {
            // Incrementamos las comparaciones
            comparisons++;
            // comparamos los valores de j y j+1
            if (list[j+1]<list[j]) {
                // Hacemos el intercambio
                swap(list, j, j+1);
                // Incrementamos los intercambios
                swaps++;
            } else {
                j = -1; // break
            }
            // Decrementamos el valor de j
            j--;
        }
    }
}

template<class T>
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

// MÉTODO DE MERGE SORT
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

template<class T>
int getPivot(vector<T> &list, int left, int right) {
    // Definimos el pivote
    int pivot = right;

    // Creamos un indice aux en left - 1
    int auxIndex = left-1;

    // Iteramos la lista desde left hasta right -1
    for(int index=left;index < right;index++){
        // COmparamos el valor de index con el valor del pivot
        if (list[index] < list[pivot]){
            // Incrementamos el índice auxiliar
            auxIndex++;
            // Intercambiamos el indice auxiliar con index
            swap(list, index, auxIndex);

        }
    }

    // Incrementamos el índice auxiliar
    auxIndex++;
    // Intercambiamos el indice auxiliar con el pivot
    swap(list, pivot, auxIndex);    
    // Regresamoe el indice auxliar
    return auxIndex;
}

// MÉTODO DE QUICK SORT
template<class T>
void quickSort(vector<T> &list, int left, int right) {
    if (left < right) {
        // Obtenemos la posición final del privote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot+1, right);
    }
}

// MÉTODO DE SHELL SORT
template<class T>
void shell(vector<T> &a, int n)
{
    int ints, i;
    bool band;
    ints = n;
    while (ints > 1)
    {
        ints = (ints / 2);
        band = true;
        while (band == true)
        {
            band = false;
            i = 0;
            while ((i + ints) <= n)
            {
                if (a[i] > a[i + ints])
                {
                    swap(a,i,i+ints);
                    band = true;
                }
                i++;
            }
        }
    }
}



//MENÚ DEL ALGORITMOS DE BÚSQUEDA
template<class T>
void menuAlgoritmosBusqueda(vector<T> &list){
    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    int opcion = 0;
    // Imprimir una lista
    cout << "ALGORITMOS DE BÚSQUEDA" << endl;
    cout << "Lista de valores aleatorios: " << endl;
    print(list);
    cout << endl;

    while (opcion != 3){
        int comparisons = 0;
        int swaps = 0;

        cout << "1) Búsqueda sequencial" << endl;
        cout << "2) Búsqueda binaria" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> opcion;

        // Búsqueda sequencial
        if (opcion == 1){             
            startTime(begin);
            swapSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Intercambio" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }   // Búsqueda binaria
        else if(opcion == 2){
            startTime(begin);
            bubbleSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Burbuja" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }        
    }   
}


//MENÚ DEL ALGORITMOS DE ORDENAMIENTOS
template<class T>
void menuAlgoritmosOrdenamiento(vector<T> &list){
    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    int opcion = 0;
    // Imprimir una lista
    cout << "ALGORITMOS DE ORDENAMIENTO" << endl;
    cout << "Lista de valores aleatorios: " << endl;
    print(list);
    cout << endl;

    while (opcion != 8){
        int comparisons = 0;
        int swaps = 0;

        cout << "1) Método de Intercambio" << endl;
        cout << "2) Método de Burbuja" << endl;
        cout << "3) Método de Selección directa" << endl;
        cout << "4) Método de Inserción" << endl;
        cout << "5) Método de Merge Sort" << endl;
        cout << "6) Método de Quick Sort" << endl;
        cout << "7) Método de Shell Sort" << endl;
        cout << "8) Salir" << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> opcion;

            // Método de Intercambio
        if (opcion == 1){             
            startTime(begin);
            swapSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Intercambio" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }   // Método de Burbuja
        else if(opcion == 2){
            startTime(begin);
            bubbleSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Burbuja" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }   // Método de Selección
        else if(opcion == 3){
            startTime(begin);
            selectionSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Selección" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }   // Método de Inserción
        else if(opcion == 4){
            startTime(begin);
            insertionSort(list, comparisons, swaps);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Inserción" << endl;
            print(list);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        }   // Método de Mezcle
        else if(opcion == 5){
            startTime(begin);
            mergeSort(list, 0, list.size()-1);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento por Mezcla" << endl;
            print(list);
        }   // Método de ordenamiento rápido
        else if(opcion == 6){
            startTime(begin);
            quickSort(list, 0, list.size()-1);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento Rápido" << endl;
            print(list);
        }   // Método de Shell Sort
        else if(opcion == 7){
            int n = list.size()-1;
            startTime(begin);
            shell(list,n);
            cout << endl;
            getTime(begin, end);
            cout << "Ordenamiento Shell Sort" << endl;
            print(list);
        }
        opcion = 8;
    }
}


// MENÚ DEL TIPO DE ALGORITMO
template<class T>
void menuAlgoritmo(vector<T> &list){
    int opcion = 0;
    while (opcion != 3){
        cout << "ALGORITMOS FUNDAMENTALES" << endl;
        cout << "1) Algoritmos de ordenamiento" << endl;
        cout << "2) Algoritmos de búsqueda" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> opcion;
        cout << endl << endl;

        // Algoritmos de ordenamiento
        if (opcion == 1){            
            // AGREGAR EL MENÚ
            menuAlgoritmosOrdenamiento(list);
        } 
        // Algoritmos de búsqueda 
        else if(opcion == 2){
            // AGREGAR EL MENÚ
            menuAlgoritmosBusqueda(list);
        }
    }
}


// MENÚ PRINCIPAL
void start(){
    int opcion = 0;

    while(opcion != 4){
        cout << endl << "MENU GENERAL" << endl;
        cout << "1) Crear un vector de tipo _int_" << endl;
        cout << "2) Crear un vector de tipo _char_" << endl;
        cout << "3) Crear un vector de tipo _string_" << endl;
        cout << "4) Salir" << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> opcion;
        cout << endl;

        // Vector INT
        if (opcion == 1){
            int n;
            vector<int> list;
            cout << "VECTOR INT" << endl;
            cout <<"Ingresa el numero de elementos en el vector: ";
            cin >> n;
            cout << endl;
            createListInt(list, n);
            menuAlgoritmo(list);
        } // Vector CHAR 
        else if(opcion == 2){
            int n;
            vector<char> list;
            cout << "VECTOR CHAR" << endl;
            cout <<"Ingresa el numero de elementos en el vector: ";
            cin >> n;
            cout << endl;
            createListChar(list, n);
            menuAlgoritmo(list);
        } // Vector STRING
        else if (opcion == 3){
            int n,l;
            vector<string> list;
            cout << "VECTOR STRING" << endl;
            cout <<"Ingresa el numero de elementos en el vector: ";
            cin >> n;
            cout <<"Ingresa la longitud del string: ";
            cin >> l;
            cout << endl;
            createListString(list,n,l);
            menuAlgoritmo(list);
        }               
    }
}


int main() {
    //Semilla para generar números aleatorios
    srand(time(0));
    
    start();

    // vector<char> list;
    // createListChar(list,10);
    // vector<char> listAux;
    
    // print(list);
    // int comparisons = 0;
    // int swaps = 0;

    // listAux = list;
    // startTime(begin);
    // swapSort(listAux, comparisons, swaps);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento por Intercambio" << endl;
    // print(listAux);
    // cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    
    // listAux = list;
    // comparisons= 0;
    // swaps = 0;
    // startTime(begin);
    // bubbleSort(listAux, comparisons, swaps);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento por Burbuja" << endl;
    // print(listAux);
    // cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    
    // listAux = list;
    // comparisons= 0;
    // swaps = 0;
    // startTime(begin);
    // selectionSort(listAux, comparisons, swaps);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento por Selección" << endl;
    // print(listAux);
    // cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    
    // listAux = list;
    // comparisons= 0;
    // swaps = 0;
    // startTime(begin);
    // insertionSort(listAux, comparisons, swaps);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento por Inserción" << endl;
    // print(listAux);
    // cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    
    // listAux = list;
    // startTime(begin);
    // mergeSort(listAux, 0, listAux.size()-1);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento por Mezcla" << endl;
    // print(listAux);

    // listAux = list;
    // startTime(begin);
    // quickSort(listAux, 0, listAux.size()-1);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento Rápido" << endl;
    // print(listAux);    

    // listAux = list;
    // int n = listAux.size()-1;
    // startTime(begin);
    // shell(listAux,n);
    // cout << endl;
    // getTime(begin, end);
    // cout << "Ordenamiento Shell Sort" << endl;
    // print(listAux);

    return 0;
}


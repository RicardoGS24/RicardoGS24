#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;

void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

template<class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

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

void createListString(vector<string> &list,int quantity,int longitud){
    for (int i = 0; i < quantity; i++) {
        string nuevoString = generarStringAleatorio(longitud);
        list.push_back(nuevoString);
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

template<class T>
void binarySearch(vector<T> list, T data){
    // Inicializar left y right
    int left = 0;
    int right = list.size() - 1;

    while(left <= right){
        //Calcular el valor de en medio
        int mid = left + (right - left)/2;
        //Camparamos el valor buscadoo con el valor de la lista en el indice mid
        if (list[mid] == data){
            // Ya lo encontramos
            cout << "El valor buscado tiene el índice: " << mid << endl;
            return;
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
    cout << ("No sé encontró el valor buscado") << endl;
}

template<class T>
void secuencialSearch(vector<T>list,T data){
    int cont=0;
    for(int i=0; i < list.size(); i++){
        if(data == list[i]){
            cout << "El valor buscado tiene el índice: " << i << endl;
            return;
        }
        cont++;
    }
    
    if(cont >= list.size()){
        cout << "No sé encontró el valor buscado" << endl;
    }
}


template<class T>
int main() {

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 10000 de enteros
    // vector<int> list;
    // createListInt(list, 10);

    // vector<char> list;
    // createListChar(list,10);

    // NOTA:
    // Cambiar la funciones para crear los vectores para que 
    // cree elementos que no se repitan y los string sean todos en minúscula

    vector<string> list;
    createListString(list,10,5);
    quickSort(list, 0, list.size()-1);
    
    print(list);
    T index;

    cout << "Ingresa el entero a buscar: ";
    cin >> index;

    while (index != "0"){

        binarySearch(list,index);        
        secuencialSearch(list,index);
        
        cout << "Ingresa el entero a buscar: ";
        cin >> index;
    }

    return 0;
}
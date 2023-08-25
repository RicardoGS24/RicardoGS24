#include <iostream>
#include <vector>
#include <chrono>
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

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

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

int secuencialSearch(vector<int>list,int data){
    for(int i = 0; i < list.size(); i++){
        if(data == list[i]){
            return i;
        }
    }
    return -1;
}

int main() {

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 1000000 de enteros
    vector<int> list;
    createListInt(list, 1000000);
    sort(list.begin(),list.end()); //Sorting el vector

    int index;
    cout << "Ingresa el entero a buscar: ";
    cin >> index;

    while (index != 0){

        cout << "Tiempo de búsqueda binaria: ";
        startTime(begin);
        cout << binarySearch(list,index) << endl;
        getTime(begin, end);
        
        cout << "Tiempo de búsqueda secuencial: ";
        startTime(begin);
        cout << secuencialSearch(list,index) << endl;
        getTime(begin, end);
        
        cout << "Ingresa el entero a buscar: ";
        cin >> index;
    }

    return 0;
}
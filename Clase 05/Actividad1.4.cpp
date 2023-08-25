#include <iostream>
#include <vector>
using namespace std;

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



int main()
{
    vector<int> list = {5,12,23,27,32,34,38,40,45};
    cout << binarySearch(list,23) << endl;
    cout << secuencialSearch(list,23) << endl;
    return 0;
}

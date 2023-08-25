#include <iostream>
#include <vector>
using namespace std;

// int binarySearch(vector<string> list, int data){
//     // Inicializar left y right
//     int left = 0;
//     int right = list.size() - 1;

//     while(left <= right){
//         //Calcular el valor de en medio
//         int mid = left + (right - left)/2;
//         //Camparamos el valor buscadoo con el valor de la lista en el indice mid
//         if (list[mid] == data){
//             // Ya lo encontramos
//             return mid;
//         }
//         else { // No son iguales
//             if (data < list[mid]){ //Data se encuentra de lado izquierdo
//                 right = mid - 1;
//             }
//             else if (data > list[mid]){ //Data se encuentra de lado derecho
//                 left = mid + 1;
//             }
//         }
//     }
//     //throw out_of_range("No sé encontró el valor buscado");
//     return -1;
// }

int secuencialSearch(vector<string>list){
    int contador = 0;
    for(int i = 0; i < list.size(); i++){ //Iterar para obtener cada elemento del vector
        for(int k=0; i<list[i].size();k++){  //Iterar para obtener cada caracter del string
            contador++;
            if(list[i][k] == list[i][k+1]){
                //contador++;
                k++;
            }
            else {
                return contador;
            }
        }
    }
    return 0;
}


int main()
{
    vector<string> list;
    int n = 0;
    string x = "";
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> x;
        list.push_back(x);
    }

    int sS = secuencialSearch(list);

    cout << list[0][(sS*2) -2] << " " << sS << endl;

    return 0;
}

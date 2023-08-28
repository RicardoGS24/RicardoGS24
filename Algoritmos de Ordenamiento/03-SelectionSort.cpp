#include <iostream>
using namespace std;

template<class T>
void swap(vector<T> &list, int a, int b){
    if (list[a] != list[b]){
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

template <class T>
void selectionSort(vector<T> &vector,int &comparisons,int &swaps){    
    for(int i=0; i<vector.size()-1;i++){
        int numMenor = i;
        for(int k=i+1; k<vector.size();k++){
            comparisons++;
            // ¿Por qué numMenor?
            if(vector[k] < vector[numMenor]){  
                numMenor = k;
            }
        }
        // ¿Por qué numMenor - i?
        if (numMenor != i){
            swap(vector,numMenor,i);
            swaps++;
        }
    }
}

int main()
{
    vector<int> list = {15,7,3,9,12,5,2};
    vector<int> listAux;

    int comparisonsSort = 0, swapsSort = 0;

    selectionSort(list,comparisonsSort,swapsSort);
    cout << "Método de selección SORT: " << endl;
    print(list);
    cout << "Comparaciones: " << comparisonsSort << endl;
    cout << "Intercambios: " << swapsSort << endl;
    
    return 0;
}

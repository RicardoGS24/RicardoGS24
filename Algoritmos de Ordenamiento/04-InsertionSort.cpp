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
void insertionSort(vector<T> &list,int &comparisons,int &swaps){    
    for(int i=1; i<list.size(); i++){
        int j = i-1;
        while(j>=0){
            comparisons++;
            if(list[j+1]<list[j]){
                swap(list,j,j+1);
                swaps++;
            } else {
                j = -1; // break;
            }
            j--;
        }
    }
}

template <class T>
void insertionSort1(vector<T> &list,int &comparisons,int &swaps){    
    for(int i=1; i<list.size(); i++){
        int j = i-1;
        while(j>=0 && list[j+1]<list[j]){
            comparisons++;
            swap(list,j,j+1);
            swaps++;
            j--;
        }
        if(j<0){
            comparisons++;
        }
    }
}

int main()
{
    vector<int> list = {15,7,3,9,12,5,2};
    vector<int> listAux;

    int comparisonsSort = 0, swapsSort = 0;

    insertionSort(list,comparisonsSort,swapsSort);
    cout << "Método de inserción SORT: " << endl;
    print(list);
    cout << "Comparaciones: " << comparisonsSort << endl;
    cout << "Intercambios: " << swapsSort << endl;
    
    return 0;
}

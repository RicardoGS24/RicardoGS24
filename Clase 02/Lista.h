#ifndef Lista_h //Si una vez ya está definida no lo vualves a definir para evitar repetir información
#define Lista_h
#include <iostream>
using namespace std;

#include <stdio.h>
#include <vector>

// El trabajar con un template se debe 
template <typename T>
class Lista {
    private:
        vector<T> data;
        int size;
    public:
        Lista();
        ~Lista();
        void insert(T a);
        void removeLast();
        T getData(int p);
        int getSize();
        T getMax();
        void print();
};

template <typename T>
Lista<T>::Lista(){
    size = 0;
}

template <typename T>
Lista<T>::~Lista(){

}

template <typename T>
void Lista<T>::insert(T a){
    data.push_back(a);
    size++;
}

template <typename T>
void Lista<T>::removeLast(){
    if (size > 0){
        cout << "Valor eliminado: " << data[size-1] << endl << endl;;
        //data.erase(data.begin()+ size-1);
        data.pop_back(); // Elimina el último elemento
        size = size - 1;
    }
    else{
        throw out_of_range("NO HOY ELEMENTOS");
    }
}

template <typename T>
T Lista<T>::getData(int index){
    if (index >= 0 &&  index < size){
        return data[index];
    }
    else{
        throw out_of_range("Posición invlálida");
    }
}

template <typename T>
int Lista<T>::getSize(){
    return size;    
}

template <typename T>
T Lista<T>::getMax(){
    if (size > 0){
        T max = data[0];
        for (int i = 1; i < size; i++){
            if (max <= data[i]){
                max = data[i];                    
            }
        }
        return max;
    }
    else {
        throw out_of_range("La lista está vacía");
    }
}

template <typename T>
void Lista<T>::print(){         
    for (int i = 0;i < size;i++){
        cout <<"["<<i<<"]"<< " - " << data[i] << endl;
    }
    cout << endl;
}

#endif
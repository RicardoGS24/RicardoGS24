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
        void printHello();
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
    if (data.size() == 0){
        cout << "NO HOY ELEMENTOS";
    }
    else{
        cout << "Valor eliminado: " << data[size-1] << endl << endl;;
        data.erase(data.begin()+ size-1);
        size = size - 1;
    }
}

template <typename T>
T Lista<T>::getData(int p){
    if (0 <= p-1 < size){
        return data[p-1];
    }
    else{
        cout <<"NO EXISTE ESE ELEMENTO";
        //return data[1];
    }
}

template <typename T>
int Lista<T>::getSize(){
    return size;    
}

template <typename T>
T Lista<T>::getMax(){
    //int pos = 0;
    T max = data[0];

    for (int i = 1; i < size; i++){
        if (max <= data[i]){
            max = data[i];                    
        }
    }
    return max;
}

template <typename T>
void Lista<T>::print(){
            
    //Forma 1
    for (int i = 0;i < size;i++){
        cout <<"["<<i<<"]"<< " - " << data[i] << endl;
    }
    cout << endl;

    //Forma 2
    // for(auto el:data){
    //     cout << el << endl;
    //     //cout <<"["<<i<<"]"<< " - " << data[i] << endl;
    // }
}

template <typename T>
void Lista<T>::printHello(){
            cout << "Hello world" << endl;
}


#endif
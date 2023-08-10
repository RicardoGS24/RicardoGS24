#ifndef Lista_h
#define Lista_h
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// El trabajar con un template se debe 
template <typename T>
class Lista {
    private:
        vector<T> data;
        int size;
    public:
        Lista(){
            size = 0;
        }
        ~Lista(){
            
        }
        
        void insert(T a){
            data.push_back(a);
            size++;
        }

        void removeLast(){
            if (data.size() == 0){
                cout << "NO HOY ELEMENTOS";
            }
            else{
                cout << "Valor eliminado: " << data[size-1] << endl << endl;;
                data.erase(data.begin()+ size-1);
                size = size - 1;
            }
        }

        T getData(int p){
            if (0 <= p-1 < size){
                return data[p-1];
            }
            else{
                cout <<"NO EXISTE ESE ELEMENTO";
                //return data[1];
            }
        }

        int getSize(){
            return size;    
        }

        T getMax(){
            //int pos = 0;
            T max = data[0];

            for (int i = 1; i < size; i++){
                if (max <= data[i]){
                    max = data[i];                    
                }
            }
            return max;
        }

        void print(){
            for (int i = 0;i < size;i++){
                cout <<"["<<i<<"]"<< " - " << data[i] << endl;
            }
            cout << endl;
        }
        
        void printHello(){
            cout << "Hello world" << endl;
        }
};

#endif

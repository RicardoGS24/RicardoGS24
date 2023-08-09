#ifndef Lista_h
#define Lista_h
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

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
                cout << data[size-1] << endl;
                size = size - 1;
                data.erase(data.begin()+ size-1);
            }
        }

        T getData(int p){
            if (0 <= p < size){
                return data[p];
            }
            else{
                cout <<"NO EXISTE ESE ELEMENTO";
            }
        }

        int getSize(){
            return size;    
        }

        /*T getMax(){
            template max = data[0];
            template pos;
            for (int i = 0; i < size; i++){
                if (max >= int)
            }
            return max;
        }*/

        void print(){
            for (int i = 0;i < size;i++){
                cout <<"["<<i<<"]"<< " - " << data[i] << endl;
            }
        }
        
        void printHello(){
            cout << "Hello world" << endl;
        }
};


/*class Lista{
    private:
        template <class data[]>
        vector<int> data;
        //template <class Data>;

        int size;
    public:
        Lista();
        void insert(int);
        void removeLast(int);
        int getData(int);
        int getSize();
        int getMax();
        void print();

};*/

#endif

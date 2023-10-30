#ifndef Heap_h
#define Heap_h

#include <vector>
#include "Log.h"

template <class T>
class Heap {
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T pop(); // elimina el elemento de mayor prioridad en el heap
    int getSize();
    void print();
    bool isEmpty();
    void push(T data);
    T top();
    vector<T>& returnList();
};

template <class T>
Heap<T>::Heap()
{

}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father)
{
    // Haces el proceso por cada uno de los padres
    int son1;
    int son2;
    int bigBoy;
    // Hacemos el proceso hasta que el nodo father ya no tenga hijos
    while (father * 2 + 1 < heap.size())
    {
        // Asignamos el valor del primer hijo
        son1 = father * 2 + 1;
        // validams si tiene un 2do hijo
        if (father * 2 + 2 < heap.size())
        {
            // Asignamos el valor del segundo hijo
            son2 = father * 2 + 2;
            // le asignamos a bigBoy el mayor de los hijos
            heap[son1] > heap[son2] ? bigBoy = son1 : bigBoy = son2;
        }
        else
        {
            // El primer hijo es el mayor
            bigBoy = son1;
        }
        // Validamos si tenemos que hacer el intercambio
        if (heap[bigBoy] > heap[father])
        {
            // Intercambiamos los valores
            swap(father, bigBoy);
            // le asignamos a father el valor del hijo más grande
            father = bigBoy;
        }
        else
        {
            father = heap.size();
        }
    }
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    // igualamos la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = list.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Llamamos al downSort para cada uno de los padres
        downSort(father);
        // recorremos al siguiente papa de derecha a izquierda
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    // igualamos la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = list.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Llamamos al downSort para cada uno de los padres
        downSort(father);
        // recorremos al siguiente papa de derecha a izquierda
        father--;
    }
}

template <class T>
T Heap<T>::pop() {
    if (!heap.empty()) {
        // Gaurdamos el valor de mayor prioridad del heap
        T auxMax = heap[0];
        // Intercambiamos el primer elemento (el de mayor prioridad) con el último elemento de la lista
        swap(0, heap.size()-1);
        // Eliminamos el último nodo de la lista
        heap.pop_back();
        // Hacemos el reacomod hacía abajo del primer elemento (downSort(0))
        downSort(0);
        // regresamos el valor de mayor prioridad
        return auxMax;
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template <class T>
int Heap<T>::getSize()
{
    return heap.size();
}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
bool Heap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
void Heap<T>::push(T data){
    // Validamos si la lista está vacía
    if (!isEmpty()){
        heap.push_back(data);
        
        int son = heap.size()-1;
        int father = (son-1) / 2;

        while (heap[father] < heap[son]){
            swap(son,father);
            son = father;
            father = (son-1) / 2;
        }

    } else {
        heap.push_back(data);    
    }
}

template <class T>
T Heap<T>::top(){
    if (!isEmpty()){
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template <class T>
vector<T>& Heap<T>::returnList(){
    return heap;
}


#endif /* Heap_h */
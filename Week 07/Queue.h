#ifndef Queue_h
#define Queue_h
#include "Node.h"

template <class T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* tail;
    public:
        Queue();
        void push(T data); // Agrega un elemento al final de la fila
        void pop(); // Elimina el primer elemento de la list
        T Front();  // Regresa el primer elemento de la lista
        bool isEmpty();
        void print();
};

template <class T>
Queue<T>::Queue(){
    front = nullptr;
}

template <class T>
void Queue<T>::push(T data){
    if (isEmpty()){
        tail = nullptr;
        front = new Node<T>(data,tail);
    } else {
        Node<T>* aux = tail;
        aux->next = new Node<T>(data);
        tail = aux->next->next;
    }
}

template <class T>
void Queue<T>::pop(){
    return;
}

template <class T>
T Queue<T>::Front(){

}

template  <class T>
bool Queue<T>::isEmpty(){
    return front == nullptr;
}

template <class T>
void Queue<T>::print(){
    Node<T>* aux = front;
    while(aux != nullptr){    // Se pone "->" porque al ser un apuntador no se puede trabajar con punto
        // Imprimimos el valor del nodo
        cout << aux->data;
        if (aux->next != nullptr){
            cout << " -> ";
        }
        // Asignamos a aux el valor de next de aux
        aux = aux->next;
    }
    cout << endl;
}
#endif
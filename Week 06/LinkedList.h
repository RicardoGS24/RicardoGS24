#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <class T>
class LinkedList {
    private:
        Node<T>* head;
        int size = 0;

    public:
        LinkedList();
        void addFirst(T data);
        void addLast(T data);
        void print();
        void insert(int index,T data);
        void updateData(T d1, T d2);
        int getSize();
        bool isEmpty();
};

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
}

template <class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
void LinkedList<T>::addFirst(T data){
    // Apuntamos head a un nuevo nodo que apunte a head
    head = new Node<T>(data, head);
    // Incrementamos el valor de size en 1
    size++;
}

template <class T>
void LinkedList<T>::print(){
    // Definir un apuntador de tipo nodo igual a head
    Node<T>* aux = head;

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

template <class T>
void LinkedList<T>::addLast(T data){
    // Validamos si la lista está vacía
    if (isEmpty()){
        head = new Node<T>(data);
    } else {
        // Definimos un apuntador auxiliar igual a head para recorrer la lista
        Node<T>* aux = head;
        // Recorrer la lista hasta llegar al último nodo
        while (aux->next != nullptr){
            // recorremos aux
            aux = aux->next;
        }
        //Crear un nuevo nodo
        aux->next = new Node<T>(data);
    }
    // Incrementamos el valor de size en 1
    size++;
}

template <class T>
void LinkedList<T>::insert(int index,T data){

    // Verificar que el index es válido
    if ( index >= 0 && index <= size){
        // Definir un indice auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while (auxIndex != index){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del índice auxiliar
            auxIndex++;
        }
        // Insertamos el valor
        aux->next = new Node<T>(data, aux->next);
        size ++;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
    
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

#endif
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
        void print();

        void addFirst(T data);
        void addLast(T data);        
        void insert(int index,T data);        
        bool deleteData(T data);
        bool deleteAt(int index);
        T getData(int index);
        void updateData(T d1,T d2);
        void updateAt(int index,T data);
        
        T& operator[](const int& index);
        void operator=(const LinkedList& newList);

        int findData(T data);
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
void LinkedList<T>::addFirst(T data){
    // Apuntamos head a un nuevo nodo que apunte a head
    head = new Node<T>(data, head);
    // Incrementamos el valor de size en 1
    size++;
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
bool LinkedList<T>::deleteData(T data){
    Node<T>* aux = head;    
    Node<T>* prev = aux;

    if (!isEmpty()){
        // Si es el primer elemento
        if (head->data == data){
            head = aux->next;
            size--;
            delete aux;
            return true;        
        } else {    // Si es un elemento dentro de la lista
            while(aux != nullptr){
                if (data == aux->data){
                    prev->next = aux->next;
                    size--;
                    delete aux;
                    return true;
                } else {
                    prev = aux;
                    aux = aux->next;
                }
            }
        }
    }
    return false;
}

template <class T>
bool LinkedList<T>::deleteAt(int index){
    if (index >= 0 && index < size){
        int auxIndex = 0;
        Node<T>* aux = head;
        Node<T>* prev;
        
        if (auxIndex == index){
            head = aux->next;
            size--;
            delete aux;
            return true;
        } else {
            while (auxIndex != index){
                prev = aux;
                aux = aux->next;
                auxIndex++;
            }
            prev->next = aux->next;
            size--;
            delete aux;
            return true;
        }
    } else {
        //throw out_of_range("El índice no se encuentra en la lista");
        return false;
    }
}

template <class T>
T LinkedList<T>::getData(int index){
    if (index >= 0 && index <= size) {
        int auxIndex = 0;
        Node<T>* aux = head;
        Node<T>* prev;
        
        if (auxIndex == index && head != nullptr){
            return head->data;
        } else {
            while (auxIndex != index){
                aux = aux->next;
                auxIndex++;
            }
            return aux->data;
        }
    } 
    else {
        throw out_of_range("El índice no se encuentra en la lista");
        }
}

template <class T>
void LinkedList<T>::updateData(T d1,T d2){
    Node<T>* aux = head;    
    Node<T>* prev = aux;

    // Si es el primer elemento
    if (head->data == d1){
        head->data = d2;
        return;
    } else {    // Si es un elemento dentro de la lista
        while(aux != nullptr){
            if (d1 == aux->data){
                aux->data = d2;
                return;
            } else {
                prev = aux;
                aux = aux->next;
            }
        }
    }
    
    throw out_of_range("ERROR");
}

template <class T>
void LinkedList<T>::updateAt(int index,T data){
    if (index >= 0 && index <= size){
        int auxIndex = 0;
        Node<T>* aux = head;
        
        if (auxIndex == index){
            head->data = data;
        } else {
            while (auxIndex != index){
                aux = aux->next;
                auxIndex++;
            }
            aux->data = data;
        }
    } else {
        throw out_of_range("ERROR");
    }
}

template <class T>
T& LinkedList<T>::operator[](const int& index){
    if (index >= 0 && index < size){
        int auxIndex = 0;
        Node<T>* aux = head;
        
        while (auxIndex < index){
            aux = aux->next;
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("ERROR");
    }
}

template <class T>
void LinkedList<T>::operator=(const LinkedList& newList){
    if (this == &newList) {
        return;
    }

    // Vaciar la lista
    while(head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
    }

    // Recorrer la lista nueva y agregar los elementos a la lista
    Node<T>* newListNode = newList.head;
    while (newListNode != nullptr) {
        // Aquí puedes agregar lógica para copiar
        this->addLast(newListNode->data);
        // Avanzamos al siguiente nodo
        newListNode = newListNode->next;
    }
}

template <class T>
int LinkedList<T>::findData(T data){
    // Definimos un apuntador auxiliar igual a head
    Node<T>* aux = head;
    // Definir un índice auxiliar
    int auxIndex = 0;
    //  Recorremos la lista para validar si ya lo encontramos
    while(aux != nullptr){
        // Validamos si data es el valor de aux
        if (data == aux->data){
            // Ya lo encontramos
            return auxIndex;
        } else {
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // Al salir del while asumimos que no lo encontramos
    return -1;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

#endif
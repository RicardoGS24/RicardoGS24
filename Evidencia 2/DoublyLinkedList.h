#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "DNode.h"
#include "Log.h"
#include <cstdlib>
#include <ctime>
#include <string.h>

template <class T> 
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size;

public:
    DoublyLinkedList();
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);

    T getData(int index);
    DNode<T>* getHead();
    DNode<T>* getTail();

    void updateData(T d1, T d2);
    void updateAt(int index, T data);
    int findData(T data);
    T& operator[](const int& index);
    void operator=(const DoublyLinkedList& newList);
    
    void clear();
    int getSize();
    void sort();

    void getKeyIp(DNode<T>* node);

    void swap(DNode<T>* a, DNode<T>* b);
    DNode<T>* getPivot(DNode<T>* left, DNode<T>* right,int data);
    void quickSort(DNode<T>* left, DNode<T>* right,int data);

    void duplicate();
    void removeDuplicates();

    void print(string mode);
    bool isEmpty();
};


// CONSTRUCTOR
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//----------------------------------------------------
//-------------------- MÉTODOS -----------------------
//----------------------------------------------------

template <class T>
void DoublyLinkedList<T>::addFirst(T data) {
    // Apuntamos head a un nuevo nodo que apunte a head
    head = new DNode<T>(data, head, nullptr);
    if (isEmpty()) {
        tail = head;
    } else {
        // Actualizamos el prev del siguiente nodo de head
        head->next->prev = head;
    }
    //Incrementamos el valor de size en 1
    size++; 
}

template <class T>
void DoublyLinkedList<T>::addLast(T data) {
    // apuntamos tail a nuevo nuevo nodo que su anterior va a ser tail y su siguiente va a ser nullptr tail->next
    tail = new DNode<T>(data, nullptr, tail);
    if (isEmpty()) {
        head = tail;
    } else {
        tail->prev->next = tail;
    }
    //Incrementamos el valor de size en 1
    size++; 
}

template <class T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // Validamos que el índece exista en la lista
    if (index >= 0 && index < size) {
        // Validamos de que lado de la lista empezamos a recorrer
        if (index <= (size-1) / 2) {
            // Definimos un índex auxiliar igual a 0
            int auxIndex = 0;
            // Definimos un apuntador auxiliar igual a head
            DNode<T>* aux = head;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el valor de índice auxliar
                auxIndex++;
            }
            // insertamos un nuevo nodo
            DNode<T>* aux2 = new DNode<T>(data, aux->next, aux);
            aux->next = aux2;
            // Validamos si el nodo siguiente de aux es nullptr
            if (aux2->next == nullptr) {
                tail = aux2;
            } else {
                aux2->next->prev = aux2;
            }
        } else {
            // Definimos un índex auxiliar igual a size -1
            int auxIndex = size-1;
            // Definimos un apuntador auxiliar igual a head
            DNode<T>* aux = tail;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->prev;
                // Decrementamos el valor de índice auxliar
                auxIndex--;
            }
            // insertamos un nuevo nodo
            DNode<T>* aux2 = new DNode<T>(data, aux->next, aux);
            aux->next = aux2;
            // Validamos si el nodo siguiente de aux es nullptr
            if (aux2->next == nullptr) {
                tail = aux2;
            } else {
                aux2->next->prev = aux2;
            }
        }
        // Incrementamos el valor de size
        size++;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
bool DoublyLinkedList<T>::deleteData(T data){
    DNode<T>* aux = head;    
    DNode<T>* prev = aux;

    if (!isEmpty()){
        if (head->data == data){
            head = aux->next;
            aux->next->prev = nullptr;
            size--;
            delete aux;
            return true;
        } else {
            while (aux != nullptr){
                if (data == aux->data){
                    prev->next = aux->next;
                    aux->next->prev = aux->prev;
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
bool DoublyLinkedList<T>::deleteAt(int index){
    if (index >= 0 && index < size){
        int auxIndex = 0;
        DNode<T>* aux = head;
        DNode<T>* prev;

        if (auxIndex == index){
            head = aux->next;
            aux->next->prev = nullptr;
            size--;
            delete aux;
            return true;
        } else {
            if (index <= (size-1) / 2) {
                int auxIndex = 0;
                DNode<T>* aux = head;
            
                while (auxIndex != index){
                    prev = aux;
                    aux = aux->next;
                    auxIndex++;
                }
                
                prev->next = aux->next;
                aux->next->prev = aux->prev;
                size--;
                delete aux;
                return true;

            } else {
                int auxIndex = size-1;
                DNode<T>* aux = tail;
                DNode<T>* prev = aux;

                while (auxIndex != index) {
                    prev = aux;
                    aux = aux->prev;
                    auxIndex--;
                }
                
                prev->prev = aux->prev;
                prev->prev->next = aux->next;
                delete aux;
                return true;
            }
        }
    } else {
        return false;
    }
}

template <class T>
T DoublyLinkedList<T>::getData(int index){
    if (index >= 0 && index <= size) {
        if (index <= (size-1) / 2){
            int auxIndex = 0;
            DNode<T>* aux = head;
            
            if (auxIndex == index && head != nullptr){
                return head->data;
            } else {
                while (auxIndex != index){
                    aux = aux->next;
                    auxIndex++;
                }
                return aux->data;
            }
        } else {
            int auxIndex = size-1;
            DNode<T>* aux = tail;

            while (auxIndex != index){
                aux = aux->prev;
                auxIndex--;
            }
            return aux->data;
        }
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
        }
}

template <class T>
DNode<T>* DoublyLinkedList<T>::getHead(){
    return head;
}

template <class T>
DNode<T>* DoublyLinkedList<T>::getTail(){
    return tail;
}   

template <class T>
void DoublyLinkedList<T>::updateData(T d1,T d2){
    DNode<T>* aux = head;    
    DNode<T>* prev = aux;

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
void DoublyLinkedList<T>::updateAt(int index,T data){
    if (index >= 0 && index < size){
        if (index <= (size-1) / 2) {
            int auxIndex = 0;
            DNode<T>* aux = head;
            
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
            int auxIndex = 0;
            DNode<T>* aux = tail;
            
            while (auxIndex != index){
                aux = aux->prev;
                auxIndex--;
            }
            aux->data = data;
            
            }
    } else {
        throw out_of_range("ERROR");
    }
}

template <class T>
int DoublyLinkedList<T>::findData(T data){
    DNode<T>* aux = head;
    int auxIndex = 0;
    while(aux != nullptr){
        if (data == aux->data){
            return auxIndex;
        } else {
            aux = aux->next;
            auxIndex++;
        }
    }
    return -1;
}

template <class T>
T& DoublyLinkedList<T>::operator[](const int& index){
    if (index >= 0 && index < size){
        if (index <= (size-1) / 2) {
            int auxIndex = 0;
            DNode<T>* aux = head;
            
            while (auxIndex != index){
                aux = aux->next;
                auxIndex++;
            }
            return aux->data;            
        } else {
            int auxIndex = size-1;
            DNode<T>* aux = tail;

            while (auxIndex != index) {
                aux = aux->prev;
                auxIndex--;
            }
            return aux->data;
        }
    } else {
        throw out_of_range("ERROR");
    }
}

template <class T>
void DoublyLinkedList<T>::operator=(const DoublyLinkedList& newList){
    if (this == &newList) {
        return;
    }

    while(head != nullptr) {
        DNode<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
    }

    DNode<T>* newListNode = newList.head;
    while (newListNode != nullptr) {
        this->addLast(newListNode->data);
        newListNode = newListNode->next;
    }
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

template <class T>
void DoublyLinkedList<T>::clear(){
   
    while(head != nullptr) {
        DNode<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
    }

}

template <class T>
int DoublyLinkedList<T>::getSize(){
    return size;
}

template<class T>
void DoublyLinkedList<T>::sort() {
    bool swapped;
    DNode<T>* current;
    DNode<T>* last = nullptr;

    if (isEmpty())
        return;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data.keyFH > current->next->data.keyFH) {
                // Intercambiar los datos de los nodos
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

template <class T>
void DoublyLinkedList<T>::duplicate(){
    if (!isEmpty()){
        DNode<T>* aux = head;
        T auxData;
        int auxIndex = 0;

        while(aux != nullptr){
            auxData = aux->data;
            aux = aux->next;
            insert(auxIndex,auxData);
            auxIndex = auxIndex + 2;
        }

    } else {
        throw out_of_range("La lista está vacía");
    }
}

template <class T>
void DoublyLinkedList<T>::removeDuplicates(){
    if (!isEmpty()){
        DNode<T>* aux = head;
        int auxIndex = 0;

        while(aux != nullptr){
            aux = aux->next->next;
            deleteAt(auxIndex);
            auxIndex++;
        }

    } else {
        throw out_of_range("La lista está vacía");
    }
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

template <class T>
void DoublyLinkedList<T>::swap(DNode<T>* a, DNode<T>* b){
    T auxData;
    auxData = a->data;
    a->data = b->data;
    b->data = auxData;
}

template<class T>
DNode<T>* DoublyLinkedList<T>::getPivot(DNode<T>* left, DNode<T>* right,int data) {
    
    // Creamos un indice i en left - 1
    DNode<T>* i = left->prev;

    if (data == 1){
        // Definimos el pivote
        long pivot = right->data.keyFH;

        // Iteramos la lista desde left hasta right -1
        for(DNode<T>* j = left; j != right; j=j->next){
            // COmparamos el valor de index con el valor del pivot
            if (j->data.keyFH < pivot){
                // Incrementamos el índice auxiliar
                i = (i == nullptr) ? left : i->next;
                swap(i, j);
            }
        }
    } else if (data == 2){
        // Definimos el pivote
        string pivot = right->data.keyIP;

        // Iteramos la lista desde left hasta right -1
        for(DNode<T>* j = left; j != right; j=j->next){
            // COmparamos el valor de index con el valor del pivot
            if (j->data.keyIP < pivot){
                // Incrementamos el índice auxiliar
                i = (i == nullptr) ? left : i->next;
                swap(i, j);
            }
        }
    }

    // Incrementamos el índice auxiliar
    i = (i == nullptr) ? left : i->next;
    // Intercambiamos el indice auxiliar con el pivot
    swap(i, right);    
    // Regresamoe el indice auxliar
    return i;
}

// MÉTODO DE QUICK SORT
template<class T>
void DoublyLinkedList<T>::quickSort(DNode<T>* left, DNode<T>* right,int data) {
    if(right != nullptr && left != right && left != right->next) {
        // Obtenemos la posición final del privote
        DNode<T>* pivot = getPivot(left, right, data);
        // Ordenamos la lista del lado izquierdo
        quickSort(left, pivot->prev, data);
        // Ordenamos la lista del lado derecho
        quickSort(pivot->next, right, data);
    }
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

template <class Log>
void DoublyLinkedList<Log>::print(string mode){
    if (mode == "asc"){
        // Definimos un apuntador de tipo de nodo igual a head;
        DNode<Log>* aux = head;
        while (aux != nullptr)
        {
            // Imprimimos el valor del nodo
            //cout << x << ": " << aux->data.keyIP << endl;
            cout << aux->data.month << " " << aux->data.day << " " <<aux->data.year << " " << aux->data.time << " " << aux->data.ip << " " << aux->data.message << endl;
            // Asignamos a aux el valor de next de aux
            aux = aux->next;
        }
        // Imprimimos un salto de linea
        cout << endl;
    } else {
        // Definimos un apuntador de tipo de nodo igual a tail;
        DNode<Log>* aux = tail;
        while (aux != nullptr)
        {
            // Imprimimos el valor del nodo
            cout << aux->data.month << " " << aux->data.day << " " <<aux->data.year << " " << aux->data.time << " " << aux->data.ip << " " << aux->data.message << endl;
            // Asignamos a aux el valor de next de aux
            aux = aux->prev;
        }
        // Imprimimos un salto de linea
        cout << endl;
    }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void DoublyLinkedList<T>::getKeyIp(DNode<T>* node){
    while (node != nullptr){
        cout << node->data.keyIP << endl;
        node = node->next;
    }
}

#endif /* DoublyLinkedList_h */
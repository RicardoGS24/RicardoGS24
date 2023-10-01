#ifndef Stack_h
#define Stack_h
#include "Node.h"

template <class T>
class Stack {
    private:
        Node<T>* top;
    public:
        Stack();
        void push(T data); // Agrega un elemento arriba de la pila
        void pop();  // Elimina el elemento de arriba de la pila
        T top();    // regresa el valor de elemento de arriba de la pila
        bool isEmpty(); // regresa si la pila está vacía
};

template <class T>
Stack<T>::Stack(){

}

template <class T>
void Stack<T>::push(T data){
    
}


#endif
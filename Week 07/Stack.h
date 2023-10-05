#ifndef stack_h
#define stack_h

#include <iostream>
#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
    int size;

public:
    Stack();

    void pop();
    void push(T data);
    T top();

    bool isEmpty();
    void print();
    
};

template <class T>
Stack<T>::Stack() {
    head = nullptr;
    size = 0;
}

//-----------------------------------------------

template <class T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        Node<T>* aux = head;
        head = head -> next;
        delete aux; 
        size--;        
    } else {
        throw out_of_range("No se puede borrar - La Pila está vacía");
    }
}

template <class T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
T Stack<T>::top() {
    if (!isEmpty()) {
        return head -> data;
    } else {
        throw out_of_range("No hay datos en la Pila");
    }
}

//-----------------------------------------------

template <class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::print(){
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;
        if (aux->next != nullptr)
        {
            cout << " -> ";
        }
        aux = aux->next;
    }
    cout << endl;
}

#endif
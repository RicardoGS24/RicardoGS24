#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();

    void pop();
    void push (T data);
    T front();

    bool isEmpty();
    void print();
};

template <class T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
} 

// ------------------------------------------------

template <class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* aux = head;
        head = head -> next;
        delete aux;         
    } else {
        throw out_of_range("No se puede borrar - No hay datos en el Queue");
    }
}

template <class T>  
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (!isEmpty()) {
        tail -> next = newNode;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
}

template <class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head -> data;
    } else {
        throw out_of_range("No hay datos en el Queue");
    }
}

// ------------------------------------------------

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Queue<T>::print(){
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
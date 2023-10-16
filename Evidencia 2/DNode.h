#pragma once

#include "Log.h"

template <class T>
struct DNode {

    Log data;
    DNode<T>* next;
    DNode<T>* prev;
    DNode();
    DNode(T data);
    DNode(T data, DNode<T>* next, DNode<T>* prev);

};

template<class T>
DNode<T>::DNode() {
    data = nullptr; // <----------
    next = nullptr;
    prev = nullptr;
}

template<class T>
DNode<T>::DNode(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
DNode<T>::DNode(T data, DNode<T>* next, DNode<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}

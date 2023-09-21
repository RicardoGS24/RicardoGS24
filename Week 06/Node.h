// DEFINICIÓN DE UNA ESTRUCTURA
#pragma once

template <class T>
struct Node {
    
    T data;
    Node<T>* next;
    Node();
    Node(T data);
    Node(T data, Node<T>* next);

};

template <class T>
Node<T>::Node(){
    // No hay nada, en una estructura no es necesario
    //cout << "Constructor por default" << endl;
    next = nullptr;
}

template <class T>
Node<T>::Node(T data){
    this-> data = data;
    this-> next = nullptr;
}

template <class T>
Node<T>::Node(T data, Node<T>* next){
    this -> data = data;
    this -> next = next;
}

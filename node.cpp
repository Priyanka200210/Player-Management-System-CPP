#include "node.h"
template<class T>	
Node<T>::Node(T d){
     this->data = d;
     this->prev = NULL;
     this->next = NULL;
}

template<class T>
void Node<T>::setData(T d){
     this->data = d;
}

template<class T>
void Node<T>::setNext(Node<T>* n){
     this->next = n;
}

template<class T>
void Node<T>::setPrev(Node<T>* p){
	this->prev = p;
}

template<class T>
T Node<T>::getData(){
     return data;
}

template<class T>
Node<T>* Node<T>::getNext(){
     return next;
}

template<class T>
Node<T>* Node<T>::getPrev(){
	return prev;
}
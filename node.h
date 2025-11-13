#include "player.h"
#include<iostream>
using namespace std;
template<class T>	
class Node{
     T data;
     Node<T>*prev;
	 Node<T>*next;

     public:
     Node(T);
     void setData(T);	
     T	getData();
     void setPrev(Node<T>*);
     Node<T>* getPrev();
     void setNext(Node<T>*);
     Node<T>* getNext();
};
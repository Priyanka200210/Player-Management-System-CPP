#include "node.h"

Node::Node(Player& d){
     this->data = d;
     this->prev = NULL;
     this->next = NULL;
}

void Node::setData(Player d){
     this->data = d;
}

void Node::setNext(Node* n){
     this->next = n;
}

void Node::setPrev(Node* p){
	this->prev = p;
}

Player Node::getData(){
     return data;
}

Node* Node::getNext(){
     return next;
}

Node* Node::getPrev(){
	return prev;
}
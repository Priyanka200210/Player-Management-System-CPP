#include "player.h"
#include<iostream>
using namespace std;

class Node{
     Player data;
     Node *prev,*next;

     public:
     Node(Player&);
     void setData(Player);
     Player getData();
     void setPrev(Node*);
     Node* getPrev();
     void setNext(Node*);
     Node* getNext();
};
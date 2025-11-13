#include "node.h"
#include<iostream>
using namespace std;

class DoublyLinkedList{
     Node* start;

     public:
     DoublyLinkedList();
     void addData(Player&,int);
     void deleteData();
     void display();
     void search();
     Node* searchByData(int);
     Node* searchByJersyNo(int);
     Node* searchByName(const char*);
     Node* searchByRuns(int);
     Node* searchByWickets(int);
     Node* searchByMatchesPlayed(int);
     void sorting();
     void sortByJersyNo();
     void sortByWickets();
     void sortByRuns();
     void sortByMatchesPlayed();
	 void descSortByJersyNo();
	 void descSortByWickets();
	 void descSortByRuns();
	 void descSortByMatchesPlayed();
     void updatePlayerData();
     void updateByRuns(Node*,int);
     void updateByWickets(Node*,int);
     void updateByMatchesPlayed(Node*,int);
	~DoublyLinkedList();

};
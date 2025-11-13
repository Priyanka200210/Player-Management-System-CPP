#include "node.cpp"
#include<iostream>			
using namespace std;

template<class T>	
class DoublyLinkedList{
     Node<T>* start;

     public:
     DoublyLinkedList();
     void addData(T,int);
     void deleteData();
     void display();
     void search();
     Node<T>* searchByData(int);
     Node<T>* searchByJersyNo(int);
     Node<T>* searchByName(const char*);
     Node<T>* searchByRuns(int);
     Node<T>* searchByWickets(int);
     Node<T>* searchByMatchesPlayed(int);
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
     void updateByRuns(Node<T>*,int);
     void updateByWickets(Node<T>*,int);
     void updateByMatchesPlayed(Node<T>*,int);
     void readFile(char* fn);
     void writeFile(char* fn);
	~DoublyLinkedList();

};
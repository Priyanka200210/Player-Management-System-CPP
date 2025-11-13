#include "linked_List.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
     this->start = NULL;
}

/***************************************************************************/
/////////////////////  START ADD DATA ///////////////////////////
template<class T>
void DoublyLinkedList<T>::addData(T data,int position){
	Node<T>* temp = new Node<T>(data);
	if(start == NULL){
		start = temp;
		return;
	}
		
	if(position == 1){
		temp->setNext(start);
		start->setPrev(temp);
		start = temp;
		return;
	}
	
	 Node<T>* p = start;
     int i=1;
     while( i<position-1 && p->getNext()!=NULL ){
          i++;
          p = p->getNext();
     }
     if(p->getNext()==NULL){
     	temp->setPrev(p);
     	p->setNext(temp);
	 }
	 else{
	 	temp->setPrev(p);
	 	temp->setNext(p->getNext());
	 	p->getNext()->setPrev(temp);
	 	p->setNext(temp);	
	 }
	
}
////////////////////// END ADD DATA /////////////////////////////////

/***************************************************************************/

///////////////////// START DISPLAY ///////////////////////////////////////
template<class T>
void DoublyLinkedList<T>::display(){
	if(start == NULL){
		cout<<"\nLinked List is empty!!"<<endl;
		return;
	}
	
     Node<T>* p = start;
     p->getData().displayHeaders();
     while(p!=NULL)
     {
//      cout<<p->getData()<<" ";
      p->getData().displayAllPlayers();
      p = p->getNext();
      
     }
}
////////////////////////////// END DISPLAY //////////////////////////////

/***************************************************************************/

///////////////////////////// START SEARCH /////////////////////////////
template<class T>
void DoublyLinkedList<T>::search(){
	Node<T>* q = start;
	if(start == NULL){
		cout<<"\nLinked List is Empty!!";
		return;
	}
	
	int choice;
    cout<<"\n1. Search by Jersy No\n2. Search by Player Name\n3. Search by Runs\n4. Search by Wickets\n5. Search By Matches Played\nEnter your choice:";
    cin>>choice;
     if(choice==1){
    	int jNo;
    	cout<<"Enter Jersy No: ";
    	cin>>jNo;
    	
     Node<T>* p = searchByJersyNo(jNo);
     
     if(p->getData().getJNo() == jNo){
    	 	p->getData().displayHeaders();
    	 	p->getData().displayAllPlayers();
    	 	return;
	 }	 
	 
	 if(p->getNext() == NULL){
        cout<<"\nData not found!!";
   	    return;
	  }	
	 
    if(p->getNext()->getData().getJNo() == jNo){
	     	    p->getData().displayHeaders();
		 	    p->getNext()->getData().displayAllPlayers();
		 	    return;
	  }
	  
	}
	else if(choice==2){
		char name[20];
		cout<<"Enter name of player: ";
		fflush(stdin);
		gets(name);
		
		Node<T>* p = searchByName(name);
		
		
		 
		if(strcasecmp(p->getData().getName(),name)==0){
	     	  p->getData().displayHeaders();
	     	  p->getData().displayAllPlayers();
	     	  return;
		}
		
		if(p->getNext()==NULL){
    	 	 cout<<"\nData not found!!";
    	 	 return;
		}
		
		if(strcasecmp(p->getNext()->getData().getName(),name)== 0){
			    p->getData().displayHeaders();
		 	    p->getNext()->getData().displayAllPlayers();
		}
		
		
	}
	else if(choice==3){
		int runs;
    	cout<<"Enter No of Runs made: ";
    	cin>>runs;
    	
    	 Node<T>* p = searchByRuns(runs);
    	
		 
    	 if(p->getData().getRuns() == runs){
    	 	p->getData().displayHeaders();
    	 	p->getData().displayAllPlayers();
    	 	return;
		 }
		 
		  if(p->getNext()==NULL){
    	 	 cout<<"\nData not found!!";
    	 	 return;
		  }
		 
    	 if(p->getNext()->getData().getRuns() == runs){
	     	    p->getData().displayHeaders();
		 	    p->getNext()->getData().displayAllPlayers();
		 }
    	
    	 
	}
	else if(choice == 4){
		int wickets;
    	cout<<"Enter No of wickets taken: ";
    	cin>>wickets;
    	
    	 Node<T>* p = searchByWickets(wickets);
    	
		 
    	 if(p->getData().getWickets() == wickets){
    	 	p->getData().displayHeaders();
    	 	p->getData().displayAllPlayers();
    	 	return;
		 }
		 
		  if(p->getNext()==NULL){
    	 	 cout<<"\nData not found!!";
    	 	 return;
		 }
		 
    	 if(p->getNext()->getData().getWickets() == wickets){
	     	    p->getData().displayHeaders();
		 	    p->getNext()->getData().displayAllPlayers();
		 }
	}
	else if(choice == 5){
		int MatchesPlayed;
    	cout<<"Enter No of Matches Played: ";
    	cin>>MatchesPlayed;
    	
    	 Node<T>* p = searchByMatchesPlayed(MatchesPlayed);
    	 
		 
    	 if(p->getData().getMatchPlayed() == MatchesPlayed){
    	 	p->getData().displayHeaders();
    	 	p->getData().displayAllPlayers();
    	 	return;
		 }
		 
		 if(p->getNext()==NULL){
    	 	 cout<<"\nData not found!!";
    	 	 return;
		 }
		 
    	 if(p->getNext()->getData().getMatchPlayed() == MatchesPlayed){
	     	    p->getData().displayHeaders();
		 	    p->getNext()->getData().displayAllPlayers();
		 }
    	
	}
	else{
		cout<<"\nInvalid Choice!!"<<endl;
	}
	
}

////////////////////////// START SEARCH BY JERSY NO ///////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByJersyNo(int jNo){
	Node<T>* p = start;	
	if(p->getData().getJNo() == jNo){
		return p;
	}
	
	while(p->getNext()!=NULL && p->getNext()->getData().getJNo()!=jNo){
			p = p->getNext();
	}
				
	return p;
}
//////////////////// END SEARCH BY JERSY NO ///////////////////////////////

///////////////////// START SEARCH BY NAME //////////////////////////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByName(const char* data){
		if(start == NULL){
			return NULL;
		}
		   
		Node<T>* p = start;
		if(strcasecmp(p->getData().getName(),data)==0){
			return p;
		}
		while(p->getNext()!=NULL && strcasecmp(p->getNext()->getData().getName(),data)!=0){
			p = p->getNext();
		}
		
		return p;
}
///////////////////////// END SEARCH BY NAME ///////////////////////////////////////////////

////////////////////////// START SEARCH BY RUNS ////////////////////////////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByRuns(int runs){
		if(start == NULL){
			return NULL;
		}
		   
		Node<T>* p = start;
		if(p->getData().getRuns()== runs){
		 return p;
		}
		
		
		while(p->getNext()!=NULL && p->getNext()->getData().getRuns()!=runs){
			p = p->getNext();
		}
		
		return p;
}
//////////////////////////// END SEARCH BY RUNS ///////////////////////////////////////////

//////////////////////////// START SEARCH BY WICKETS //////////////////////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByWickets(int wickets){
			if(start == NULL){
			return NULL;
		}
		   
		Node<T>* p = start;
		if(p->getData().getWickets()== wickets){
		 return p;
		}
		
		
		while(p->getNext()!=NULL && p->getNext()->getData().getWickets()!=wickets){
			p = p->getNext();
		}
		
		return p;
}
///////////////////////////// END SEARCH BY WICKETS//////////////////////////////////////////////////////

/////////////////////////////// START SEARCH BY MATCHES PLAYED /////////////////////////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByMatchesPlayed(int matchesPlayed){
			if(start == NULL){
			return NULL;
		}
		   
		Node<T>* p = start;
		if(p->getData().getMatchPlayed()== matchesPlayed){
		 return p;
		}
		
		
		while(p->getNext()!=NULL && p->getNext()->getData().getMatchPlayed()!=matchesPlayed){
			p = p->getNext();
		}
		
		return p;
}
/////////////////////////////// END SEARCH BY MATCHES PLAYED /////////////////////////////////////////
/////////////////////////////// END SEARCH ///////////////////////////////////////////////////////////

/***************************************************************************************************/


////////////////////////  START SORT ///////////////////////////////////////////////////////////////
template<class T>
void DoublyLinkedList<T>::sorting(){
	if(start == NULL){
		cout<<"\nLinked List is empty!!";
		return;
	}
	
	int choice,ch;
	cout<<"\n1. Sort By Ascending: \n2. Sort By Descending: \nEnter your choice: ";
	cin>>ch;

	
	cout<<"\n1. Sort by Jersy No\n2. Sort by Wickets\n3. Sort by Runs\n4. Sort by Matches Played\nEnter your choice:";
	cin>>choice;
	
	if(choice == 1){
		if(ch==1){
			sortByJersyNo();
		}
		else{
			descSortByJersyNo();
		}
	    	
	}
	else if(choice == 2){
		if(ch==1){
			sortByWickets();	
		}
		else{
			descSortByWickets();
		}	
	
	}
	else if(choice == 3){
		if(ch==1){
			sortByRuns();
		}
		else{
			descSortByRuns();
		}
		
	}
	else if(choice == 4){
		if(ch==1){
			sortByMatchesPlayed();	
		}
		else{
			descSortByMatchesPlayed();
		}
	     
	}
	else{
		cout<<"\nInvalid Choice!!";
	}
}
	


//////////////////////// ASCENDING SORT ///////////////////////////////////

/*********************   JERSY NO  **************************************/
template<class T>
void DoublyLinkedList<T>::sortByJersyNo(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getJNo() > q->getData().getJNo()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
	
}

/*********************  WICKETS  **************************************/
template<class T>
void DoublyLinkedList<T>::sortByWickets(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getWickets() > q->getData().getWickets()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}

/*********************   RUNS  **************************************/
template<class T>
void DoublyLinkedList<T>::sortByRuns(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getRuns() > q->getData().getRuns()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}

/*********************   MATCHES PLAYED  **************************************/
template<class T>
void DoublyLinkedList<T>::sortByMatchesPlayed(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getMatchPlayed() > q->getData().getMatchPlayed()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}
////////////////////////////// END //////////////////////////////////////////////


//////////////////////////// DESCENDING SORT  ////////////////////////////////////


/*********************   JERSY NO  **************************************/
template<class T>
void DoublyLinkedList<T>::descSortByJersyNo(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getJNo() < q->getData().getJNo()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
}

/*********************   WICKETS  **************************************/
template<class T>
void DoublyLinkedList<T>::descSortByWickets(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getWickets() < q->getData().getWickets()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}

/*********************   RUNS  **************************************/
template<class T>
void DoublyLinkedList<T>::descSortByRuns(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getRuns() < q->getData().getRuns()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}

/*********************   MATCHES PLAYED  **************************************/
template<class T>
void DoublyLinkedList<T>::descSortByMatchesPlayed(){
	int flag = 0;
	Node<T>* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node<T>* q = p->getNext();q!=NULL;q = q->getNext()){
			if(p->getData().getMatchPlayed() < q->getData().getMatchPlayed()){
				Player temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);					
			}
		}
		p->getData().displayAllPlayers();
	}
	
}
///////////////////////////// END SORT  /////////////////////////////////////////////////////////

/***********************************************************************************************/

/////////////////////////////// START UPDATE /////////////////////////////////////////////////////////
template<class T>
void DoublyLinkedList<T>::updatePlayerData(){
	Node<T>* p = start;
	if(start == NULL){
		cout<<"\nLinked List is empty!!"<<endl;
		return;
	}
	
	int jNo;
	cout<<"\nEnter jersy No: ";
	cin>>jNo;
	
	Node<T>* q = searchByJersyNo(jNo);
	if( q->getNext() == NULL && q->getData().getJNo() != jNo){
		cout<<"\nData not found!!"<<endl;
		return;
	}
		
	int choice;
	cout<<"\n1. Update by Runs\n2. Update by Wickets\n3. Update by MatchesPlayed\nEnter your choice: ";
	cin>>choice;
	
	if(choice == 1 || choice == 2 || choice == 3)
	{
		if(choice == 1){
			updateByRuns(q,jNo);	
		} 
		else if(choice == 2){
		    updateByWickets(q,jNo);
		}
		else if(choice == 3){
		    updateByMatchesPlayed(q,jNo);
		}
	}
	else{
		cout<<"\nInvalid Choice!!";
	}
	

		
}

template<class T>
void DoublyLinkedList<T>::updateByRuns(Node<T>* q,int jNo){
	    int runs;
		cout<<"\nEnter runs to update: ";
		cin>>runs;
		
		Player p1(q->getData().getJNo(),q->getData().getName(),runs,q->getData().getWickets(),q->getData().getMatchPlayed());
		if(q->getData().getJNo() == jNo){
			Node<T>* r = start;
			r->setData(p1);
			cout<<"\nData Updated Successfully!!";
       		return;
		}
		
		q = q->getNext();
		Player p2(q->getData().getJNo(),q->getData().getName(),runs,q->getData().getWickets(),q->getData().getMatchPlayed());
	    q->setData(p2);

		cout<<"\nData Updated Successfully!!";	
}

template<class T>
void DoublyLinkedList<T>::updateByWickets(Node<T>* q,int jNo){
	    int wickets;
		cout<<"\nEnter wickets to update: ";
		cin>>wickets;
		
		Player p1(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),wickets,q->getData().getMatchPlayed());
		if(q->getData().getJNo() == jNo){
			Node<T>* r = start;
			r->setData(p1);
			cout<<"\nData Updated Successfully!!";
       		return;
		}
		
		q = q->getNext();
		Player p2(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),wickets,q->getData().getMatchPlayed());
	    q->setData(p2);

		cout<<"\nData Updated Successfully!!";	
}

template<class T>
void DoublyLinkedList<T>::updateByMatchesPlayed(Node<T>* q,int jNo){
	    int mPlayed;
		cout<<"\nEnter Matches Played to update: ";
		cin>>mPlayed;
		
		Player p1(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),q->getData().getWickets(),mPlayed);
		if(q->getData().getJNo() == jNo){
			Node<T>* r = start;
			r->setData(p1);
			cout<<"\nData Updated Successfully!!";
       		return;
		}
		
		q = q->getNext();
		Player p2(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),q->getData().getWickets(),mPlayed);
	    q->setData(p2);

		cout<<"\nData Updated Successfully!!";	
}
////////////////////////// END UPDATE ////////////////////////////////////////////////

/***************************************************************************/

//////////////////  START DELETE  ///////////////////////////////////////////
template<class T>
void  DoublyLinkedList<T>::deleteData(){
	if(start == NULL){
		cout<<"\nLinked List is empty!!";
		return;
	}
	int jNo;
	cout<<"\nEnter Jersy No: ";
	cin>>jNo;
	
	if(start->getData().getJNo() == jNo){
		Node<T>* p = start;
		start = p->getNext();
		delete p;
		cout<<"Data Deleted Successfully!!";
		return;
	}
	
	Node<T>* p = searchByData(jNo);

	if(p->getNext()==NULL){
		cout<<"Data not found!!";
		return;
	}
	
	Node<T>* q = p->getNext();
	p->setNext(q->getNext());
	delete q;
	cout<<"Data Deleted Successfully!!";
	
	
}
//////////////////  END DELETE  ///////////////////////////////////////////

///////////////// START SEARCH BY DATA /////////////////////////////////////////
template<class T>
Node<T>* DoublyLinkedList<T>::searchByData(int data){
	Node<T>* p = start;
		while(p->getNext()!=NULL && p->getNext()->getData().getJNo()!=data){
		p = p->getNext();
	}
	return p;
}
///////////////// END SEARCH BY DATA///////////////////////////

/***************************************************************************/

/////////////////// START DESTRUCTOR ///////////////////////////////
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	if(start!=NULL){
		Node<T>* p = start->getNext();
		while(p!=NULL){
			delete start;
			start = p;
			p = start->getNext();
		}
		delete start;
	}

}
///////////////	//////// END DESTRUCTOR //////////////////////////////////////
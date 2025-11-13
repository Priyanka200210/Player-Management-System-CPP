#include "linked_List.h"

DoublyLinkedList::DoublyLinkedList(){
     this->start = NULL;
}

/***************************************************************************/
/////////////////////  START ADD DATA ///////////////////////////
void DoublyLinkedList::addData(Player& data,int position){
	Node* temp = new Node(data);
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
	
	 Node* p = start;
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
void DoublyLinkedList::display(){
	if(start == NULL){
		cout<<"\nLinked List is empty!!"<<endl;
		return;
	}
	
     Node* p = start;
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
void DoublyLinkedList::search(){
	Node* q = start;
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
    	
     Node* p = searchByJersyNo(jNo);
     
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
		
		Node* p = searchByName(name);
		
		
		 
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
    	
    	 Node* p = searchByRuns(runs);
    	
		 
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
    	
    	 Node* p = searchByWickets(wickets);
    	
		 
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
    	
    	 Node* p = searchByMatchesPlayed(MatchesPlayed);
    	 
		 
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
Node* DoublyLinkedList::searchByJersyNo(int jNo){
	Node* p = start;	
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
Node* DoublyLinkedList::searchByName(const char* data){
		if(start == NULL){
			return NULL;
		}
		   
		Node* p = start;
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
Node* DoublyLinkedList::searchByRuns(int runs){
		if(start == NULL){
			return NULL;
		}
		   
		Node* p = start;
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
Node* DoublyLinkedList::searchByWickets(int wickets){
			if(start == NULL){
			return NULL;
		}
		   
		Node* p = start;
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
Node* DoublyLinkedList::searchByMatchesPlayed(int matchesPlayed){
			if(start == NULL){
			return NULL;
		}
		   
		Node* p = start;
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
void DoublyLinkedList::sorting(){
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
void DoublyLinkedList::sortByJersyNo(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::sortByWickets(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::sortByRuns(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::sortByMatchesPlayed(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::descSortByJersyNo(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::descSortByWickets(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::descSortByRuns(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::descSortByMatchesPlayed(){
	int flag = 0;
	Node* p = start;
	while(flag==0){
		p->getData().displayHeaders();
		flag=1;
	}
	for(;p!=NULL;p=p->getNext()){
		for(Node* q = p->getNext();q!=NULL;q = q->getNext()){
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
void DoublyLinkedList::updatePlayerData(){
	Node* p = start;
	if(start == NULL){
		cout<<"\nLinked List is empty!!"<<endl;
		return;
	}
	
	int jNo;
	cout<<"\nEnter jersy No: ";
	cin>>jNo;
	
	Node* q = searchByJersyNo(jNo);
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

void DoublyLinkedList::updateByRuns(Node* q,int jNo){
	    int runs;
		cout<<"\nEnter runs to update: ";
		cin>>runs;
		
		Player p1(q->getData().getJNo(),q->getData().getName(),runs,q->getData().getWickets(),q->getData().getMatchPlayed());
		if(q->getData().getJNo() == jNo){
			Node* r = start;
			r->setData(p1);
			cout<<"\nData Updated Successfully!!";
       		return;
		}
		
		q = q->getNext();
		Player p2(q->getData().getJNo(),q->getData().getName(),runs,q->getData().getWickets(),q->getData().getMatchPlayed());
	    q->setData(p2);

		cout<<"\nData Updated Successfully!!";	
}

void DoublyLinkedList::updateByWickets(Node* q,int jNo){
	    int wickets;
		cout<<"\nEnter wickets to update: ";
		cin>>wickets;
		Player p1(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),wickets,q->getData().getMatchPlayed());
		if(q->getData().getJNo() == jNo){
			Node* r = start;
			r->setData(p1);
			cout<<"\nData Updated Successfully!!";
       		return;
		}
		
		q = q->getNext();
		Player p2(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),wickets,q->getData().getMatchPlayed());
	    q->setData(p2);

		cout<<"\nData Updated Successfully!!";	
}

void DoublyLinkedList::updateByMatchesPlayed(Node* q,int jNo){
	    int mPlayed;
		cout<<"\nEnter Matches Played to update: ";
		cin>>mPlayed;
		
		Player p1(q->getData().getJNo(),q->getData().getName(),q->getData().getRuns(),q->getData().getWickets(),mPlayed);
		if(q->getData().getJNo() == jNo){
			Node* r = start;
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
void  DoublyLinkedList::deleteData(){
	if(start == NULL){
		cout<<"\nLinked List is empty!!";
		return;
	}
	int jNo;
	cout<<"\nEnter Jersy No: ";
	cin>>jNo;
	
	if(start->getData().getJNo() == jNo){
		Node* p = start;
		start = p->getNext();
		delete p;
		cout<<"Data Deleted Successfully!!";
		return;
	}
	
	Node* p = searchByData(jNo);

	if(p->getNext()==NULL){
		cout<<"Data not found!!";
		return;
	}
	
	Node* q = p->getNext();
	p->setNext(q->getNext());
	delete q;
	cout<<"Data Deleted Successfully!!";
	
	
}
//////////////////  END DELETE  ///////////////////////////////////////////

///////////////// START SEARCH BY DATA /////////////////////////////////////////
Node* DoublyLinkedList::searchByData(int data){
	Node* p = start;
		while(p->getNext()!=NULL && p->getNext()->getData().getJNo()!=data){
		p = p->getNext();
	}
	return p;
}
///////////////// END SEARCH BY DATA///////////////////////////

/***************************************************************************/

/////////////////// START DESTRUCTOR ///////////////////////////////
DoublyLinkedList::~DoublyLinkedList(){
	if(start!=NULL){
		Node* p = start->getNext();
		while(p!=NULL){
			delete start;
			start = p;
			p = start->getNext();
		}
		delete start;
	}

}
/////////////////////// END DESTRUCTOR //////////////////////////////////////
#include "linked_List.cpp"
#include<iostream>
#include<string.h>
using namespace std;

int main(){	
	int choice,position;
	DoublyLinkedList<Player> l;	
	l.readFile("object.bin");
	char name[20];
    int jersyNo;
    int runs;
    int wickets;
    int matchPlayed;
	do{
		cout<<"\n1. Add Player Data\n2. Display All Players\n3. Search Player\n4. Remove Player\n5. Sort Players\n6. Update Player \n0. To exit\n Enter your choice:  ";
     	cin>>choice;
		 
		 switch(choice){
		 	case 1:{
		 		
                cout<<"\nEnter Jersy No: ";
                cin>>jersyNo;
                cout<<"\nEnter Name of Player: ";
                fflush(stdin);
                gets(name);
                cout<<"\nEnter Runs: ";
                cin>>runs;
                cout<<"\nEnter Wickets: ";
                cin>>wickets;
                cout<<"\nEnter No of matches played: ";
                cin>>matchPlayed;
                cout<<"\nEnter position to add Player data: ";
                cin>>position;
                
                Player p1(jersyNo,name,runs,wickets,matchPlayed);
                l.addData(p1,position);
                cout<<"\nPlayer Data Added Successfully!!"<<endl;
				break;
				
			 }
			 
			 case 2:{
			 	l.display();
				break;
			 }
			 
			 case 3:{
			 	l.search();
				break;
			 }
			 case 4:{
			    l.deleteData();
				break;
			 }
			 case 5:{
			 	 l.sorting();  
				break;
			 }
			 case 6:{
			 	l.updatePlayerData();
				break;
			 }
			 case 0:{
			 	 l.writeFile("object.bin");
			 	cout<<"\nThank You!!";
				break;
			 }
			 default:{
			 	cout<<"\nInvalid Choice!!"<<endl;
				break;
			 }
		 }	
		
	}while(choice!=0);
	
}
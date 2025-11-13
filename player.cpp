#include "player.h"
//#include "node.h"

Player::Player(){
	this->jersyNo = 0;
	strcpy(this->name,"Not Given");
	this->runs = 0;
	this->wickets = 0;
	this->matchPlayed = 0;
}

Player::Player(int jNO,const char* name,int runs,int wickets,int mPlayed){
	this->jersyNo = jNO;
	strcpy(this->name,name);
	this->runs = runs;
	this->wickets = wickets;
	this->matchPlayed = mPlayed;
}

void Player::setName(const char* n){
	strcpy(this->name,n);
}

void Player::setJNo(int j){
	this->jersyNo = j;
}

void Player::setRuns(int r){
	this->runs = r;
}

void Player::setWickets(int w){
    this->wickets = w;
}

void Player::setMatchesPlayed(int m){
	this->matchPlayed = m;
}

     	
const char* Player::getName(){
	return this->name;
}

int Player::getJNo(){
	return this->jersyNo;
}

int Player::getRuns(){
	return this->runs;
}

int Player::getWickets(){
	return this->wickets;
}

int Player::getMatchPlayed(){
	return this->matchPlayed;
}


bool Player::isEmpty(){
     if(index==-1)
          return true;
     return false;
}

bool Player::isFull(){
     return index == size-1;
}

void Player::displayAllPlayers(){

	 	printf("\n|  %11d  |  %27s | %15d | %14d | %16d|\n",this->jersyNo,this->name,this->runs,this->wickets,this->matchPlayed);
	 	cout<<"\n+---------------+------------------------------+-----------------+----------------+-----------------+\n";
}

Player Player::addPlayer(Player& player,int ctr){
	Player p;
	int flag;
	do{
		flag=0;
		cout<<"\nEnter the jersy no: ";
		cin>>p.jersyNo;
		for(int i=0;i<ctr;i++){
			if(player.getJNo() == p.jersyNo){
				cout<<"\nThis Jersy No is already exist!!"<<endl;
				flag=1;
				break;
			}
		}
	}while(flag==1);
	
	cout<<"\nEnter the Player Name: ";
	fflush(stdin);
	gets(p.name);
	cout<<"\nEnter Runs: ";
	cin>>p.runs;
	cout<<"\nEnter Wickets: ";
	cin>>p.wickets;
	cout<<"\nEnter no of matches played: ";
	cin>>p.matchPlayed;
	return p;	
}

//
//int Player::HardCodedValue(Player& player,int ctr){
//     Player p;
////     Node* p = start;
////     p.jersyNo = 18;
////     strcpy(p.name,"Virat Kohli");
////     p.runs = 12000;
////     p.wickets = 40;
////     p.matchPlayed = 403;
////     p->setData(p);
////     p = p->getNext();
////     ptr[ctr++] = p;
//	
////	 player.jersyNo = 18;
////     strcpy(player.name,"Virat Kohli");
////     player.runs = 12000;
////     player.wickets = 40;
////     player.matchPlayed = 403;
////     p->setData(p);
////     p = p->getNext();
//     ctr++;
////     p.jersyNo = 45;
////     strcpy(p.name,"Rohit Sharma");
////     p.runs = 11500;
////     p.wickets = 8;
////     p.matchPlayed = 254;
////     p->setData(p);
////     p = p->getNext();
//////     ptr[ctr++] = p;
////     
////     p.jersyNo = 7;
////     strcpy(p.name,"MS Dhoni");
////     p.runs = 10773;
////     p.wickets = 1;
////     p.matchPlayed = 420;
////     p->setData(p);
////     p = p->getNext();
//////     ptr[ctr++] = p;
////     
////     p.jersyNo = 10;
////     strcpy(p.name,"Sachin Tendulkar");
////     p.runs = 18426;
////     p.wickets = 8;
////     p.matchPlayed = 432;
////     p->setData(p);
////     p = p->getNext();
//////     ptr[ctr++] = p;
////     
////     p.jersyNo = 12;
////     strcpy(p.name,"Yuvraj Singh");
////     p.runs = 8701;
////     p.wickets = 6;
////     p.matchPlayed = 304;
////     p->setData(p);
////     p = p->getNext();
//////     ptr[ctr++] = p;
////     
//     
//     return ctr;
//     
//     
//}

void Player::displayHeaders(){
	 printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
     printf("\n|   Jersy No    |        Player Name           |     Runs        |    Wickets     |  Matches Played |\n" );
     printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
}

//void Player::display(Player& player,int res){
//		printf("\n|  %11d  |  %27s | %15d | %14d | %16d|\n",ptr[res].jersyNo,ptr[res].name,ptr[res].runs,ptr[res].wickets,ptr[res].matchPlayed);
//	 	printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
//}
//
//void Player::searchPlayer(Player& player,int ctr){
//	int ch;
//	printf("\n1. Search By Jersy No\n2. Search by Player Name\n Enter your choice: ");
//	scanf("%d",&ch);
//	if(ch==1){
//		int jNo;
//		cout<<"\nEnter the Jersy No: ";
//		cin>>jNo;
//		
//		int res = searchByJersyNo(player,jNo,ctr);
//		if(res==-1){
//			cout<<"\nPlayer not found!!";
//		}
//		else{
//			displayHeaders();
//			display(player,res);
//		}
//	}
//	else if(ch==2){
//		char name[20];
//		cout<<"\nEnter the Player Name: ";
//		fflush(stdin);
//		gets(name);
//		
//		int res = searchByJersyName(player,name,ctr);
//		if(res==-1){
//			cout<<"\nPlayer not found...";
//		}
//		else{
//			displayHeaders();
//			display(player,res);
//		}
//	}
//	else{
//		cout<<"\nInvalid Choice!!";
//	}
//}
//
//int Player::searchByJersyNo(Player& player,int JNo,int ctr){
//	for(int i=0;i<ctr;i++){
//		if(ptr[i].jersyNo==JNo){
//			return i;
//		}
//
//	}
//		return -1;
//}
//
//int Player::searchByJersyName(Player& player,char* name,int ctr){
//	for(int i=0;i<ctr;i++){
//		if(strcasecmp(ptr[i].name,name)==0){
//			return i;
//		}
//}
//	return -1;
//}
//
//void Player::deletePlayer(Player& player,int res,int ctr){
//		for(int i=res;i<ctr;i++){
//			ptr[i] = ptr[i+1];	
//		}
//}
//
//void Player::sortPlayer(Player& player,int ctr){
//		int ch;
//		cout<<"\n1. Sort by Jersy No\n2. Sort by Runs\n3. Sort by wickets\n4. Sort by match played\nEnter your choice: ";
//		cin>>ch;
//		
//		int cho;
//		if(ch>0 && ch<5){	
//			cout<<"\n1. Ascending\n2. Descending\nEnter your choice: ";
//			cin>>cho;
//			
//			if(ch==1){
//				if(cho==1){
//					AscSortByJersyNo(player,ctr);	
//				}
//				else if(cho==2){
//					DescSortByJersyNo(player,ctr);
//				}
//				else{
//					cout<<"\nInvalid Choice!!";
//				}
//			}
//			else if(ch==2){
//				if(cho==1){
//					AscSortByRuns(player,ctr);	
//				}
//				else if(cho==2){
//					DescSortByRuns(player,ctr);
//				}
//				else{
//					cout<<"\nInvalid Choice!!";
//				}
//			}
//			else if(ch==3){
//				if(cho==1){
//					AscSortByWickets(player,ctr);	
//				}
//				else if(cho==2){
//					DescSortByWickets(player,ctr);
//				}
//				else{
//					cout<<"\nInvalid Choice!!";
//				}
//			}
//			else if(ch==4){
//				if(cho==1){
//					AscSortByMatchesPlayed(player,ctr);	
//				}
//				else if(cho==2){
//					DescSortByMatchesPlayed(player,ctr);
//				}
//				else{
//					cout<<"\nInvalid Choice!!";
//				}
//			}
//		}
//		else{
//			 cout<<"\nInvalid Choice!!";
//		}
//}
//
//void Player::AscSortByJersyNo(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].jersyNo>ptr[j].jersyNo){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::DescSortByJersyNo(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].jersyNo<ptr[j].jersyNo){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		
//	}
//}
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//
//
//void Player::AscSortByRuns(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].runs >ptr[j].runs){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		
//	}
//	
//}
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::DescSortByRuns(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].runs<ptr[j].runs){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::AscSortByWickets(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].wickets>ptr[j].wickets){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::DescSortByWickets(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].wickets<ptr[j].wickets){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//
//
//void Player::AscSortByMatchesPlayed(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].matchPlayed>ptr[j].matchPlayed){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::DescSortByMatchesPlayed(Player& player,int ctr){
//	for(int i=0;i<ctr;i++){
//		for(int j=i+1;j<ctr;j++){
//			if(ptr[i].matchPlayed<ptr[j].matchPlayed){
//				Player temp = ptr[i];
//				ptr[i] = ptr[j];
//				ptr[j] = temp;
//			}
//		}
//	}
//	
//	cout<<"\nSorted Successfully!!";
//	displayAllPlayers(player,ctr);
//}
//
//void Player::updatePlayerData(Player& player,int ctr){
//		Player p;
//		cout<<"\nEnter Jersy No: ";
//		cin>>p.jersyNo;
//		
//		int res;		
//	   res = searchByJersyNo(player,p.jersyNo,ctr);
//	   if(res==-1){
//	   cout<<"\nInvalid Jersy No";
//	   }	
//	   else{
//	   	 	   int choice;
//               cout<<"\nWhat you want to update:";
//               cout<<"\n1. Update by Runs\n2. Update by Wickets\n3. Update by Matches Played\nEnter your choice: ";
//               cin>>choice;
//               
//               if(choice==1){
//               		cout<<"\nEnter Runs to update: ";
//               		cin>>p.runs;
//               		ptr[res].runs = p.runs; 
//               		cout<<"\nUpdated Successfully!!";
//			   }
//			   else if(choice==2){
//			   	    cout<<"\nEnter Wickets to update: ";
//               		cin>>p.wickets;
//               		ptr[res].wickets = p.wickets; 
//               		cout<<"\nUpdated Successfully!!";
//			   }
//			   else if(choice==3){
//			   		cout<<"\nEnter Matches Played to update: ";
//               		cin>>p.matchPlayed;
//               		ptr[res].matchPlayed = p.matchPlayed; 
//               		cout<<"\nUpdated Successfully!!";
//			   }
//			   else{
//			   	cout<<"\nInvalid Choice!!";
//			   }
//	   }
//}

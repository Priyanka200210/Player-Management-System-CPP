#include<iostream>
#include<string.h>
using namespace std;

class Player{
	 int size,index;
     Player* ptr;
     
	 char name[20];
     int jersyNo;
     int runs;
     int wickets;
     int matchPlayed;
     
     public:
     	Player();  
     	Player(int ,const char* ,int ,int ,int );
     	void setName(const char* );
     	void setJNo(int);
     	void setRuns(int);
     	void setWickets(int);
     	void setMatchesPlayed(int);
     	
     	const char* getName();
     	int getJNo();
     	int getRuns();
     	int getWickets();
     	int getMatchPlayed();
     	
     	bool isEmpty();
      	bool isFull();
      	
      	Player addPlayer(Player&,int);
      	
      	void displayHeaders();
      	void display(Player&,int res);

      	void displayAllPlayers();
	  	void searchPlayer(Player& ,int );
	  	int searchByJersyNo(Player& ,int ,int );
	  	int searchByJersyName(Player& ,char*,int);
	  	
	  	void deletePlayer(Player& ,int,int);
	  	
	  	void sortPlayer(Player&,int);
	  	
	  	void AscSortByJersyNo(Player& ,int);
	  	void DescSortByJersyNo(Player&,int );
	  	
	  	void AscSortByRuns(Player& ,int );		
	  	void DescSortByRuns(Player& ,int );
	  	
	  	void AscSortByWickets(Player& ,int );
	  	void DescSortByWickets(Player& ,int );
	  	
	  	void AscSortByMatchesPlayed(Player& ,int );
	  	void DescSortByMatchesPlayed(Player& ,int );
	  	
	  	void updatePlayerData(Player& ,int );
};

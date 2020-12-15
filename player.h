#ifndef PLAYER_H
#define PLAYER_H

#include "race.h"

class Player  
{
 public:
	void initialiseAttributes(int); //Based on input initialise player character attributes
	void showAttributes(); //Show player attributes 
	inline void GoldAdd(int GoldAddNum){gold+=GoldAddNum;}; //Adding gold to player 
	int attack(bool isNight); //Player attack function
	void defence(int &damage, bool isNight); //Player defence function
	int printGold(); //Function to print gold collected
	//void movePlayer(char direction);
	//int look();
	void alterStats(bool isNight); //Alter player stats based on time of the day
	int getPlayerHealth(); //Get player health
  
 private:
	Race playerRace;
	int gold;
   //inventory playerInventory;
};

#endif
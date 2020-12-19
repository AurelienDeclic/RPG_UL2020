#ifndef PLAYER_H
#define PLAYER_H

#include "race.h"
#include "inventory.h"
#include "item.h"

class Player  
{
 public:
	void initialiseAttributes(int); //Based on input initialise player character attributes
	void showAttributes(); //Show player initial attributes 
	inline void GoldAdd(int GoldAddNum){gold+=GoldAddNum;}; //Adding gold to player 
	int attack(bool isNight); //Player attack function
	void defence(int &damage, bool isNight); //Player defence function
	int printGold(); //Function to print gold collected
	void alterStats(bool isNight); //Alter player stats based on time of the day
	int getPlayerHealth(); //Get player health
	void itemPickup(armour); //Pickup armour
	void itemPickup(weapon); //Pickup weapon
	void itemPickup(shield); //Pickup shield
	void itemPickup(ring); //Pickup ring
	void itemDrop(); //Need to code this!
	void movePlayer(); //Need to code this probably!
	void showCurrentStats(); //Need to code this for position of the player, shows current attributes
	
  
 private:
	Race playerRace;
	int gold;
	inventory playerInventory;
	bool isItemPicked;
	
};

#endif
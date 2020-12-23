/**********************************************************
 * player.h 
 * Interface for the Player class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/


#ifndef PLAYER_H
#define PLAYER_H

//Including interface of other classes since it will be used in Player class
#include "race.h"
#include "inventory.h"
#include "item.h"

class Player  
{
 public:
	void initialiseAttributes(int input); //Based on input initialise player character attributes
	void showInitAttributes(); //Show player initial attributes 
	inline void GoldAdd(int GoldAddNum){gold+=GoldAddNum;}; //Adding gold to player 
	int attack(bool isNight); //Player attack function
	void defence(int &damage, bool isNight); //Player defence function
	inline int printGold(){return gold;}; //Function to print gold collected
	void alterStats(bool isNight); //Alter player race stats based on time of the day
	int getPlayerHealth(); //Get player health
	void itemPickup(armour); //Pickup armour and add to player inventory
	void itemPickup(weapon); //Pickup weapon and add to player inventory
	void itemPickup(shield); //Pickup shield and add to player inventory
	void itemPickup(ring); //Pickup ring and add to player inventory
	void itemDrop(); //Need to code this!
	void movePlayer(); //Need to code this probably!
	void showCurrentStats(); //Need to code this for position of the player, shows current attributes
	
  
 private:
	Race playerRace;
	inventory playerInventory;
	int gold; //Used for player gold.
	
};

#endif
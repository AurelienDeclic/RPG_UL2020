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
#include "../Race/race.h"
#include "inventory.h"
#include "../Item/item.h"

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
		void itemDrop(); //Drop item from inventory
		void movePlayer(char direction); //Move player co-ordinates: N,S,E,W
		void showCurrentStats(); //Shows player current attributes
		void updateStats(); //Function to update player Stats
		inline int getPlayerSTR(){return playerSTR;}; //Function to get current player Strength
		inline int getPlayerHP(){return playerHP;}; //Function to get current player race HP
		inline int getX(){return xCoord;}; //Function to provide player X co-ordinates
		inline int getY(){return yCoord;}; //Function to provide player Y co-ordinates.
  
	private:
		Race playerRace; //Player Race
		inventory playerInventory; //Player Inventory
		int gold; //Used for player gold.
		int playerHP; //Player Health points
		int playerSTR; //Player Strength
		int damageTaken; //DamageTaken by player
		int xCoord; // Player X coordinate, initialized in the center of the board from Xcoord to BoardSize-1
		int yCoord; // Player Y coordinate, same as above
};

#endif
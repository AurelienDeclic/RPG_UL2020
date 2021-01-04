/**********************************************************
 * Enemy.h 
 * Interface for the Enemy class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef ENEMY_H
#define ENEMY_H

#include "../Race/race.h"

class Enemy  
{
	public:
		Enemy(); //Enemy constructor
		~Enemy(); //Enemy destructor 
		void initialiseAttributes(); //Initialise enemy character attributes
		void showAttributes(); //Show enemy initial attributes
		int attack(bool isNight); //Enemy attack function
		void defence(int &damage, bool isNight); //Enemy defence function
		int getEnemyHealth(); //Function to get Enemy health
		int getDefenceValue(); //Function to get enemy defence value which gets added to player gold.
		void alterStats(bool isNight); //Function to alter enemy race stats based on time of the day.
		void showCurrentStats(); //Displays enemy current attributes
		void setCoordinates(int,int); // Set co-ordinates of enemy
        inline int getXCoordinates(){ return xCoord;}; //Get X co-ordinate of enemy
        inline int getYCoordinates(){return yCoord;}; //Get Y co-ordinate of enemy

	private:
		Race enemyRace; //Enemy Race
		int damageTaken; //DamageTaken by enemy
		int enemyHP; //Enemy health
		int xCoord; //X-co-ordinate
		int yCoord; //Y-co-ordinate
};

#endif
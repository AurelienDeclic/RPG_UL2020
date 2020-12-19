#ifndef ENEMY_H
#define ENEMY_H

#include "race.h"

class Enemy  
{
 public:
	Enemy(); //Enemy constructor
	void initialiseAttributes(); //Initialise enemy character attributes
	void showAttributes(); //Show enemy attributes
	int attack(bool isNight); //Enemy attack function
	void defence(int &damage, bool isNight); //Enemy defence function
	int getEnemyHealth(); //Function to get Enemy health
	int getDefenceValue(); //Function to get enemy defence value which gets added to player gold.
	void alterStats(bool isNight); //Function to alter enemy race stats based on time of the day.
  
 private:
	Race enemyRace;
};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#include "race.h"

class Player  
{
 public:
	void initialiseAttributes(int);
	void showAttributes();
	inline void GoldAdd(int GoldAddNum){gold+=GoldAddNum;};
	int attack(bool isNight);
	void defence(int &damage, bool isNight);
	int printGold();
	//void movePlayer(char direction);
	//int look();
	void alterStats(bool isNight);
	int getPlayerHealth();
  
 private:
	Race playerRace;
	int gold;
   //inventory playerInventory;
};

#endif
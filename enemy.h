#ifndef ENEMY_H
#define ENEMY_H

#include "race.h"

class Enemy  
{
 public:
	void initialiseAttributes();
	void showAttributes();
	int attack(bool isNight);
	void defence(int &damage, bool isNight);
	int getEnemyHealth();
	int getDefenceValue();
	void alterStats(bool isNight);
  
 private:
	Race enemyRace;
};

#endif
#include <cstdlib>
#include <time.h>
#include <iostream>

#include "weapon.h"

using namespace std;

weapon::weapon(){
  int NPossibleItems = 2;
  //srand(time(NULL));
  setStats(rand() % NPossibleItems +1);
}

weapon::weapon(int ID){
  int NpossibleItems = 2;
  if( 0 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(0); }
}

void weapon::setStats(int ID){
  switch(ID){
  case 0://"empty ID" for inventory
    name = "NONE";
    weight = 0;
    BonusAttack = 0;
    BonusDefense = 0;
    BonusHP = 0;
    BonusStrength = 0;
    break;
  case 1:
    //Sets stats for Sword
    name = "Sword (weapon)";
    weight = 10;
    BonusAttack = 10;
    BonusDefense = 0;
    BonusHP = 0;
    BonusStrength = 0;
    break;
  case 2:
    name = "Dagger (weapon)";
    weight = 5;
    BonusAttack = 5;
    BonusDefense = 0;
    BonusHP = 0;
    BonusStrength = 0;
  }
}

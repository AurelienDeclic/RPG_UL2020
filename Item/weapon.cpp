#include <cstdlib>
#include <time.h>
#include <iostream>

#include "weapon.h"

using namespace std;

//////////////////////////////////////////////////////////
//basic constructor for weapon
//creates a random item, with the database from SetStats() function.
/////////////////////////////////////////////////////////
weapon::weapon(){
  int NPossibleItems = 2;
  setStats(rand() % NPossibleItems +1);
}

/////////////////////////////////////////////////////////
//general constructor for the weapon objects
//creates an "EMPTY" weapon if prompted with anything else that is not described in the setStats function
/////////////////////////////////////////////////////////
weapon::weapon(int ID){
  int NpossibleItems = 2;
  if( 0 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(0); }
}

////////////////////////////////////////////////////////
//PRIVATE function setStats
//call the function with correct ID
//has the database from the program.
///////////////////////////////////////////////////////
void weapon::setStats(int ID){
  switch(ID){
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
    break;
  default: //default item is empty
    name = "NONE";
    weight = 0;
    BonusAttack = 0;
    BonusDefense = 0;
    BonusHP = 0;
    BonusStrength = 0;
  }
}

#include <cstdlib>
#include <time.h>
#include <iostream>
#include "armour.h"

using namespace std;

//////////////////////////////////////////////////////////
//basic constructor for armour
//creates a random item, with the database from SetStats() function.
/////////////////////////////////////////////////////////
armour::armour(){
  int NPossibleItems = 2;
  srand(static_cast<unsigned int>(time(NULL)));
  setStats(rand() % NPossibleItems +1);
}

/////////////////////////////////////////////////////////
//general constructor for the armour objects
//creates an "EMPTY" weapon if prompted with anything else that is not described in the setStats function
/////////////////////////////////////////////////////////
armour::armour(int ID){
  int NpossibleItems = 2;
  if( 1 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(0); }
}

////////////////////////////////////////////////////////
//PRIVATE function setStats
//call the function with correct ID
//has the database from the program.
///////////////////////////////////////////////////////
void armour::setStats(int ID){
  switch(ID){
  case 1:
    //Sets stats for Plate Armour
    name = "Plate Armour (armour)";
    weight = 40;
    BonusAttack = -5;
    BonusDefense = 10;
    BonusHP = 0;
    BonusStrength = 0;
    break;
  case 2:
    name = "Leather Armour (armour)";
    weight = 20;
    BonusAttack = 0;
    BonusDefense = 5;
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

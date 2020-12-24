#include <cstdlib>
#include <time.h>
#include "shield.h"

using namespace std;

//////////////////////////////////////////////////////////
//basic constructor for shield
//creates a random item, with the database from SetStats() function.
/////////////////////////////////////////////////////////
shield::shield(){
  int NPossibleItems = 2;
  setStats(rand() % NPossibleItems +1);
}

/////////////////////////////////////////////////////////
//general constructor for the shield objects
//creates an "EMPTY" weapon if prompted with anything else that is not described in the setStats function
/////////////////////////////////////////////////////////
shield::shield(int ID){
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
void shield::setStats(int ID){
  switch(ID){
  case 1:
    //Sets stats for Large Shield
    name = "Large shield (shield)";
    weight = 30;
    BonusAttack = -5;
    BonusDefense = 10;
    BonusHP = 0;
    BonusStrength = 0;
    break;
  case 2:
    name = "Small shield (shield)";
    weight = 10;
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

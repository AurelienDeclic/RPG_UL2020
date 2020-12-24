#include <cstdlib>
#include <time.h>
#include <iostream>

#include "ring.h"

using namespace std;

//////////////////////////////////////////////////////////
//basic constructor for ring
//creates a random item, with the database from SetStats() function.
/////////////////////////////////////////////////////////
ring::ring(){
  int NPossibleItems = 2; //Max possible items (2 rings are possible here)
  srand(static_cast<unsigned int>(time(NULL))); //initialise seed of rand() with current time
  setStats(rand() % NPossibleItems +1); //calls setStats function with the random number
}

/////////////////////////////////////////////////////////
//general constructor for the ring objects
//creates an "EMPTY" weapon if prompted with anything else that is not described in the setStats function
/////////////////////////////////////////////////////////
ring::ring(int ID){
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
void ring::setStats(int ID){
  switch(ID){
  case 1:
    //Sets stats for Ring of life
    name = "Ring of life (ring)";
    weight = 1;
    BonusAttack = 0;
    BonusDefense = 0;
    BonusHP = 10;
    BonusStrength = 0;
    break;
  case 2:
    name = "Ring of Strength (ring)";
    weight = 1;
    BonusAttack = 0;
    BonusDefense = 0;
    BonusHP = -10;
    BonusStrength = 50;
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

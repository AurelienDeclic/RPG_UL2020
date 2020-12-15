#include <cstdlib>
#include <time.h>
#include <iostream>

#include "ring.h"

//notes to debug: random seed should be initialised at the beggining of the program, so we have different rings everywhere. function has to be called with random value and general constructor ring(int)

using namespace std;

ring::ring(){ //constructor to get a random ring item
  int NPossibleItems = 2; //Max possible items (2 rings are possible here)
  //srand(time(NULL)); //initialise seed of rand() with current time
  setStats(rand() % NPossibleItems +1); //cals setStats function with the random number
}

ring::ring(int ID){ //general constructor
  int NpossibleItems = 2;
  if( 1 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(0); }
}

void ring::setStats(int ID){
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
  }
}

#include <cstdlib>
#include <time.h>
#include <iostream>

#include "armour.h"

using namespace std;

armour::armour(){
  int NPossibleItems = 2;
  //and(time(NULL));
  setStats(rand() % NPossibleItems +1);
}

armour::armour(int ID){
  int NpossibleItems = 2;
  if( 1 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(1); }
}

void armour::setStats(int ID){
  switch(ID){
  case 1:
    //Sets stats for Plate Armour
    name = "Plate Armour (armour)";
    weight = 40;
    BonusAttack = 5;
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
  }
}

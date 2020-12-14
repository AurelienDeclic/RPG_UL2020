#include <cstdlib>
#include <time.h>
#include "shield.h"

using namespace std;

shield::shield(){
  int NPossibleItems = 2;
  //srand(time(NULL));
  setStats(rand() % NPossibleItems +1);
}

shield::shield(int ID){
  int NpossibleItems = 2;
  if( 1 <= ID && ID <= NpossibleItems){
  setStats(ID);
  }else{ setStats(1); }
}

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
    BonusDefense = 10;
    BonusHP = 0;
    BonusStrength = 0;
  }
}

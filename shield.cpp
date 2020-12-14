#include <cstdlib>
#include <time.h>
#include "shield.h"

using namespace std;

shield::shield(){
  int NPossibleItems = 2;
  srand(time(NULL));
  setStats(rand() % NPossibleItems +1);
}

shield::shield(int ID){
  setStats(ID);
}

void shield::setStats(int ID){
  switch(ID){
  case 1:
    //Sets stats for Large Shield
    name = "Large shield";
    weight = 30;
    BonusAttack = -5;
    BonusDefense = 10;
    BonusHP = 0;
    break;
  case 2:
    name = "Small shield";
    weight = 10;
    BonusAttack = 0;
    BonusDefense = 10;
    BonusHP = 0;
  }
}

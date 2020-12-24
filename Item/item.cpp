#include <cstdlib>
#include <iostream>
#include "item.h"

using namespace std;
/////////////////////////////////////////////////////////////////////
//Function printStats():
//Prints the stats of the item object to the cmd (Weight Attack Defense HP Strength)
////////////////////////////////////////////////////////////////////
void item::printStats(){
  cout << name << " ";
  if(weight != 0){
    cout << "W" << weight;
  }
  if(BonusAttack != 0){
    cout << "A" << BonusAttack;
  }
  if(BonusDefense != 0){
    cout << "D" << BonusDefense;
  }
  if(BonusHP != 0){
    cout << "H" << BonusHP;
  }
  if(BonusStrength != 0){
    cout << "S" << BonusStrength;
  }
}

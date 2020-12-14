#include <cstdlib>
#include <iostream>
#include "item.h"

using namespace std;

void item::pickup(){
  //get the item out of the board
 
  ItemX = 0;
  ItemY = 0;

  //Add Item to inventory
}

void item::drop(){
  //set ItemX and ItemY to current player coordinates
  //delete item from inventory
}

void item::printStats(){
  cout << name << ": W" << weight;
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

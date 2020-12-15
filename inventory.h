#ifndef inventory_h
#define inventory_h

#include "item.h"
#include "shield.h"
#include "weapon.h"
#include "armour.h"
#include "ring.h"

class inventory{
 public:
  inventory(); //creates an empty inventory

  //functions:
  void printInventory(); //prints the whole content of the inventory

  //returning the private values:
  inline weapon getWeapon(){return EqWeapon;};
  inline armour getArmor(){return EqArmour;};
  inline shield getShield(){return EqShield;};
  inline int getNRings(){return NRings-1;};
  ring getRings();
  
 private:
  //storage units of the inventory
  weapon EqWeapon;
  armour EqArmour;
  shield EqShield;
  ring *EqRings;
  int NRings;

  //values modified each time an item is picked up
  int TotAtackBonus;
  int TotDefBonus;
  int TotHPBonus;
  int TotStrengthBonus;
};



#endif //end of def guard

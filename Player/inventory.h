#ifndef inventory_h
#define inventory_h

#include "../Item/item.h"
#include "../Item/shield.h"
#include "../Item/weapon.h"
#include "../Item/armour.h"
#include "../Item/ring.h"

////////////////////////////////////////////////////////////////////////
//class name: inventory
//construction: default only
//destruction: NONE
//Derived from: NONE
//used as inheritance for classes:  NONE
//
//Description: The inventory class is used to create inventory objects. It contains a weapon, a shield, an armour,
//   and a ring array who is dynamically allowed.
//   pickup and drop function are here because both are directly related to the inventory.
//   Overall bonus statistics from the items contained in the inventory can easyly be acces via the public
//   interface. 
//   This class will be used to create the players inventory.
/////////////////////////////////////////////////////////////////////////
class inventory{
 public:
  // constructors
  inventory(); //creates an empty inventory with "EMPTY" items (stats = NULL)

  void pickup(weapon); //picks the item up on the currrent player tile. function is called
  void pickup(armour); //depending on the type of object taken
  void pickup(shield);
  void pickup(ring);
  int drop(int,int,armour [],shield [],weapon [],ring []); //prompts the player with a choice to chose which item to drop
  
  void printInventory(); //prints the whole content of the inventory
  void printBonusStats(); //prints the added bonus stats of the inventory (+weight)

  //returning the private items (see private section for description):
  inline weapon getWeapon(){return EqWeapon;};
  inline armour getArmor(){return EqArmour;};
  inline shield getShield(){return EqShield;};
  inline int getNRings(){return NRings;};
  inline ring* getRings(){return EqRings;};
  //returning the private overall bonus values:
  inline int getTotAttack(){return TotAttackBonus;};
  inline int getTotDef(){return TotDefBonus;};
  inline int getTotHP(){return TotHPBonus;};
  inline int getTotStrength(){return TotStrengthBonus;};
  inline int getTotWeight(){return TotWeight;};
  
 private:
  //storage units of the inventory
  weapon EqWeapon; //Equiped weapon object
  armour EqArmour; //Equiped armour object
  shield EqShield; //Equiped shield object
  ring *EqRings; //Equiped rings stored in a dynamically dimensioned array of size NRings
  int NRings; //Number of Rings in the inventory.
  //values modified each time an item is picked up:
  int TotAttackBonus;
  int TotDefBonus;
  int TotHPBonus;
  int TotStrengthBonus;
  int TotWeight;
  void Update(); //internal function that must be called when adding/droping an item
  void DeleteRing(int); //Deletes and creates the new EqRing Array with the right size (size-1). used in function drop()
};

#endif //end of def guard

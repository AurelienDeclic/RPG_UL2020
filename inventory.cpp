#include <cstdlib>
#include <iostream>
#include "inventory.h"

using namespace std;

inventory::inventory(){
  EqWeapon = weapon(0);
  EqArmour = armour(0);
  EqShield = shield(0);
  //Dynamic allocation of rings:
  int NRings = 1;
  EqRings = new ring[NRings];
  EqRings[0] = ring(0);
}

void inventory::printInventory(){
  cout << "Equiped Weapon => ";
  EqWeapon.printStats();
  cout << endl  << "Equiped Armour => ";
  EqArmour.printStats();
  cout << endl << "Equiped Shield => ";
  EqShield.printStats();
  cout << endl << "Equiped Rings:";
  for(int i = 0; i<= NRings; i++){
    cout << endl << "Ring n" << (i+1) << " +> ";
    EqRings[i].printStats();
  }
  cout << endl;
}
  

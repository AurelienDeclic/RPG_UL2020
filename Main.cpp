#include <cstdlib>
#include <iostream>
#include <time.h>

#include "item.h"
#include "shield.h"
#include "weapon.h"
#include "armour.h"
#include "ring.h"
#include "inventory.h"

using namespace std;

int main(){
  //Test code for Aurelien part (Item/Inventory classes)

  //Part 1: item creation
  //4 types of items, all using different classes
  //all inherits from class "item", which stores default bonus values of item + name
  
  srand(time(NULL)); //Rand seed MUST BE INITIALISED BEFORE CREATION

  cout << "Creating new items: " << endl;
  
  weapon weapon1;
  weapon1.printStats();
  cout << endl;
  shield shield1;
  shield1.printStats();
  cout << endl;
  armour armour1;
  armour1.printStats();
  cout << endl;
  ring ring1;
  ring1.printStats();
  cout << endl;

  cout << "Creating an empty inventory:" << endl;

  inventory PlayerInventory; //creates an empty inventory (items are all here)
  PlayerInventory.printInventory();
  PlayerInventory.printBonusStats();

  //picking up the created objects
  PlayerInventory.pickup(weapon1);
  PlayerInventory.pickup(shield1);
  PlayerInventory.pickup(armour1);
  PlayerInventory.pickup(ring1);

  //printing the inventory to the screen.
  cout << endl << "New inventory after pickup:" <<endl;
  PlayerInventory.printInventory();
  PlayerInventory.printBonusStats();
  //What if we want to add a huge amount of rings? Is Dynamic memory working well?

  cout << "Picking up rings..." << endl;
  int fingers = 5;
  for(int i = 0; i < fingers ; i++){
    ring NewRing;
    PlayerInventory.pickup(NewRing);
    }
    cout << endl << "We have now:" << PlayerInventory.getNRings() <<endl;
  
  PlayerInventory.printInventory();
  PlayerInventory.printBonusStats();

  int exit = 0;
  while(exit == 0){
    PlayerInventory.drop();
    cout << endl << endl << endl;

    cout << endl << "Exit ? (1 or 0)" << endl;
    cin >> exit;
  }
  
  PlayerInventory.pickup(weapon1);
  PlayerInventory.pickup(shield1);
  PlayerInventory.pickup(armour1);
  PlayerInventory.pickup(ring1);
  
  
  //end of Aurelien test code... Issues encountered and to answer:
  //Do we delete the item picked? Program actually copy pastes the object as it is now.
  return EXIT_SUCCESS;
}

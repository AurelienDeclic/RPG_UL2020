#include <cstdlib>
#include <iostream>
#include <time.h>

#include "item.h"
#include "shield.h"
#include "weapon.h"
#include "armour.h"
#include "ring.h"

using namespace std;

int main(){
  //Test code for Aurelien part (Item/Inventory classes)

  //Part 1: item creation
  //4 types of items, all using different classes
  //all inherits from class "item", which stores default bonus values of item + name

  srand(time(NULL)); //Rand seed MUST BE INITIALISED BEFORE CREATION

  weapon weapon1; //weapon object no 1
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

  //end of Aurelien test code
  return EXIT_SUCCESS;
}

#ifndef armour_h
#define armour_h

#include "Item/item.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//class name: armour
//construction: basic (random item, except "NONE") and general (with an integer item ID)
//destruction: NONE
//Derived from: item class
//used as inheritance for classes: NONE
//
//Description: creates armour objects, and set their statistics following a database (see armour.cpp)
////////////////////////////////////////////////////////////////////////////////////////////////////

class armour : public item{
 public:
  armour(); //creates a random weapon object
  armour(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item
};

#endif //end of def guard

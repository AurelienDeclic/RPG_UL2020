#ifndef weapon_h
#define weapon_h

#include "item.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//class name: weapon
//construction: basic (random item, except "EMPTY") and general (with an integer item ID)
//destruction: NONE
//Derived from: item class
//used as inheritance for classes: NONE
//
//Description: creates weapon objects, and set their statistics following a database (see weapon.cpp)
////////////////////////////////////////////////////////////////////////////////////////////////////

class weapon : public item{
 public:
  weapon(); //creates a random weapon object
  weapon(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item, can not be called outside of weapon class
};

#endif //end of def guard

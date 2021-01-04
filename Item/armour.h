/**********************************************************
 * armour.h 
 * Interface for the Armour class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef armour_h
#define armour_h

#include "item.h"

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

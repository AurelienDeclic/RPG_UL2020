/**********************************************************
 * shield.h 
 * Interface for the Shield class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef shield_h
#define shield_h

#include "item.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//class name: shield
//construction: basic (random item, except "EMPTY") and general (with an integer item ID)
//destruction: NONE
//Derived from: item class
//used as inheritance for classes: NONE
//
//Description: creates shield objects, and set their statistics following a database (see shield.cpp)
////////////////////////////////////////////////////////////////////////////////////////////////////
class shield : public item{
 public:
  shield(); //creates a random weapon object
  shield(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int);//function called internally to set values
};

#endif //end of def guard

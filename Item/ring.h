/**********************************************************
 * ring.h 
 * Interface for the Ring class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef ring_h
#define ring_h

#include "item.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//class name: ring
//construction: basic (random item, except "EMPTY") and general (with an integer item ID)
//destruction: NONE
//Derived from: item class
//used as inheritance for classes: NONE
//
//Description: creates ring objects, and set their statistics following a database (see ring.cpp)
////////////////////////////////////////////////////////////////////////////////////////////////////
class ring : public item{
 public:
  ring(); //creates a random weapon object
  ring(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item
};

#endif //end of def guard

#ifndef weapon_h
#define weapon_h

#include "item.h"

class weapon : public item{
 public:
  weapon(); //creates a random weapon object
  weapon(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item
};


#endif //end of def guard

#ifndef armour_h
#define armour_h
#include "item.h"

class armour : public item{
 public:
  armour(); //creates a random weapon object
  armour(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item
};

#endif //end of def guard

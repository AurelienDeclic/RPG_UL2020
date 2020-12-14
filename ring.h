#ifndef ring_h
#define ring_h

#include "item.h"

class ring : public item{
 public:
  ring(); //creates a random weapon object
  ring(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int); //sets all the stats from an item
};

#endif //end of def guard

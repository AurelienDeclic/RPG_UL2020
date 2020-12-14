#ifndef shield_h
#define shield_h

#include "item.h"

class shield : public item{
 public:
  shield(); //creates a random weapon object
  shield(int); //creates an item with certain atributes and a shield ID
 private:
  void setStats(int);//function called internally to set values
};

#endif //end of def guard

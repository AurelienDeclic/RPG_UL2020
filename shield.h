#ifndef shield_h
#define shield_h

#include "item.h"

class shield : public item{
 public:
  shield(); //creates a random weapon object
  shield(int); //creates an item with certain atributes and a shield ID

  void getStats(); //prints stats to the screen
  
 private:
  void setStats(int);
  //NONE (inherits from item class)
};

#endif //end of def guard

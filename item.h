#ifndef item_h
#define item_h

#include <cstdlib>
#include <string>

/////////////////////////////////////////////////////////////
//class item
//construction: NONE
//Used as derivation in classes weapon armour shield ring
/////////////////////////////////////////////////////////////

class item{
  public:
  void pickup(); //picks the item up on the currrent player tile
  void drop(); //drops the item on the current player tile

  //Get and Set coordinates functions
  inline int getX(){return ItemX;};
  inline void setX(int &i){ItemX = i;};
  inline int getY(){return ItemY;};
  inline void setY(int &i){ItemX = i;};

  //You can only get the value of: Weight BonusAttack BonusDefense BonusHP
  //Can not set these values: are set at initialisation
  inline int getWeight(){return weight;};
  inline int getBAttack(){return BonusAttack;};
  inline int getBDefense(){return BonusDefense;};
  inline int getBHP(){return BonusHP;};

  //Prints the stats to the cmd in a Dungeons and Dragons style (oooh yeeeeah best game)
  void printStats();
  
 protected:
  int ItemX;
  int ItemY;
  std::string name;
  int weight;
  int BonusAttack;
  int BonusDefense;
  int BonusHP;
};

#endif //end of def guard

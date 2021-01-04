/**********************************************************
 * item.h 
 * Interface for the Item class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef item_h
#define item_h

#include <cstdlib>
#include <string>

///////////////////////////////////////////////////////////////////////////////////////////////////
//class name: inventory
//construction: NONE
//destruction: NONE
//Derived from: NONE
//used as inheritance for classes: weapon, ring, shield, armour
//
//Description: Is used to simplify program writing and set new Item properties in case of update.
//     The interface can be used to get the bonus values from the item
//     Stores the name of the item, weight, Bonus Defense, Bonus HP, BonusStrength values.
////////////////////////////////////////////////////////////////////////////////////////////////////

class item {
public:
    //Get and Set coordinates functions
    inline int getX() { return ItemX; };

    inline int getY() { return ItemY; };

    inline void setX(int x) { ItemX = x; };

    inline void setY(int y) { ItemY = y; };

    //You can only get the value of: Weight BonusAttack BonusDefense BonusHP
    //Can not set these values: are set at initialisation
    inline int getWeight() { return weight; };

    inline int getBAttack() { return BonusAttack; };

    inline int getBDefense() { return BonusDefense; };

    inline int getBHP() { return BonusHP; };

    inline int getBStrength() { return BonusStrength; };

    inline std::string getString() { return name; };

    //Prints the stats to the cmd in a Dungeons and Dragons style (oooh yeeeeah best game)
    void printStats();

protected:
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    int ItemX;
    int ItemY;
    std::string name;
    int weight;
    int BonusAttack;
    int BonusDefense;
    int BonusHP;
    int BonusStrength;
};

#endif //end of def guard

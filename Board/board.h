//
// Created by Nischay on 24/12/2020.
//

#ifndef BOARD_H
#define BOARD_H

#include "../Enemy/enemy.h"

class Board {

public:
    Board();
    void initBoard(int,int);
//    inline int getBoard(){return board};


private:
    int x_size;
    int y_size;

    // populate board
    int random_value;

    int enemy_count;
    int armour_count;
    int weapon_count;
    int shield_count;
    int ring_count;
    int empty_count;
    Enemy* enemy_array[];

};


#endif //RPG_UL2020_BOARD_H

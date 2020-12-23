/**********************************************************
 * board.h 
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef BOARD_H
#define BOARD_H

#include "race.h"
#include "inventory.h"
#include "shield.h"
#include "weapon.h"
#include "armour.h"
#include "ring.h"
#include "enemy.h"

class board  
{
	public:
		board(int); //creates a board array of size INT
        void printBoard(); //prints the board
	private:
		int SIZE;
        long long pointers[5][5];
        int BoardEntities[5][5];
        Enemy *EnemyArray;
        weapon *WeaponArray;
        shield *ShieldArray;
        armour *ArmourArray;
        ring *RingArray;
        int Nenemies;
        int Nweapons;
        int Nshields;
        int Narmour;
        int Nrings;

        void FillPointerArray();
        void printBoardPointers();
};

#endif
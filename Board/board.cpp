/**********************************************************
 * board.cpp
 * Implementation of the board class.
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

//Include standard libraries and enemy interface.
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "board.h"

using namespace std;

board::board(int input){
    Nenemies = 0;
    Nweapons = 0;
    Nshields = 0;
    Narmour = 0;
    Nrings = 0;
    //SIZE = input;
	SIZE = 5;
    //BoardEntities[5][5];
    //pointers[5][5]; //dynamic allocation of memory for board size

    //filling the board entities array
    for(int i = 0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            BoardEntities[i][j] = rand()%6;
            switch(BoardEntities[i][j]){
                case 1:
                    Nenemies++;
                    break;
                case 2:
                    Nweapons++;
                    break;
                case 3:
                    Nshields++;
                    break;
                case 4:
                    Narmour++;
                    break;
                case 5:
                    Nrings++;
                    break;
            }
        }
    }
    //array is now filled
    cout << "Entity board: " << endl;
    printBoard();

    //creating the enemies, weapons, shields, armour and ring arrays
    EnemyArray = new Enemy[Nenemies];
    WeaponArray = new weapon[Nweapons];
    ShieldArray = new shield[Nshields];
    ArmourArray = new armour[Narmour];
    RingArray = new ring[Nrings];

    //filling the board pointer array

    FillPointerArray();
    printBoardPointers();
}

void board::printBoard(){
    for(int i = 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            cout << BoardEntities[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void board::FillPointerArray(){
    int E1 = 0; //these values start at 0. we scan the entity board.
    int W2 = 0; //each time we encounter an entity different than 0
    int S3 = 0; //we associate the pointer of the latter entity to our pointers array
    int A4 = 0;
    int R5 = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            switch(BoardEntities[i][j]){
                case 1:
                    pointers[i][j] = (long long)(&EnemyArray[E1++]);
                    break;
                case 2:
                    pointers[i][j] = (long long)(&WeaponArray[W2++]);
                    break;
                case 3:
                    pointers[i][j] = (long long)&ShieldArray[S3++];
                    break;
                case 4:
                    pointers[i][j] = (long long)&ArmourArray[A4++];
                    break;
                case 5:
                    pointers[i][j] = (long long)&RingArray[R5++];
                    break;
                case 0:
                    pointers[i][j] = 0;
            }
        }
        cout << endl;
    }
}

void board::printBoardPointers(){
    cout << setbase(16);
    for(int i = 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            cout << pointers[i][j] << "  ";
        }
        cout << endl;
    }
    cout <<setbase(10) << endl;
}
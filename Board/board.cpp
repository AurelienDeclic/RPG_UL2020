//
// Created by Nischay on 24/12/2020.
//

#include "board.h"
#include <iostream>
#include <cstdlib>

Board::Board() {
    // set all counters to 0
    enemy_count=0;
    armour_count=0;
    weapon_count=0;
    shield_count=0;
    ring_count=0;
    empty_count=0;

}

void Board::initBoard(int y, int x) {
    x_size=x;
    y_size=y;
    int board[y_size][x_size];

    // populate with random enemies and items
    for(int y = 0; y < y_size; y++) {
        // column loop
        for (int x = 0; x < x_size; x++) {
//            cout << "current pos: " << i << "," << j;
            // populate with random enemies (1)
            // populate with random items (2 to 5)
            // remaining cells set to 0 (empty cell0)
            // for first cell of board, keep empty
            if (x == 0 && y == 0){
                board[y][x] = 0;
            } else {
                random_value = rand()%6;
                board[y][x] = random_value;
            }
        }
    }

    // get the count of enemies and items from the populated board
    // row loop
    for(int y = 0; y < y_size; y++) {
        // column loop
        for (int x = 0; x < x_size; x++) {
            if(board[y][x] == 1){
                enemy_count++;
            }else if(board[y][x] == 2){
                armour_count++;
            }else if(board[y][x] == 3){
                shield_count++;
            }else if(board[y][x] == 4){
                weapon_count++;
            }else if(board[y][x] == 5){
                ring_count++;
            }else {
                // empty
                empty_count++;
            }
        }
    }

    // init enemy array
    enemy_array[enemy_count];
    // create enemy objects
    for(int i=0;i<enemy_count;++i)
    {
        enemy_array[i] = new Enemy();
    }
    int temp_counter=0;

    // set co-ordinates for new enemy objects
    for(int y = 0; y < y_size; y++) {
        // row loop
        for (int x = 0; x < x_size; x++) {
            if(board[y][x]==1) {
                enemy_array[temp_counter]->setCoordinates(y, x);
                temp_counter++;
            }
        }
    }
    temp_counter=0; //Resetting temp counter

}
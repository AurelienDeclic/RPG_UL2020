//
// Created by Nischay on 18/12/2020.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Console.h"
#include<locale.h>

using namespace std;

int Console::requestCharacterSelection() {
    int player_input;

    cout << "Please choose your player (enter a key from 1 to 5):" << endl;
    cout << "(1) - Human Harry" << endl;
    cout << "(2) - Elf Dobby" << endl;
    cout << "(3) - Dwarf Tyrion" << endl;
    cout << "(4) - Hobbit Frodo" << endl;
    cout << "(5) - Orc Gargoyle" << endl;

    cin >> player_input;
    // TODO
    // sanitize and handle invalid inputs here

    return player_input;
}

void Console::printWelcomeMessage(string message) {
    cout << "*********************" << message << "********************" << endl;
}

int Console::requestBoardDimensions() {
    int dimensions;

    cout << "Please enter the board dimensions: (max 200)" << endl;
    cin >> dimensions;

    // TODO
    // sanitize and handle invalid inputs here

    return dimensions;
}

void Console::renderConsoleInterface() {

    cout <<"Please choose direction: N,S,E,W or" << endl;
    cout << "Choose one of the options: " << endl;
    cout << "(A) Attack, (P) Pickup, (D) Drop, (L) Look, (I) Inventory, (X)Exit" << endl;
}

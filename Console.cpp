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
    string player = "Human Harry";
//    int Health = 80;
//    int Bag = 80;
//    int Attack = 80;
//    int Defence = 80;

    //accept input

    cout << "You: Human Harry [Health: 80 | Bag: 25 of 70 | Attack: 45 | Defence: 40]" << endl;
    cout << "Current Position: 10,22                                      Time: Night" << endl;
    cout << "" << endl;
    cout << "A wild Aurelien appeared!" << endl;
    cout << "" << endl;
    cout << "Commands: Move [(N)orth (S)outh (E)ast (W)est]" << endl;
    cout << "Or: (A)ttack | (P)ick | (D)rop | (L)ook | (I)nventory | E(X)it" << endl;
}

void Console::renderConsoleWithEmojis() {
    string player = "Human Harry";
    int Health = 80;
    int Bag = 80;
    int Attack = 80;
    int Defence = 80;

    setlocale(LC_ALL, "en_US.utf8");

    string heart = u8"\U00002665";
//    string bag = u8"\U0001F4B0";
    string bag = "\xF0\x9F\x92\xB0";
    string sword = u8"\U00002694";
    string shield = u8"\U0001F6E1";
    string sun = u8"\U00002600";
    string moon = u8"\U0001F319";

    cout << "You: Human Harry [" << heart  << ": " << Health << " | " << bag  << ": " << Bag << " of 70 | " << sword  << ": " << Attack << " | " << shield  << ": " << Defence << "]" << endl;
    cout << "Current Position: 10,22                                      Time: " << moon << endl;
    cout << "" << endl;
    cout << "A wild Aurelien appeared!" << endl;
    cout << "" << endl;
    cout << "Commands: Move [(N)orth (S)outh (E)ast (W)est]" << endl;
    cout << "Or: (A)ttack | (P)ick | (D)rop | (L)ook | (I)nventory | E(X)it" << endl;
}
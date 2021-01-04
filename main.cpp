/**********************************************************
 * main.cpp
 * Main file of the game. 
 * Consist of code to create board, initialise player, initialise enemies & items, 
 * attack/defend, item pick up and drop, move around the board, look player inventory.
 * Have fun gaming!!
 * c++ programming language.
 * creators: 20072325 20065124 20014325 20106947
             Aurelien RK       Nischay  Elea
 * date created:	18.12.2020
 * date last-modified:	24.12.2020
 **********************************************************/

//Include standard libraries 
#include <iostream>

#include <iomanip>

#include <cstdlib>

// Include custom headers
#include "Console.h"

#include "Player/player.h"

#include "Enemy/enemy.h"

using namespace std;

//Function to check if its day or night
bool ifNight(int cnt);

//Main function of the program
int main(int argc, char * argv[]) {

  // set rand() seed
  srand(static_cast < unsigned int > (time(NULL)));

  Console console; // initialize console

  // welcome message
  console.printWelcomeMessage("Welcome to FantasyArena 2020");

  /************** Board ****************/
  int dimensions = console.requestBoardDimensions(); // request for and load dimensions

  int y_size = dimensions; //y*x board parameter
  int x_size = dimensions; //y*x board parameter

  int board[x_size][y_size]; //initiating board size.

  int random_value; //Random value used to populate enemy/items on the board
  // populate board
  // row loop
  for (int y = 0; y < y_size; y++) {
    // column loop
    for (int x = 0; x < x_size; x++) {
      // populate with random enemies (1:Enemy)
      // populate with random items (2:Armour, 3:Shield, 4:Weapon, 5:Ring)
      // remaining cells set to 0 (0:empty cell)

      // for first cell of board, keep empty
      if (x == 0 && y == 0) {
        board[y][x] = 0;
      } else {
        random_value = rand() % 6;
        board[y][x] = random_value;
      }
    }
  }

  //Printing board for testing.
  cout << "Board:" << endl;
  // row loop
  for (int y = 0; y < y_size; y++) {
    // column loop
    for (int x = 0; x < x_size; x++) {
      cout << board[y][x] << " ";
    }
    cout << endl;
  }

  // set counters to 0. Counters are used to know how many random enemies, items got populated on the board.
  int enemy_count = 0;
  int armour_count = 0;
  int weapon_count = 0;
  int shield_count = 0;
  int ring_count = 0;
  int empty_count = 0;

  // count each board element - Enemies or items
  // row loop
  for (int y = 0; y < y_size; y++) {
    // column loop
    for (int x = 0; x < x_size; x++) {
      if (board[y][x] == 1) {
        enemy_count++; //Increment enemy counter
      } else if (board[y][x] == 2) {
        armour_count++; //Increment Armour counter
      } else if (board[y][x] == 3) {
        shield_count++; //Increment Shield counter
      } else if (board[y][x] == 4) {
        weapon_count++; //Increment weapon counter
      } else if (board[y][x] == 5) {
        ring_count++; //Increment Ring counter
      } else {
        // Increment empty counter
        empty_count++;
      }
    }
  }

  //	Below cout are used to know how many elements got populated. For testing!
  //    cout << enemy_count << " Enemies" << endl;
  //    cout << armour_count << " Armour" << endl;
  //    cout << shield_count << " Shield" << endl;
  //    cout << weapon_count << " Weapon" << endl;
  //    cout << ring_count << " ring" << endl;
  //    cout << empty_count << " empty" << endl;

  //    Initialising arrays or enemies and items.
  Enemy * enemy_array[enemy_count];
  armour * armour_array[armour_count];
  shield * shield_array[shield_count];
  ring * ring_array[ring_count];
  weapon * weapon_array[weapon_count];

  // Creating objects of enemeies and items.	
  for (int i = 0; i < enemy_count; ++i) {
    enemy_array[i] = new Enemy();
  }
  for (int i = 0; i < armour_count; ++i) {
    armour_array[i] = new armour();
  }
  for (int i = 0; i < shield_count; ++i) {
    shield_array[i] = new shield();
  }
  for (int i = 0; i < weapon_count; ++i) {
    weapon_array[i] = new weapon();
  }
  for (int i = 0; i < ring_count; ++i) {
    ring_array[i] = new ring();
  }

  // Temporary counter set to 0. These are used while setting co-ordinates of enemies and items. 
  int temp_counter_enemy = 0;
  int temp_counter_armour = 0;
  int temp_counter_shield = 0;
  int temp_counter_weapon = 0;
  int temp_counter_ring = 0;

  //Code below used to set the co-ordinates of enemies and items.
  // column
  for (int y = 0; y < y_size; y++) {
    // row loop
    for (int x = 0; x < x_size; x++) {
      // For all enemies in the array their co-ordinates are set.
      if (board[y][x] == 1) {
        enemy_array[temp_counter_enemy] -> setCoordinates(y, x);
        temp_counter_enemy++;
      }

      // For all armour in the array their co-ordinates are set.
      if (board[y][x] == 2) {
        armour_array[temp_counter_armour] -> setX(x);
        armour_array[temp_counter_armour] -> setY(y);
        temp_counter_armour++;
      }

      // For all shield in the array their co-ordinates are set.
      if (board[y][x] == 3) {
        shield_array[temp_counter_shield] -> setX(x);
        shield_array[temp_counter_shield] -> setY(y);
        temp_counter_shield++;
      }

      // For all weapon in the array their co-ordinates are set.
      if (board[y][x] == 4) {
        weapon_array[temp_counter_weapon] -> setX(x);
        weapon_array[temp_counter_weapon] -> setY(y);
        temp_counter_weapon++;
      }

      // For all ring in the array their co-ordinates are set.
      if (board[y][x] == 5) {
        ring_array[temp_counter_ring] -> setX(x);
        ring_array[temp_counter_ring] -> setY(y);
        temp_counter_ring++;
      }
    }
  }

  /************** Board end ****************/

  /************** Select Player ****************/
  int character_selected;
  character_selected = console.requestCharacterSelection();

  // Spawn player
  Player player;
  player.initialiseAttributes(character_selected, dimensions);
  player.showInitAttributes(); //Display player attributes

  /***********************************************/

  /**************** Begin GAme *******************************/

  console.renderConsoleInterface(); //Initialising print statements
  char option; //entered option of the user
  int counter = 0; //Counter to check for day and night and alter status, needs to be incremented after every move.
  bool isNight; //Set to true or false based on night or day and based on player and enemy object
  int current_enemy = -1; // Enemy array index, initialised to -1.
  int current_armour = -1; // Armour array index, initialised to -1.
  int current_shield = -1; // Shield array index, initialised to -1.
  int current_weapon = -1; // Weapon array index, initialised to -1.
  int current_ring = -1; // Ring array index, initialised to -1.

  cin >> option; //Choose the option 1-5

  //Execute while until player exits.
  while (option != 'X' || option != 'x') {
    //Check to ensure the race attributes are changed only when it changes to day or night
    if (counter % 5 == 0) {
      player.alterStats(isNight); //Currently only Orc status is altered.
      for (int i = 0; i < enemy_count; i++) {
        enemy_array[i] -> alterStats(isNight);
      }
    }

    // player movement
    if (option == 'N' || option == 'n' || option == 'S' || option == 's' || option == 'E' || option == 'e' || option == 'W' || option == 'w') {
      // reset current enemy value everytime the player moves.
      current_enemy = -1;
      current_armour = -1;
      current_shield = -1;
      current_weapon = -1;
      current_ring = -1;

      // Move player
      player.movePlayer(option);
      // Utilising the co-ordinates to know if there is an enemy/item/empty cell.
      int y_co = player.getY();
      int x_co = player.getX();

      // check if the cell has enemy
      if (board[y_co][x_co] == 1) {
        // enemy
        for (int j = 0; j < enemy_count; j++) {
          //Print enemy if present in the co-ordinates	
          if (enemy_array[j] -> getYCoordinates() == y_co && enemy_array[j] -> getXCoordinates() == x_co) {
            enemy_array[j] -> showAttributes();
            current_enemy = j;
          }
        }
      } else if (board[y_co][x_co] == 2) { // Check if the cell has armour
        // armour
        for (int j = 0; j < armour_count; j++) {
          //Print armour details if present in the co-ordinates		
          if (armour_array[j] -> getY() == y_co && armour_array[j] -> getX() == x_co) {
            cout << armour_array[j] -> getString() << endl;
            current_armour = j;
          }
        }

      } else if (board[y_co][x_co] == 3) { // Check if the cell has shield
        // shield
        for (int j = 0; j < shield_count; j++) {
          //Print shield details if present in the co-ordinates	
          if (shield_array[j] -> getY() == y_co && shield_array[j] -> getX() == x_co) {
            cout << shield_array[j] -> getString() << endl;
            current_shield = j;
          }
        }
      } else if (board[y_co][x_co] == 4) { // Check if the cell has weapon
        // weapon
        for (int j = 0; j < weapon_count; j++) {
          //Print weapon details if present in the co-ordinates	
          if (weapon_array[j] -> getY() == y_co && weapon_array[j] -> getX() == x_co) {
            cout << weapon_array[j] -> getString() << endl;
            current_weapon = j;
          }
        }
      } else if (board[y_co][x_co] == 5) { // Check if the cell has ring
        // ring
        for (int j = 0; j < ring_count; j++) {
          //Print ring details if present in the co-ordinates
          if (ring_array[j] -> getY() == y_co && ring_array[j] -> getX() == x_co) {
            cout << ring_array[j] -> getString() << endl;
            current_ring = j;
          }
        }
      } else {
        cout << "empty cell!" << endl;
      }
    }

    // If option chosen is to attack
    else if (option == 'A' || option == 'a') {
      if (board[player.getY()][player.getX()] == 1) {
        int attackDamage = 0;
        attackDamage = player.attack(isNight); //Call attack function of the player to find the damage
        if (attackDamage != 0) {
          enemy_array[current_enemy] -> defence(attackDamage, isNight); //Call enemy defence function to defend the attack damage and modify the enemy health based on defence.
          int enemyhealth = 0;
          enemyhealth = enemy_array[current_enemy] -> getEnemyHealth(); //Check enemy health
          cout << "Enemy health: " << enemyhealth << endl;
          if (enemyhealth <= 0) {
            cout << "Enemy defeated. " << enemy_array[current_enemy] -> getDefenceValue() << " will be added to gold" << endl;
            player.GoldAdd(enemy_array[current_enemy] -> getDefenceValue()); //Adding enemy defence value as gold to player.
            // set board cell to empty after enemy dies
            int enemy_y_co = enemy_array[current_enemy] -> getYCoordinates();
            int enemy_x_co = enemy_array[current_enemy] -> getXCoordinates();
            board[enemy_y_co][enemy_x_co] = 0;
            // move enemy out from the board
            enemy_array[current_enemy] -> setCoordinates(-1, -1);
          }
        }
        //Resetting attack damage for enemy to initiate the attack now.
        attackDamage = 0;
        cout << current_enemy << " - current enemy" << endl;
        attackDamage = enemy_array[current_enemy] -> attack(isNight); //Call attack function of the enenmy to find the damage
        if (attackDamage != 0) {
          player.defence(attackDamage, isNight); //Call player defence function to defend the attack damage and modify the player health based on defence.
          int playerhealth = 0;
          playerhealth = player.getPlayerHealth(); //Check player health
          cout << "Player health: " << playerhealth << endl;
          //If player health is 0 then you lose!
          if (playerhealth <= 0) {
            cout << "YOU LOSE, GAME OVER!!!" << endl;
            break;
          }
        }
      }

    } else if (option == 'P' || option == 'p') {
      //Multiple if criteria based on different types of items. Items to be populated when board is initiated. Assuming flag is set to pick either armour/weapon etc.
      if (current_armour != -1) {
        string itemType2 = armour_array[current_armour] -> getString();

        if (itemType2 == "Plate Armour (armour)") {
          player.itemPickup( * armour_array[current_armour]);
        }

        if (itemType2 == "Leather Armour (armour)") {
          player.itemPickup( * armour_array[current_armour]);
        }

        // set board cell to empty after item pickup
        int armour_y_co = armour_array[current_armour] -> getY();
        int armour_x_co = armour_array[current_armour] -> getX();
        board[armour_y_co][armour_x_co] = 0; //Setting the field to empty on board
        // modify object in array, change its x & y to move it out of the board.
        armour_array[current_armour] -> setY(-1);
        armour_array[current_armour] -> setX(-1);
      }

      if (current_shield != -1) {
        string itemType3 = shield_array[current_shield] -> getString();

        if (itemType3 == "Large shield (shield)") {
          player.itemPickup( * shield_array[current_shield]);
        }
        if (itemType3 == "Small shield (shield)") {
          player.itemPickup( * shield_array[current_shield]);
        }

        // set board cell to empty after item pickup
        int shield_y_co = shield_array[current_shield] -> getY();
        int shield_x_co = shield_array[current_shield] -> getX();
        board[shield_y_co][shield_x_co] = 0; //Setting the field to empty on board
        // modify object in array, change its x & y
        shield_array[current_shield] -> setY(-1);
        shield_array[current_shield] -> setX(-1);
      }

      if (current_weapon != -1) {
        string itemType4 = weapon_array[current_weapon] -> getString();

        if (itemType4 == "Sword (weapon)") {
          player.itemPickup( * weapon_array[current_weapon]);
        }
        if (itemType4 == "Dagger (weapon)") {
          player.itemPickup( * weapon_array[current_weapon]);
        }

        // set board cell to empty after item pickup
        int weapon_y_co = weapon_array[current_weapon] -> getY();
        int weapon_x_co = weapon_array[current_weapon] -> getX();
        board[weapon_y_co][weapon_x_co] = 0; //Setting the field to empty on board
        // modify object in array, change its x & y
        weapon_array[current_weapon] -> setY(-1);
        weapon_array[current_weapon] -> setX(-1);
      }

      if (current_ring != -1) {
        string itemType5 = ring_array[current_ring] -> getString();

        if (itemType5 == "Ring of life (ring)") {
          player.itemPickup( * ring_array[current_ring]);
        }
        if (itemType5 == "Ring of Strength (ring)") {
          player.itemPickup( * ring_array[current_ring]);
        }

        // set board cell to empty after item pickup
        int ring_y_co = ring_array[current_ring] -> getY();
        int ring_x_co = ring_array[current_ring] -> getX();
        board[ring_y_co][ring_x_co] = 0; //Setting the field to empty on board
        // modify object in array, change its x & y
        ring_array[current_ring] -> setY(-1);
        ring_array[current_ring] -> setX(-1);
      }

      cout << "End pickup" << endl;
    } else if (option == 'D' || option == 'd') {
      // get the co-ordinates of this cell
      int cell_y = player.getY();
      int cell_x = player.getX();
      //Drop item on the board.
      int type_returned = player.itemDrop(cell_y, cell_x, * armour_array, * shield_array, * weapon_array, * ring_array);

      board[cell_y][cell_x] = type_returned; //Populate it to the board.

      // place item on board

      string itemType2 = armour_array[current_armour] -> getString();
      cout << "ItemType2: " << itemType2 << endl;

      if (itemType2 == "Plate Armour (armour)") {
        player.itemPickup( * armour_array[current_armour]);
      }

      if (itemType2 == "Leather Armour (armour)") {
        player.itemPickup( * armour_array[current_armour]);
      }

      // set board cell to empty after item pickup
      int armour_y_co = armour_array[current_armour] -> getY();
      int armour_x_co = armour_array[current_armour] -> getX();
      board[armour_y_co][armour_x_co] = 0;

    } else if (option == 'L' || option == 'l') {
      player.showCurrentStats(); //Show player current attributes.
      //enemy_array[current_enemy]->showCurrentStats();
    } else if (option == 'I' || option == 'i') {
      //Print inventory
      player.printInventory();
    }
    //If any option other than A,X,P etc is picked then need to exit
    else {
      cout << "Exiting" << endl;
      break;
    }
    //Loop until Exit
    cout << "Please choose direction: N,S,E,W or" << endl;
    cout << "Choose one of the options: " << endl;
    cout << "(A) Attack, (P) Pickup, (D) Drop, (L) Look, (I) Inventory, (X)Exit" << endl;
    cin >> option;
    //Increment counter
    counter++;
    //Call isNight function to change the flag to day or night
    isNight = ifNight(counter);
  }
  //Print gold
  cout << "Gold collected: " << player.printGold() << endl;
  /***********************************************/

  // place player at position 0,0 on board

  // Randomize
  // spawn random number of enemies and items

  //    console.renderConsoleWithEmojis();

}

bool ifNight(int cnt) {
  if (cnt % 10 == 0 || cnt % 10 == 1 || cnt % 10 == 2 || cnt % 10 == 3 || cnt % 10 == 4) {
    cout << "Its day" << endl;
    return false;
  }
  if (cnt % 10 == 5 || cnt % 10 == 6 || cnt % 10 == 7 || cnt % 10 == 8 || cnt % 10 == 9) {
    cout << "Its night" << endl;
    return true;
  }
  return false;
}

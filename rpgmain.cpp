#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "armour.h"
#include "ring.h"
#include "board.h"

using namespace std;

//Function to check if its day or night
bool ifNight(int cnt);

int main()
{
	srand(time(NULL));
	//board boardB(5);
    Player player;
	Enemy enemyPlayer; //Enemy initialised using constructor
	armour pArmour;
	weapon pWeapon;
	ring pRing;
	int input; //From console
	char option; //Attack/Quit/Pickup etc
	int counter=0; //Counter to check for day and night and alter status, needs to be incremented after every move.
	//Board board();
	bool isNight; //Set to true or false based on night or day and based on player and enemy object
	cout << "Select character: 1-5" << endl;
	cout << "1-Human" << endl;
	cout << "2-Elf" << endl;
	cout << "3-Dwarf" << endl;
	cout << "4-Hobbit" << endl;
	cout << "5-Orc" << endl;
	cin >> input;
	cout << endl;
	player.initialiseAttributes(input); //Initialisation the player attributes
	player.showInitAttributes(); //Display player attributes
	cout << "Enemy: ";
	enemyPlayer.showAttributes(); //Display enenmy attributes
	cout <<"Please choose direction: N,S,E,W or" << endl;
	cout << "Choose one of the options: " << endl;
	cout << "(A) Attack, (P) Pickup, (D) Drop, (L) Look, (I) Inventory, (X)Exit" << endl;
	cin >> option;
	//Logic to execute until Exit(X)
	while(option!='X' || option!='x')
	{	
		//Check to ensure the race attributes are changed only when it changes to day or night
		if(counter%5==0)
		{
			player.alterStats(isNight);			//Currently only Orc status is altered.
			enemyPlayer.alterStats(isNight);
		}
		if(option=='N' || option=='n' || option=='S' || option=='s' || option=='E' || option=='e' || option=='W' || option=='w')
		{
			player.movePlayer(option);
		}
		//If option chosen is to attack
		else if(option=='A' || option=='a')
		{
			int attackDamage=0;
			attackDamage=player.attack(isNight); //Call attack function of the player to find the damage
			if(attackDamage!=0)
			{
				enemyPlayer.defence(attackDamage, isNight); //Call enemy defence function to defend the attack damage and modify the enemy health based on defence.
				//For testing
				int enemyhealth=0;
				enemyhealth=enemyPlayer.getEnemyHealth(); //Check enemy health
				cout << "Enemy health: " << enemyhealth << endl;
				if(enemyhealth<=0)
				{
					cout << "Enemy defeated. " << enemyPlayer.getDefenceValue() << " will be added to gold" << endl;
					player.GoldAdd(enemyPlayer.getDefenceValue()); //Adding enemy defence value as gold to player.
					break;
				}
			}
			//Resetting attack damage for enemy to initiate the attack now.
			attackDamage=0;
			attackDamage=enemyPlayer.attack(isNight); //Call attack function of the enenmy to find the damage
			if(attackDamage!=0)
			{
				player.defence(attackDamage, isNight); //Call player defence function to defend the attack damage and modify the player health based on defence.
				int playerhealth=0;
				playerhealth=player.getPlayerHealth(); //Check player health
				cout << "Player health: " << playerhealth << endl;
				//If player health is 0 then you lose!
				if(playerhealth<=0)
				{
					cout << "LOSER" << endl;
					break;
				}	
			}
		}
		else if(option=='P' || option=='p')
		{
			//Multiple if criteria based on different types of items. Items to be populated when board is initiated. Assuming flag is set to pick either armour/weapon etc.
			string itemType1= pWeapon.getString(); // Test logic to see if attack is working after modifying the attributes.
			string itemType2=pArmour.getString();
			string itemType3=pRing.getString();
			string itemType4=pRing.getString();
			cout << "ItemType1: " << itemType1 << endl;
			cout << "ItemType2: " << itemType2 << endl;
			cout << "ItemType3: " << itemType3 << endl;
			cout << "ItemType4: " << itemType4 << endl;
			if(itemType2=="Plate Armour (armour)")
			{
				player.itemPickup(pArmour);
			}
			if(itemType2=="Leather Armour (armour)")
			{
				player.itemPickup(pArmour);
			}
			if(itemType1=="Sword (weapon)")
			{
				player.itemPickup(pWeapon);
			}
			if(itemType1=="Dagger (weapon)")
			{
				player.itemPickup(pWeapon);
			}
			//Similar for shield
			if(itemType3=="Ring of life (ring)")
			{
				player.itemPickup(pRing);
			}
			if(itemType3=="Ring of Strength (ring)")
			{
				player.itemPickup(pRing);
			}
			if(itemType4=="Ring of life (ring)")
			{
				player.itemPickup(pRing);
			}
			if(itemType4=="Ring of Strength (ring)")
			{
				player.itemPickup(pRing);
			}
		}
		else if(option=='D' || option=='d')
		{
			player.itemDrop();
		}
		else if(option=='L' || option=='l')
		{
			player.showCurrentStats();
			enemyPlayer.showCurrentStats();
		}
		else if(option=='I' || option=='i')
		{
			//Print inventory
		}
		//If any option other than A,X,P etc is picked then need to exit
		else{
			cout<< "Exiting" << endl;
			break;
		}
		//Loop until Exit
		cout <<"Please choose direction: N,S,E,W or" << endl;
		cout << "Choose one of the options: " << endl;
		cout << "(A) Attack, (P) Pickup, (D) Drop, (L) Look, (I) Inventory, (X)Exit" << endl;
		cin >> option;
		//Increment counter
		counter++;
		//Call isNight function to change the flag to day or night
		isNight=ifNight(counter);
	}
	//Print gold
	cout << "Gold collected: " << player.printGold() << endl;
    return EXIT_SUCCESS;
}

bool ifNight(int cnt)
{
	if(cnt%10==0 || cnt%10==1 || cnt%10==2 || cnt%10==3 || cnt%10==4)
	{
		cout << "Its day" << endl;
		return false;
	}
	if(cnt%10==5 || cnt%10==6 || cnt%10==7 || cnt%10==8 || cnt%10==9)
	{
		cout << "Its night" << endl;
		return true;
	}
	return false;
}
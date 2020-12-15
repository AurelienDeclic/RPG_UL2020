#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"

using namespace std;

//Function to check if its day or night
bool ifNight(int cnt);

int main()
{
    Player player;
	Enemy enemyPlayer;
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
	cout << "Choose of the options: " << endl;
	cout << "(A) Attack, (X)Exit" << endl;
	cin >> option;
	player.initialiseAttributes(input); //Initialisation the player attributes
	player.showAttributes(); //Display player attributes
	cout << "Enemy" << endl;
	enemyPlayer.initialiseAttributes(); //Initialisation the enemy attributes
	enemyPlayer.showAttributes(); //Display enenmy attributes
	//Logic to execute until Exit(X)
	while(option!='X' || option!='x')
	{	
		//Check to ensure the race attributes are changed only when it changes to day or night
		if(counter%5==0)
		{
			player.alterStats(isNight);			//Currently only Orc status is altered.
			enemyPlayer.alterStats(isNight);
		}
		//If option chosen is to attack
		if(option=='A' || option=='a')
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
		//If any option other than A,X,P etc is picked then need to exit
		else{
			cout<< "Exiting" << endl;
			break;
		}
		//Loop until Exit
		cout << "Choose of the options: " << endl;
		cout << "(A) Attack, (X)Exit" << endl;
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
		return false;
	}
	if(cnt%10==5 || cnt%10==6 || cnt%10==7 || cnt%10==8 || cnt%10==9)
	{
		return true;
	}
}
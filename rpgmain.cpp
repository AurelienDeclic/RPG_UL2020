#include <cstdlib>
#include <iostream>
#include "player.h"
#include "race.h"
#include "enemy.h"

using namespace std;

bool ifNight(int cnt);

int main()
{
    Player player;
	Enemy enemyPlayer;
	int input;
	char option;
	int counter=0; //Counter to check for day and night and alter status, needs to be incremented after every move.
	//Board board();
	bool isNight;
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
	player.initialiseAttributes(input);
	player.showAttributes();
	cout << "Enemy" << endl;
	enemyPlayer.initialiseAttributes();
	enemyPlayer.showAttributes();
	while(option!='X' || option!='x')
	{	
		if(counter%5==0)
		{
			player.alterStats(isNight);			//bool true or false
			enemyPlayer.alterStats(isNight);
		}
		if(option=='A' || option=='a')
		{
			int attackDamage=0;
			attackDamage=player.attack(isNight); //Need to pass isNight instead of true
			if(attackDamage!=0)
			{
				enemyPlayer.defence(attackDamage, isNight); //Need to pass isNight instead of true
				//For testing
				int enemyhealth=0;
				enemyhealth=enemyPlayer.getEnemyHealth();
				cout << "Enemy health: " << enemyhealth << endl;
				if(enemyhealth<=0)
				{
					cout << "Enemy defeated. " << enemyPlayer.getDefenceValue() << " will be added to gold" << endl;
					player.GoldAdd(enemyPlayer.getDefenceValue());
					break;
				}
			}
			attackDamage=0;
			attackDamage=enemyPlayer.attack(isNight);
			if(attackDamage!=0)
			{
				player.defence(attackDamage, isNight);
				int playerhealth=0;
				playerhealth=player.getPlayerHealth();
				cout << "Player health: " << playerhealth << endl;
				if(playerhealth<=0)
				{
					cout << "LOSER" << endl;
					break;
				}	
			}
		}
		else{
			cout<< "Exiting" << endl;
			break;
		}
		cout << "Choose of the options: " << endl;
		cout << "(A) Attack, (X)Exit" << endl;
		cin >> option;
		counter++;
		isNight=ifNight(counter);
	}
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
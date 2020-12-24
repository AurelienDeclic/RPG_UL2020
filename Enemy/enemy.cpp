/**********************************************************
 * enemy.cpp 
 * Implementation of the Enemy class.
 * Contains constructor, destructor and all methods associated with the class.
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

//Include standard libraries and enemy interface.
#include <cstdlib>
#include <iostream>
#include "enemy.h"

using namespace std;

/*
 * Enemy constructor
 * Description: Used to initialise enemyRace attributes.	
 * Parameters: None
 * Return: None
 */
Enemy::Enemy(){
  initialiseAttributes();
}

/*
 * Enemy destructor
 * Description: Default enemy destructor.	
 * Parameters: None
 * Return: None
 */
Enemy::~Enemy(){
	
}

/*
 * Method name: initialiseAttributes
 * Description: Method to initialse enemy race attributes.	
 * Parameters: None
 * Return: None
 */
void Enemy::initialiseAttributes()
{
	int input;
	//Initialise random enemies for the board
	input=rand()%5+1;
	enemyRace.setAttributes(input);
	enemyHP=enemyRace.getHealth();
}

/*
 * Method name: showAttributes
 * Description: Method to display enemey attributes.	
 * Parameters: None
 * Return: None
 */
void Enemy::showAttributes()
{
	enemyRace.showAttributes();
}

/*
 * Method name: alterStats
 * Description: Method to alter enemy default race stats based on time [day/night].	
 * Parameters: boolean value of day or night
 * Return: None
 */
void Enemy::alterStats(bool isNight)
{
	enemyRace.alterStats(isNight);
}

/*
 * Method name: attack
 * Description: Method to attack player.	
 * Parameters: boolean value of day or night
 * Return: damage of type int
 */
int Enemy::attack(bool isNight)
{
	int damage;
	if(enemyRace.getCharacter()=="Human")
	{
		if(enemyRace.getAttackChance()>1) //Attack chance - 2/3
		{
			cout << "Enemy Attack successful" << endl;
			damage=enemyRace.getAttack();
		}
		else
		{
			cout << "Enemy Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(enemyRace.getCharacter()=="Elf")
	{
		cout << "Enemy Attack successful" << endl; //Attack chance always successful 1/1
		damage=enemyRace.getAttack();
	}
	else if(enemyRace.getCharacter()=="Dwarf")
	{
		if(enemyRace.getAttackChance()>1) // Attack chance - 2/3
		{
			cout << "Enemy Attack successful" << endl;
			damage=enemyRace.getAttack();
		}
		else
		{
			cout << "Enemy Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(enemyRace.getCharacter()=="Hobbit")
	{
		if(enemyRace.getAttackChance()>2) // Attack chance - 1/3
		{
			cout << "Enemy Attack successful" << endl;
			damage=enemyRace.getAttack();
		}
		else
		{
			cout << "Enemy Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(enemyRace.getCharacter()=="Orc")
	{
		if(isNight)
		{
			cout << "Enemy Attack successful" << endl; //Attack chance always successful in the night 1/1
			damage=enemyRace.getAttack();
		}
		else
		{
			if(enemyRace.getAttackChance()>3) // Attack chance - 1/4 in the day
			{
				cout << "Enemy Attack successful" << endl;
				damage=enemyRace.getAttack();
			}
			else
			{
				cout << "Enemy Attack Failed" << endl;
				damage =0;
			}
		}			
	}
	return damage;
}

/*
 * Method name: defence
 * Description: Method to defend from player attack.	
 * Parameters: damage of type int and boolean value of day or night
 * Return: None
 */
void Enemy::defence(int &damage, bool isNight)
{
	if(enemyRace.getDefence()>=damage) //If enemy defence > enemy attack damage
	{
		damageTaken=0;
	}
	else
	{
		damageTaken = damage - enemyRace.getDefence();
	}
	if(enemyRace.getCharacter()=="Human")
	{
		if(enemyRace.getDefenceChance()>1) //Defence chance 1/2
		{
			cout << "Enemy Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			enemyHP -= damageTaken;
		}			
	}
	else if(enemyRace.getCharacter()=="Elf")
	{
		if(enemyRace.getDefenceChance()>3) //Defence chance 1/4
		{
			cout << "Enemy Defence successful, health increased by 1" << endl;
			enemyHP += 1;
			
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			enemyHP -= damageTaken;
		}
	}
	else if(enemyRace.getCharacter()=="Dwarf")
	{
		if(enemyRace.getDefenceChance()>1) //Defence chance 2/3
		{
			cout << "Enemy Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			enemyHP -= damageTaken;
		}
	}
	else if(enemyRace.getCharacter()=="Hobbit")
	{
		if(enemyRace.getDefenceChance()>1) //Defence chance 2/3
		{
			damageTaken=rand()%6; //Successful defense, hobbit takes random damage 1-5
			cout << "Enemy Defence successful, however " << damageTaken << " damage is caused" << endl;
			enemyHP -= damageTaken;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			enemyHP -= damageTaken;
		}
	}
	else if(enemyRace.getCharacter()=="Orc")
	{
		if(isNight) //If its night
		{
			if(enemyRace.getDefenceChance()>1) //Defence chance 1/2 at night
			{
				cout << "Enemy Defence successful, health increased by 1" << endl;
				enemyHP += 1;
			}
			else
			{
				cout << "Enemy Defence failed" << endl;
				cout << "Enemy damage taken " << damageTaken << endl;
				enemyHP -= damageTaken;
			}
		}
		else
		{
			if(enemyRace.getDefenceChance()>3) //Defence chance 1/4 at day
			{
				cout << "Enemy Defence successful" << endl;
				cout << "However, enemy damage taken " << damageTaken/4 << endl;
				enemyHP = enemyHP - (damageTaken/4);
			}
			else
			{
				cout << "Enemy Defence failed" << endl;
				cout << "Enemy damage taken " << damageTaken << endl;
				enemyHP -= damageTaken;
			}
		}	
	}
}

/*
 * Method name: getEnemyHealth
 * Description: Method to display enemey current health.	
 * Parameters: None
 * Return: Enemy health of type int.
 */
int Enemy::getEnemyHealth()
{
	return enemyHP;
}

/*
 * Method name: getDefenceValue
 * Description: Method to display enemey defence value. 	
 * Parameters: None
 * Return: Enemy defence of type int.
 */
int Enemy::getDefenceValue()
{
	return enemyRace.getDefence();
}

/*
 * Method name: showCurrentStats
 * Description: Method to display enemey current status.	
 * Parameters: None
 * Return: None
 */
void Enemy::showCurrentStats()
{
	cout << "The enemey race is " << enemyRace.getCharacter() << endl;
	cout << "Current Enemy Attack damage: " << enemyRace.getAttack() << endl;
	cout << "Current Enemy Defence: " << enemyRace.getDefence() << endl;
	cout << "Current Enemy Strength: " << enemyRace.getStrength() << endl;
	cout << "Current Enemy Health: " << enemyHP << endl;
}

void Enemy::setCoordinates(int y, int x) {
    xCoord = x;
    yCoord = y;
}
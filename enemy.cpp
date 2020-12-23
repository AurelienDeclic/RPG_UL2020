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
	srand(static_cast<unsigned int>(time(NULL)));
	input=rand()%5+1;
	enemyRace.setAttributes(input);
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
		if(enemyRace.getAttackChance()>1)
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
		cout << "Enemy Attack successful" << endl;
		damage=enemyRace.getAttack();
	}
	else if(enemyRace.getCharacter()=="Dwarf")
	{
		if(enemyRace.getAttackChance()>1)
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
		if(enemyRace.getAttackChance()>2)
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
			cout << "Enemy Attack successful" << endl;
			damage=enemyRace.getAttack();
		}
		else
		{
			if(enemyRace.getAttackChance()>3)
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
	int hp;
	int damageTaken;
	if(enemyRace.getDefence()>=damage)
	{
		damageTaken=0;
	}
	else
	{
		damageTaken = damage - enemyRace.getDefence();
	}
	if(enemyRace.getCharacter()=="Human")
	{
		if(enemyRace.getDefenceChance()>1)
		{
			cout << "Enemy Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			hp = enemyRace.getHealth() - damageTaken;
			enemyRace.setHealth(hp);
		}			
	}
	else if(enemyRace.getCharacter()=="Elf")
	{
		if(enemyRace.getDefenceChance()>3)
		{
			cout << "Enemy Defence successful, health increased by 1" << endl;
			hp = enemyRace.getHealth()+1;
			enemyRace.setHealth(hp);
			
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			hp = enemyRace.getHealth() - damageTaken;
			enemyRace.setHealth(hp);
		}
	}
	else if(enemyRace.getCharacter()=="Dwarf")
	{
		if(enemyRace.getDefenceChance()>1)
		{
			cout << "Enemy Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			hp = enemyRace.getHealth() - damageTaken;
			enemyRace.setHealth(hp);
		}
	}
	else if(enemyRace.getCharacter()=="Hobbit")
	{
		if(enemyRace.getDefenceChance()>1)
		{
			damageTaken=rand()%6;
			cout << "Enemy Defence successful, however " << damageTaken << " damage is caused" << endl;
			hp = enemyRace.getHealth() - damageTaken;
			enemyRace.setHealth(hp);
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			cout << "Enemy damage taken " << damageTaken << endl;
			hp = enemyRace.getHealth() - damageTaken;
			enemyRace.setHealth(hp);
		}
	}
	else if(enemyRace.getCharacter()=="Orc")
	{
		if(isNight)
		{
			if(enemyRace.getDefenceChance()>1)
			{
				cout << "Enemy Defence successful, health increased by 1" << endl;
				hp = enemyRace.getHealth() + 1;
				enemyRace.setHealth(hp);
			}
			else
			{
				cout << "Enemy Defence failed" << endl;
				cout << "Enemy damage taken " << damageTaken << endl;
				hp = enemyRace.getHealth() - damageTaken;
				enemyRace.setHealth(hp);
			}
		}
		else
		{
			if(enemyRace.getDefenceChance()>3)
			{
				cout << "Enemy Defence successful" << endl;
				cout << "However, enemy damage taken " << damageTaken/4 << endl;
				hp = enemyRace.getHealth() - (damageTaken)/4;
				enemyRace.setHealth(hp);
			}
			else
			{
				cout << "Enemy Defence failed" << endl;
				cout << "Enemy damage taken " << damageTaken << endl;
				hp = enemyRace.getHealth() - damageTaken;
				enemyRace.setHealth(hp);
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
	return enemyRace.getHealth();
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
	cout << "Current Enemy Health: " << enemyRace.getHealth() << endl;
}
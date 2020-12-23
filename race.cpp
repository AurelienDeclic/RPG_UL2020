/**********************************************************
 * race.cpp 
 * Implementation of the Race class.
 * Contains all methods associated with the class.
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

//Include standard libraries and Race interface.
#include <cstdlib>
#include <iostream>
#include <string>
#include "race.h"

using namespace std;

/*
 * Method name: setAttributes
 * Description: Method to initialse race attributes.	
 * Parameters: Input of type integer
 * Return: None
 */
void Race::setAttributes(int input)
{
	switch(input)
	{
		case 1:
		character="Human";
		attack=30; 
        defence=20;
		health=60;
        strength=100;
		break;
		case 2:
		character="Elf";
		attack=40; 
        defence=10;
		health=40;
        strength=70;
		break;
		case 3:
		character="Dwarf";
		attack=30; 
        defence=20;
		health=50;
        strength=130;
		break;
		case 4:
		character="Hobbit";
		attack=25; 
        defence=20;
		health=70;
        strength=85;
		break;
		case 5:
		character="Orc";
		attack=25; 
        defence=10;
		health=50;
        strength=130;
		break;
	}
}

/*
 * Method name: showAttributes
 * Description: Method to display Race attributes.	
 * Parameters: None
 * Return: None
 */
void Race::showAttributes()
{
	cout << "Your player character is: " << character << "; Attack= " << attack << "; Defence= " << defence << ";Strength= " << strength << ";Health= " << health << endl;
}

/*
 * Method name: getAttackChance
 * Description: Method to calculate and provide a probability of a success attack	
 * Parameters: None
 * Return: integer 
 */
int Race::getAttackChance()
{
	srand(time(NULL));
	if(character=="Human")
	{
		return rand()%3+1;
	}
	else if(character=="Elf")
	{
		return 1;
	}
	else if(character=="Dwarf")
	{
		return rand()%3+1;
	}
	else if(character=="Hobbit")
	{
		return rand()%3+1;
	}
	else if(character=="Orc")
	{
		if(isNight)
		{
			return 1;
		}
		else
		{
			return rand()%4+1;
		}
	}
}

/*
 * Method name: getDefenceChance
 * Description: Method to calculate and provide a probability of a success defence	
 * Parameters: None
 * Return: integer 
 */
int Race::getDefenceChance()
{
	srand(time(NULL));
	if(character=="Human")
	{
		return rand()%2+1;
	}
	else if(character=="Elf")
	{
		return rand()%4+1;
	}
	else if(character=="Dwarf")
	{
		return rand()%3+1;
	}
	else if(character=="Hobbit")
	{
		return rand()%3+1;
	}
	else if(character=="Orc")
	{
		if(isNight)
		{
			return rand()%2+1;
		}
		else
		{
			return rand()%4+1;
		}
	}
}

/*
 * Method name: setHealth
 * Description: Method to update/set race health for player or enemy	
 * Parameters: Updated health point of type integer
 * Return: None 
 */
void Race::setHealth(int hp)
{
	health=hp;
}

/*
 * Method name: setStrength
 * Description: Method to update/set race strength of player	
 * Parameters:  Updated strength point of type integer
 * Return: None 
 */
void Race::setStrength(int str)
{
	strength=str;
}

/*
 * Method name: alterStats
 * Description: Method to alter race stats	
 * Parameters: boolean to know day or night
 * Return: None 
 */
void Race::alterStats(bool time)
{
	isNight=time;
	if(isNight)
	{
		if(character=="Orc")
		{
			attack=45;
			defence=25;
		}
	}
	else
	{
		if(character=="Orc")
		{
			attack=25;
			defence=10;
		}
	}
}
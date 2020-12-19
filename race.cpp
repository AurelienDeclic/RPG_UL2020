#include <cstdlib>
#include <iostream>
#include <string>
#include "race.h"

using namespace std;


void Race::setAttributes(string name, int att, int def, int hlt, int str)
{
		character=name;
		attack=att; 
        defence=def;
        strength=str;
        health=hlt;

}

void Race::showAttributes()
{
	cout << "Your player character is: " << character << "; Attack= " << attack << "; Defence= " << defence << ";Strength= " << strength << ";Health= " << health << endl;
}


string Race::getCharacter()
{
	return character;
}

int Race::getAttack()
{
	return attack;
}

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

int Race::getDefence()
{
	return defence;
}

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


int Race::getStrength()
{
	return strength;
}

int Race::getHealth()
{
	return health;
}

void Race::setHealth(int hp)
{
	health=hp;
}

void Race::setStrength(int str)
{
	strength=str;
}

void Race::alterStats(int att,int def, bool time)
{
	attack=att;
	defence=def;
	isNight=time;
}
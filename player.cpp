#include <cstdlib>
#include <iostream>
#include "player.h"
#include "race.h"
#include <string>

using namespace std;

void Player::initialiseAttributes(int input)
{
	gold=0;
	switch(input)
	{
		case 1:
		playerRace.setAttributes("Human", 30, 20, 60, 100);
		break;
		case 2:
		playerRace.setAttributes("Elf", 40, 10, 40, 70);
		break;
		case 3:
		playerRace.setAttributes("Dwarf", 30, 20, 50, 130);
		break;
		case 4:
		playerRace.setAttributes("Hobbit", 25, 20, 70, 85);
		break;
		case 5:
		playerRace.setAttributes("Orc", 25, 10, 50, 130);
		break;
	}
	
}

void Player::showAttributes()
{
	playerRace.showAttributes();
}

void Player::alterStats(bool isNight)
{
	if(isNight==true)
	{
		if(playerRace.getCharacter()=="Orc")
		{
			playerRace.alterStats(45, 25, true);
		}
	}
	else
	{
		if(playerRace.getCharacter()=="Orc")
		{
			playerRace.alterStats(25, 10, false);
		}
	}
	
}

int Player::attack(bool isNight)
{
	int damage;
	if(playerRace.getCharacter()=="Human")
	{
		if(playerRace.getAttackChance()>1)
		{
			cout << "Player Attack successful" << endl;
			damage=playerRace.getAttack();
		}
		else
		{
			cout << "Player Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(playerRace.getCharacter()=="Elf")
	{
		cout << "Player Attack successful" << endl;
		damage=playerRace.getAttack();
	}
	else if(playerRace.getCharacter()=="Dwarf")
	{
		if(playerRace.getAttackChance()>1)
		{
			cout << "Player Attack successful" << endl;
			damage=playerRace.getAttack();
		}
		else
		{
			cout << "Player Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(playerRace.getCharacter()=="Hobbit")
	{
		if(playerRace.getAttackChance()>2)
		{
			cout << "Player Attack successful" << endl;
			damage=playerRace.getAttack();
		}
		else
		{
			cout << "Player Attack Failed" << endl;
			damage =0;
		}			
	}
	else if(playerRace.getCharacter()=="Orc")
	{
		if(isNight)
		{
			cout << "Player Attack successful" << endl;
			damage=playerRace.getAttack();
		}
		else
		{
			if(playerRace.getAttackChance()>3)
			{
				cout << "Player Attack successful" << endl;
				damage=playerRace.getAttack();
			}
			else
			{
				cout << "Player Attack Failed" << endl;
				damage =0;
			}
		}			
	}
	return damage;
}

void Player::defence(int &damage, bool isNight)
{
	int hp;
	if(playerRace.getCharacter()=="Human")
	{
		if(playerRace.getDefenceChance()>1)
		{
			cout << "Player Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			hp = playerRace.getHealth() + playerRace.getDefence() - damage;
			playerRace.setHealth(hp);
		}			
	}
	else if(playerRace.getCharacter()=="Elf")
	{
		if(playerRace.getDefenceChance()>3)
		{
			cout << "Player Defence successful, health increased by 1" << endl;
			hp = playerRace.getHealth() + 1;
			playerRace.setHealth(hp);
			
		}
		else
		{
			cout << "Player Defence failed" << endl;
			hp = playerRace.getHealth() + playerRace.getDefence() - damage;
			playerRace.setHealth(hp);
		}
	}
	else if(playerRace.getCharacter()=="Dwarf")
	{
		if(playerRace.getDefenceChance()>1)
		{
			cout << "Player Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			hp = playerRace.getHealth() + playerRace.getDefence() - damage;
			playerRace.setHealth(hp);
		}
	}
	else if(playerRace.getCharacter()=="Hobbit")
	{
		if(playerRace.getDefenceChance()>1)
		{
			int randomDamage=rand()%6;
			cout << "Player Defence successful, however " << randomDamage << " damage is caused" << endl;
			hp = playerRace.getHealth() - randomDamage;
			playerRace.setHealth(hp);
		}
		else
		{
			cout << "Player Defence failed" << endl;
			hp = playerRace.getHealth() + playerRace.getDefence() - damage;
			playerRace.setHealth(hp);
		}
	}
	else if(playerRace.getCharacter()=="Orc")
	{
		if(isNight)
		{
			if(playerRace.getDefenceChance()>1)
			{
				cout << "Player Defence successful, health increased by 1" << endl;
				hp = playerRace.getHealth() + 1;
				playerRace.setHealth(hp);
			}
			else
			{
				cout << "Player Defence failed" << endl;
				hp = playerRace.getHealth() + playerRace.getDefence() - damage;
				playerRace.setHealth(hp);
			}
		}
		else
		{
			if(playerRace.getDefenceChance()>3)
			{
				cout << "Player Defence successful no damage taken" << endl;
			}
			else
			{
				cout << "Player Defence failed" << endl;
				hp = playerRace.getHealth() + (playerRace.getDefence() - damage)/4;
				playerRace.setHealth(hp);
			}
		}	
	}
}

int Player::getPlayerHealth()
{
	return playerRace.getHealth();
}

int Player::printGold()
{
	return gold;
}
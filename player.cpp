#include <cstdlib>
#include <iostream>
#include "player.h"
#include <string>

using namespace std;

void Player::initialiseAttributes(int input)
{
	gold=0;
	isItemPicked=false;
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
			damage=playerRace.getAttack() + playerInventory.getTotAttack();
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
		damage=playerRace.getAttack() + playerInventory.getTotAttack();
	}
	else if(playerRace.getCharacter()=="Dwarf")
	{
		if(playerRace.getAttackChance()>1)
		{
			cout << "Player Attack successful" << endl;
			damage=playerRace.getAttack() + playerInventory.getTotAttack();
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
			damage=playerRace.getAttack() + playerInventory.getTotAttack();
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
			damage=playerRace.getAttack() + playerInventory.getTotAttack();
		}
		else
		{
			if(playerRace.getAttackChance()>3)
			{
				cout << "Player Attack successful" << endl;
				damage=playerRace.getAttack() + playerInventory.getTotAttack();
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
	int damageTaken;
	if(playerRace.getDefence() + playerInventory.getTotDef()>=damage)
	{
		damageTaken=0;
	}
	else
	{
		damageTaken = damage - (playerRace.getDefence() + playerInventory.getTotDef());
	}	
	if(playerRace.getCharacter()=="Human")
	{
		if(playerRace.getDefenceChance()>1)
		{
			cout << "Player Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			hp = playerRace.getHealth() - damageTaken;
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
			cout << "Player damage taken " << damageTaken << endl;
			hp = playerRace.getHealth() - damageTaken;
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
			cout << "Player damage taken " << damageTaken << endl;
			hp = playerRace.getHealth() - damageTaken;
			playerRace.setHealth(hp);
		}
	}
	else if(playerRace.getCharacter()=="Hobbit")
	{
		if(playerRace.getDefenceChance()>1)
		{
			damageTaken=rand()%6;
			cout << "Player Defence successful, however " << damageTaken << " damage is caused" << endl;
			hp = playerRace.getHealth() - damageTaken;
			playerRace.setHealth(hp);
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			hp = playerRace.getHealth() - damageTaken;
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
				cout << "Player damage taken " << damageTaken << endl;
				hp = playerRace.getHealth() - damageTaken;
				playerRace.setHealth(hp);
			}
		}
		else
		{
			if(playerRace.getDefenceChance()>3)
			{
				cout << "Player Defence successful" << endl;
				cout << "However, Player damage taken " << damageTaken/4 << endl;
				hp = playerRace.getHealth() - (damageTaken)/4;
				playerRace.setHealth(hp);
			}
			else
			{
				cout << "Player Defence failed" << endl;
				cout << "Player damage taken " << damageTaken << endl;
				hp = playerRace.getHealth() - damageTaken;
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

void Player::itemPickup(armour eqArmour)
{
	playerInventory.pickup(eqArmour);
	int str;
	str = playerRace.getStrength() - eqArmour.getWeight();
	playerRace.setStrength(str);
}

void Player::itemPickup(weapon eqWeapon)
{
	playerInventory.pickup(eqWeapon);
	int str;
	str = playerRace.getStrength() - eqWeapon.getWeight();
	playerRace.setStrength(str);
}

void Player::itemPickup(shield eqShield)
{
	playerInventory.pickup(eqShield);
	int str;
	str = playerRace.getStrength() - eqShield.getWeight();
	playerRace.setStrength(str);
}

void Player::itemPickup(ring eqRing)
{
	playerInventory.pickup(eqRing);
	int hp;
	hp = playerRace.getHealth() + eqRing.getBHP();
	playerRace.setHealth(hp);
	int str;
	str = playerRace.getStrength() + eqRing.getBStrength() - eqRing.getWeight();
	playerRace.setStrength(str);
	
}

void Player::itemDrop()
{
	//Incomplete coz player needs to know the inventory dropped to set the new value of str and health (add or subtract).
	playerInventory.drop();
	//int str;
	//str = playerRace.getStrength() +/- Strength;
	//playerRace.setStrength(str);
	//Need to know if the item dropped is ring to resetHealth
	//int hp= playerRace.getHealth() +/- HP;
	//playerRace.setHealth(hp);
	
}

void Player::showCurrentStats()
{
	cout << "You picked race as " << playerRace.getCharacter() << endl;
	cout << "Current Attack damage: " << playerRace.getAttack() + playerInventory.getTotAttack() << endl;
	cout << "Current Defence: " << playerRace.getDefence() + playerInventory.getTotDef() << endl;
	cout << "Current Strength: " << playerRace.getStrength() << endl;
	cout << "Current Health: " << playerRace.getHealth() << endl;
}

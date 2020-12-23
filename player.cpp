/**********************************************************
 * player.cpp 
 * Implementation of the Player class.
 * Contains all methods associated with the class.
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

// Include standard library and player interface
#include <cstdlib>
#include <iostream>
#include "player.h"
#include <string>

using namespace std;

/*
 * Method name: initialiseAttributes
 * Description: Method to initialse player race attributes.	
 * Parameters: input which is of type integer provided in the console
 * Return: None
 */
void Player::initialiseAttributes(int input)
{
	gold=0;
	playerRace.setAttributes(input);
}

/*
 * Method name: showInitAttributes
 * Description: Method to display player attributes once a race is chosen in console.	
 * Parameters: None
 * Return: None
 */
void Player::showInitAttributes()
{
	playerRace.showAttributes();
}

/*
 * Method name: alterStats
 * Description: Method to alter player default race stats based on time [day/night].	
 * Parameters: boolean value of day or night
 * Return: None
 */
void Player::alterStats(bool isNight)
{
	playerRace.alterStats(isNight);
}

/*
 * Method name: attack
 * Description: Method to attack enemy.	
 * Parameters: boolean value of day or night
 * Return: damage of type int
 */
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

/*
 * Method name: defence
 * Description: Method to defend from enemy attack.	
 * Parameters: damage of type int and boolean value of day or night
 * Return: None
 */
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

/*
 * Method name: getPlayerHealth
 * Description: Method to display player current health.	
 * Parameters: None
 * Return: Player health of type int.
 */
int Player::getPlayerHealth()
{
	return playerRace.getHealth();
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Armour from the board.	
 * Parameters: Armour
 * Return: None
 */
void Player::itemPickup(armour eqArmour)
{
	playerInventory.pickup(eqArmour);
	int str;
	str = playerRace.getStrength() - eqArmour.getWeight();
	playerRace.setStrength(str);
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Weapon from the board.	
 * Parameters: Weapon
 * Return: None
 */
void Player::itemPickup(weapon eqWeapon)
{
	playerInventory.pickup(eqWeapon);
	int str;
	str = playerRace.getStrength() - eqWeapon.getWeight();
	playerRace.setStrength(str);
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Shield from the board.	
 * Parameters: Shield
 * Return: None
 */
void Player::itemPickup(shield eqShield)
{
	playerInventory.pickup(eqShield);
	int str;
	str = playerRace.getStrength() - eqShield.getWeight();
	playerRace.setStrength(str);
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Ring from the board.	
 * Parameters: Ring
 * Return: None
 */
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

/*
 * Method name: itemDrop
 * Description: Method to drop item on the board.	
 * Parameters: 
 * Return: None
 */
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

/*
 * Method name: showCurrentStats
 * Description: Method to display player current attributes.	
 * Parameters: None
 * Return: None
 */
void Player::showCurrentStats()
{
	cout << "You picked race as " << playerRace.getCharacter() << endl;
	cout << "Current Attack damage: " << playerRace.getAttack() + playerInventory.getTotAttack() << endl;
	cout << "Current Defence: " << playerRace.getDefence() + playerInventory.getTotDef() << endl;
	cout << "Current Strength: " << playerRace.getStrength() << endl;
	cout << "Current Health: " << playerRace.getHealth() << endl;
}

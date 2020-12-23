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
	PlayerSTR=playerRace.getStrength(); //Initialising player strength to race strength
	PlayerHP=playerRace.getHealth(); //Initialising player health to race health
	Xcoord = 200/2; //sets starting coordinates at the middle of the board
    Ycoord = 200/2;
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
			PlayerHP -= damageTaken;
		}			
	}
	else if(playerRace.getCharacter()=="Elf")
	{
		if(playerRace.getDefenceChance()>3)
		{
			cout << "Player Defence successful, health increased by 1" << endl;
			PlayerHP += 1;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			PlayerHP -= damageTaken;
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
			PlayerHP -= damageTaken;
		}
	}
	else if(playerRace.getCharacter()=="Hobbit")
	{
		if(playerRace.getDefenceChance()>1)
		{
			damageTaken=rand()%6;
			cout << "Player Defence successful, however " << damageTaken << " damage is caused" << endl;
			PlayerHP -= damageTaken;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			PlayerHP -= damageTaken;
		}
	}
	else if(playerRace.getCharacter()=="Orc")
	{
		if(isNight)
		{
			if(playerRace.getDefenceChance()>1)
			{
				cout << "Player Defence successful, health increased by 1" << endl;
				PlayerHP += 1;
			}
			else
			{
				cout << "Player Defence failed" << endl;
				cout << "Player damage taken " << damageTaken << endl;
				PlayerHP -= damageTaken;
			}
		}
		else
		{
			if(playerRace.getDefenceChance()>3)
			{
				cout << "Player Defence successful" << endl;
				cout << "However, Player damage taken " << damageTaken/4 << endl;
				PlayerHP = PlayerHP - (damageTaken)/4;
			}
			else
			{
				cout << "Player Defence failed" << endl;
				cout << "Player damage taken " << damageTaken << endl;
				PlayerHP -= damageTaken;
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
	return PlayerHP;
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Armour from the board.	
 * Parameters: Armour
 * Return: None
 */
void Player::itemPickup(armour eqArmour)
{
	//Logic to check if similar inventory is picked and if strength > eq weight
	if(((playerInventory.getArmor()).getString())=="NONE")
	{
		if(getPlayerSTR() >= eqArmour.getWeight())
		{
			playerInventory.pickup(eqArmour);
			updateStats();
		}
		else
		{
			cout << "You dont have enough strength to pick " << eqArmour.getString() << endl;
		}
	}
	else
	{
		cout << "Armour already picked, need to drop existing before picking another" << endl;
	}
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Weapon from the board.	
 * Parameters: Weapon
 * Return: None
 */
void Player::itemPickup(weapon eqWeapon)
{
	//Logic to check if similar inventory is picked and if strength > eq weight
	if(((playerInventory.getWeapon()).getString())=="NONE")
	{
		if(getPlayerSTR() >= eqWeapon.getWeight())
		{
			playerInventory.pickup(eqWeapon);
			updateStats();
		}
		else
		{
			cout << "You dont have enough strength to pick " << eqWeapon.getString() << endl;
		}
	}
	else
	{
		cout << "Weapon already picked, need to drop existing before picking another" << endl;
	}	
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Shield from the board.	
 * Parameters: Shield
 * Return: None
 */
void Player::itemPickup(shield eqShield)
{
	//Logic to check if similar inventory is picked and if strength > eq weight
	if(((playerInventory.getShield()).getString())=="NONE")
	{
		if(getPlayerSTR() >= eqShield.getWeight())
		{
			playerInventory.pickup(eqShield);
			updateStats();
		}
		else
		{
			cout << "You dont have enough strength to pick " << eqShield.getString() << endl;
		}
	}
	else
	{
		cout << "Shield already picked, need to drop existing before picking another" << endl;
	}
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Ring from the board.	
 * Parameters: Ring
 * Return: None
 */
void Player::itemPickup(ring eqRing)
{
	//Logic to check if player strength > ring weight
	if(getPlayerSTR() >= eqRing.getWeight())
	{
		playerInventory.pickup(eqRing);
		updateStats();
	}
	else
	{
		cout << "You dont have enough strength to pick " << eqRing.getString() << endl;
	}
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
	updateStats();
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
	cout << "Current Player Attack damage: " << playerRace.getAttack() + playerInventory.getTotAttack() << endl;
	cout << "Current Player Defence: " << playerRace.getDefence() + playerInventory.getTotDef() << endl;
	cout << "Current Player Strength utilised: " << playerInventory.getTotWeight() <<"/"<< getPlayerSTR() << endl;
	cout << "Current Player Health: " << getPlayerHP() << endl;
	cout << "Current Player Co-ordinates: [" << Ycoord << "][" << Xcoord << "]" << endl;
}

/*
 * Method name: updateStats
 * Description: Method to update player attributes.	
 * Parameters: None
 * Return: None
 */
void Player::updateStats()
{
	PlayerSTR=playerRace.getStrength()+playerInventory.getTotStrength();
	PlayerHP=playerRace.getHealth()+playerInventory.getTotHP();
}

/*
 *method movePlayer
 *input: integer   1:NORTH - 2:WEST - 3:SOUTH - 4:EAST
 *description: changes the players coordinate in function of input
 *output: none, modifies Xcoord and Ycoord value of player object
 */
void Player::movePlayer(char Direction)
{
  switch(Direction)
  {
    case 'n'://Moves the player to the north
    case 'N':
      if(Ycoord+1 < 200-1)
	  { //if we don't go out of bounds ---------------
		Ycoord++;
      }
	  else
	  {
		cout << "You can't go north anymore..." << endl;
      }
    break;
    case 'w': //Moves the player to the west
    case 'W':
      if((Xcoord-1) > 0)
	  {
		Xcoord--;
      }
	  else
	  {
		cout << "You can't go west anymore..." << endl;
      }
    break;
    case 's': //Moves the player to the south
    case 'S':
      if((Ycoord-1) > 0)
	  {
		Ycoord--;
      }
	  else
	  {
		cout << "You can't go south anymore..." << endl;
      }
    break;
    case 'e': //Moves the player to the East
    case 'E':
      if((Xcoord+1) < 200-1)
	  {
		Xcoord++;
      }
	  else
	  {
		cout << "You can't go east anymore..." << endl;
      }
    break;
  }
}
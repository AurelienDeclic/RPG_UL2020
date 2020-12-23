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
	gold=0; //Initial value set to zero
	playerRace.setAttributes(input); //Setting race attributes
	playerSTR=playerRace.getStrength(); //Initialising player strength to race strength
	playerHP=playerRace.getHealth(); //Initialising player health to race health
	xCoord = 200/2; //sets starting coordinates at the middle of the board
    yCoord = 200/2; //sets starting coordinates at the middle of the board
}

/*
 * Method name: showInitAttributes
 * Description: Method to display player attributes once a race is chosen in console.	
 * Parameters: None
 * Return: None
 */
void Player::showInitAttributes()
{
	playerRace.showAttributes(); //Show player initial attributes
}

/*
 * Method name: alterStats
 * Description: Method to alter player default race stats based on time [day/night].	
 * Parameters: boolean value of day or night
 * Return: None
 */
void Player::alterStats(bool isNight)
{
	playerRace.alterStats(isNight); //Alter race stats
}

/*
 * Method name: attack
 * Description: Method to attack enemy.	
 * Parameters: boolean value of day or night
 * Return: damage of type int
 */
int Player::attack(bool isNight)
{
	int damage; //Damage caused during attack
	if(playerRace.getCharacter()=="Human")
	{
		if(playerRace.getAttackChance()>1) //Attack chance - 2/3
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
		cout << "Player Attack successful" << endl; //Attack chance always successful 1/1
		damage=playerRace.getAttack() + playerInventory.getTotAttack();
	}
	else if(playerRace.getCharacter()=="Dwarf")
	{
		if(playerRace.getAttackChance()>1) // Attack chance - 2/3
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
		if(playerRace.getAttackChance()>2) // Attack chance - 1/3
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
		if(isNight) //If its night
		{
			cout << "Player Attack successful" << endl; //Attack chance always successful in the night 1/1
			damage=playerRace.getAttack() + playerInventory.getTotAttack();
		}
		else
		{
			if(playerRace.getAttackChance()>3) // Attack chance - 1/4 in the day
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
	if(playerRace.getDefence() + playerInventory.getTotDef()>=damage) //If players defence > enemy attack damage
	{
		damageTaken=0;
	}
	else
	{
		damageTaken = damage - (playerRace.getDefence() + playerInventory.getTotDef());
	}	
	if(playerRace.getCharacter()=="Human")
	{
		if(playerRace.getDefenceChance()>1) //Defence chance 1/2
		{
			cout << "Player Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			playerHP -= damageTaken;
		}			
	}
	else if(playerRace.getCharacter()=="Elf")
	{
		if(playerRace.getDefenceChance()>3) //Defence chance 1/4
		{
			cout << "Player Defence successful, health increased by 1" << endl;
			playerHP += 1;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			playerHP -= damageTaken;
		}
	}
	else if(playerRace.getCharacter()=="Dwarf")
	{
		if(playerRace.getDefenceChance()>1) //Defence chance 2/3
		{
			cout << "Player Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			playerHP -= damageTaken;
		}
	}
	else if(playerRace.getCharacter()=="Hobbit")
	{
		if(playerRace.getDefenceChance()>1) //Defence chance 2/3
		{
			damageTaken=rand()%6; //Successful defense, hobbit takes random damage 1-5
			cout << "Player Defence successful, however " << damageTaken << " damage is caused" << endl;
			playerHP -= damageTaken;
		}
		else
		{
			cout << "Player Defence failed" << endl;
			cout << "Player damage taken " << damageTaken << endl;
			playerHP -= damageTaken;
		}
	}
	else if(playerRace.getCharacter()=="Orc")
	{
		if(isNight) //If its night
		{
			if(playerRace.getDefenceChance()>1) //Defence chance 1/2 at night
			{
				cout << "Player Defence successful, health increased by 1" << endl;
				playerHP += 1;
			}
			else
			{
				cout << "Player Defence failed" << endl;
				cout << "Player damage taken " << damageTaken << endl;
				playerHP -= damageTaken;
			}
		}
		else
		{
			if(playerRace.getDefenceChance()>3) //Defence chance 1/4 at day
			{
				cout << "Player Defence successful" << endl;
				cout << "However, Player damage taken " << damageTaken/4 << endl;
				playerHP = playerHP - (damageTaken)/4;
			}
			else
			{
				cout << "Player Defence failed" << endl;
				cout << "Player damage taken " << damageTaken << endl;
				playerHP -= damageTaken;
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
	int hp = getPlayerHP() + playerInventory.getTotHP();
	return hp;
}

/*
 * Method name: itemPickup
 * Description: Method to pickup item of type Armour from the board.	
 * Parameters: Armour
 * Return: None
 */
void Player::itemPickup(armour eqArmour)
{
	//Logic to check if similar inventory is picked prior and if strength > eq weight
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
	//Logic to check if similar inventory is picked prior and if strength > eq weight
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
	//Logic to check if similar inventory is picked prior and if strength > eq weight
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
	//Drop item and update player attributes
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
	cout << "Current Player Health: " << getPlayerHP() + playerInventory.getTotHP() << endl;
	cout << "Current Player Co-ordinates: [" << yCoord << "][" << xCoord << "]" << endl;
}

/*
 * Method name: updateStats
 * Description: Method to update player strength based on item picked or dropped.	
 * Parameters: None
 * Return: None
 */
void Player::updateStats()
{
	playerSTR=playerRace.getStrength()+playerInventory.getTotStrength();
}

/*
 *Method name: movePlayer
 *Description: changes the players coordinate
 *Parameters: character  N/n:NORTH - W/w:WEST - S/s:SOUTH - E/e:EAST
 *Return: None
 */
void Player::movePlayer(char Direction)
{
  switch(Direction)
  {
    case 'n'://Moves the player to the north
    case 'N':
      if((yCoord+1) < 200-1) //to ensure we are inside the board
	  { 
		yCoord++;
      }
	  else
	  {
		cout << "You can't go north anymore..." << endl;
      }
    break;
    case 'w': //Moves the player to the west
    case 'W':
      if((xCoord-1) > 0)
	  {
		xCoord--;
      }
	  else
	  {
		cout << "You can't go west anymore..." << endl;
      }
    break;
    case 's': //Moves the player to the south
    case 'S':
      if((yCoord-1) > 0)
	  {
		yCoord--;
      }
	  else
	  {
		cout << "You can't go south anymore..." << endl;
      }
    break;
    case 'e': //Moves the player to the East
    case 'E':
      if((xCoord+1) < 200-1)
	  {
		xCoord++;
      }
	  else
	  {
		cout << "You can't go east anymore..." << endl;
      }
    break;
  }
}
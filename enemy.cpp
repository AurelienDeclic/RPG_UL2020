#include <cstdlib>
#include <iostream>
#include "enemy.h"
#include "race.h"


using namespace std;

void Enemy::initialiseAttributes()
{
	srand(time(NULL));
	switch(rand()%5+1)
	{
		case 1:
		enemyRace.setAttributes("Human", 30, 20, 60, 100);
		break;
		case 2:
		enemyRace.setAttributes("Elf", 40, 10, 40, 70);
		break;
		case 3:
		enemyRace.setAttributes("Dwarf", 30, 20, 50, 130);
		break;
		case 4:
		enemyRace.setAttributes("Hobbit", 25, 20, 70, 85);
		break;
		case 5:
		enemyRace.setAttributes("Orc", 25, 10, 50, 130);
		break;
	}
	
}

void Enemy::showAttributes()
{
	enemyRace.showAttributes();
}

void Enemy::alterStats(bool isNight)
{
	if(isNight==true)
	{
		if(enemyRace.getCharacter()=="Orc")
		{
			enemyRace.alterStats(45, 25, true);
		}
	}
	else
	{
		if(enemyRace.getCharacter()=="Orc")
		{
			enemyRace.alterStats(25, 10, false);
		}
	}
}

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

void Enemy::defence(int &damage, bool isNight)
{
	int hp;
	if(enemyRace.getCharacter()=="Human")
	{
		if(enemyRace.getDefenceChance()>1)
		{
			cout << "Enemy Defence successful no damage taken" << endl;
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			hp = enemyRace.getHealth() + enemyRace.getDefence() - damage;
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
			hp = enemyRace.getHealth() + enemyRace.getDefence() - damage;
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
			hp = enemyRace.getHealth() + enemyRace.getDefence() - damage;
			enemyRace.setHealth(hp);
		}
	}
	else if(enemyRace.getCharacter()=="Hobbit")
	{
		if(enemyRace.getDefenceChance()>1)
		{
			int randomDamage=rand()%6;
			cout << "Enemy Defence successful, however " << randomDamage << " damage is caused" << endl;
			hp = enemyRace.getHealth() - randomDamage;
			enemyRace.setHealth(hp);
		}
		else
		{
			cout << "Enemy Defence failed" << endl;
			hp = enemyRace.getHealth() + enemyRace.getDefence() - damage;
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
				hp = enemyRace.getHealth() + enemyRace.getDefence() - damage;
				enemyRace.setHealth(hp);
			}
		}
		else
		{
			if(enemyRace.getDefenceChance()>3)
			{
				cout << "Enemy Defence successful no damage taken" << endl;
			}
			else
			{
				cout << "Enemy Defence failed" << endl;
				hp = enemyRace.getHealth() + (enemyRace.getDefence() - damage)/4;
				enemyRace.setHealth(hp);
			}
		}	
	}
}

int Enemy::getEnemyHealth()
{
	return enemyRace.getHealth();
}

int Enemy::getDefenceValue()
{
	return enemyRace.getDefence();
}
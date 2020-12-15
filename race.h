#ifndef RACE_H
#define RACE_H

#include<string>

class Race{

    public:
		void setAttributes(std::string name, int att, int def, int str, int hlt);
        void showAttributes();
		std::string getCharacter();
		int getAttack();
		int getAttackChance();
		int getDefence();
		int getDefenceChance();
		int getStrength();
		int getHealth();
		void setHealth(int hp);
		void alterStats(int att,int def, bool time);
		//void updateHealth();
	
	protected:
        std::string character; // human or elf or etc...
        int attack;
        int attackChance; 
        int defence;
        int defenceChance;   // similar to attack chance
        int strength;
        int health;
		bool isNight; 
		//int updateStregnth;
		//int updateHealth;
        
};

#endif
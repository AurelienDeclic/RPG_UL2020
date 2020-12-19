#ifndef RACE_H
#define RACE_H

#include<string>

class Race{

    public:
		void setAttributes(std::string name, int att, int def, int hlt, int str); //Initialising stats of a character - Player/Enemy
        void showAttributes(); //Show race attributes
		std::string getCharacter(); //Function to get Character data.
		int getAttack(); //Function to get attack value.
		int getAttackChance(); //Function to get attack chance.
		int getDefence(); //Function to get defence value.
		int getDefenceChance(); //Function to get defence chance.
		int getStrength(); // Function to get strenght value.
		int getHealth(); //Function to get health value.
		void setHealth(int hp); //Function to update health based on attack/defence
		void setStrength(int str); //Function to add strength if ring of strength is picked
		void alterStats(int att,int def, bool time); //Function to alter stats of a race based on time of the day
	
	protected:
        std::string character; // human or elf etc...
        int attack;
        int attackChance; 
        int defence;
        int defenceChance;
        int strength;
        int health;
		bool isNight; //Is used to alter race abilities based on time of the day.
        
};

#endif
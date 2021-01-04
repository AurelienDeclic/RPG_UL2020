/**********************************************************
 * race.h 
 * Interface for the Race class
 * c++ programming language.
 * date created:	18.12.2020
 * date last-modified:	22.12.2020
 **********************************************************/

#ifndef RACE_H
#define RACE_H

class Race
{
    public:
		void setAttributes(int input); //Initialising stats of a character - Player/Enemy
        void showAttributes(); //Show race attributes
		inline std::string getCharacter(){return character;}; //Function to get Race name - Human/Orc/...
		inline int getAttack(){return attack;}; //Function to get attack value.
		int getAttackChance(); //Function to get attack chance.
		inline int getDefence(){return defence;}; //Function to get defence value.
		int getDefenceChance(); //Function to get defence chance.
		inline int getStrength(){return strength;}; // Function to get strength value.
		inline int getHealth(){return health;}; //Function to get health value
		void alterStats(bool time); //Function to alter stats of a race based on the time (day/night)
	
	private:
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
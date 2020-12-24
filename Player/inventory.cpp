#include <cstdlib>
#include <iostream>
#include "Player/inventory.h"


using namespace std;

/////////////////////////////////////////////////////
// inventory basic constructor:
// creates an inventory, and initialising it empty (ID 0 in item classes)
/////////////////////////////////////////////////////
inventory::inventory(){
  EqWeapon = weapon(0); //initialisation of items as "EMPTY" named items
  EqArmour = armour(0);
  EqShield = shield(0);
  //Dynamic allocation of rings:
  NRings = 1; //First ring created
  EqRings = new ring[NRings];
  EqRings[0] = ring(0); //First ring is "NONE"
  Update(); //sets all bonus values to 0 (empty inventory)
}
////////////////////////////////////////
//printInventory() function from class inventory
//prints using <iostream> the contents of the inventory to the screen.
//each inventory spot has an ID ranging from 1 to Nring +3
///////////////////////////////////////
void inventory::printInventory(){
  cout << "1 : Equiped Weapon => ";
  EqWeapon.printStats(); //Prints equiped weapon name and stats
  cout << endl  << "2 : Equiped Armour => ";
  EqArmour.printStats(); //Prints equiped armour name and stats
  cout << endl << "3 : Equiped Shield => ";
  EqShield.printStats(); //Prints equiped shield name and stats
  for(int i = 0; i < NRings; i++){ //loop to print the rings that are equiped (starting from inventory ID4)
    cout << endl << (i+4) << " : Ring n" << (i+1) << " => ";
    EqRings[i].printStats();
  }
  cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////
//pickup(item) functions   (for weapon, armour, shield)
//intput variables: Item on the players coordinates.
//each of these functions are setting the item that is "on the floor" as the Equiped weapon
//
//functions are the same but only difference is the object treated.
//light comments for the 2 last functions
//These functions also prints to the cmd using <iostream> what the player has picked up.
//////////////////////////////////////////////////////////////////////////////////

void inventory::pickup(weapon OnFloor){
  cout << "You picked up ";
  OnFloor.printStats();
  cout << " and placed it in your inventory" << endl;
  EqWeapon = OnFloor;//sets the Onfloor weapon to the equiped weapon
  //Remove weapon from the floor -------------------------------------------------------------------------------------------------------------
  Update();//updating overall bonuses...
}
void inventory::pickup(armour OnFloor){
  cout << "You picked up ";
  OnFloor.printStats();
  cout << " and placed it in your inventory" << endl;
  EqArmour = OnFloor;
  //delete item on floor from board class -----------------------------------------------------------------------------------------------------
  Update();
} 
void inventory::pickup(shield OnFloor){
  cout << "You picked up ";
  OnFloor.printStats();
  cout << " and placed it in your inventory" << endl;
  EqShield = OnFloor;
  // delete item on floor from board class-----------------------------------------------------------------------------------------------------
  Update();
}

/////////////////////////////////////////////////////////////////////////
//pickup(ring)
//picks up a ring object to the inventory object.
//
//Dynamically changes the size of the EqRings array, to add the picked ring to it.
/////////////////////////////////////////////////////////////////////////
void inventory::pickup(ring OnFloor){
  if(EqRings[0].getString() == "NONE"){ //if there is no ring in inventory ("EMPTY" ring)
    EqRings[0] = OnFloor; //sets onfloor ring as equiped ring
  }else
    { //Ring array is not empty
    ring *TempArr = new ring[++NRings]; //creates a new ring array with a size of Nrings+1
    for(int i = 0; i <= NRings-2 ; i++){ //copy pastes the values of the EqRings array to the TempArr arr, loop needed since they are not the same size
       TempArr[i] = EqRings[i];
    }
    delete[] EqRings; //delete the Old EqRings array
    EqRings = new ring[NRings]; //creates a new one with the right size
    EqRings = TempArr; //copies the temporary array to the EqRings array
    EqRings[NRings-1] = OnFloor; //sets the last ring of the list to be the picked up one
  }
  cout << "You picked up "; //informs the user of what he has done
  OnFloor.printStats();
  cout << " and placed it in your inventory" << endl;
  Update();//updates every bonus value.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//drop() function.
//
//This function firstly shows the user the inventory and the bonus statistics from the latter
//it then asks the user which item he would like to drop on the tile (integer describing the item).
//depending on the choice made, will drop the weapon on the board and set a "NONE" item.
//if the object is a ring, calls the function DeleteRing() to remove the right ring from the ring array.
////////////////////////////////////////////////////////////////////////////////////////////////////
void inventory::drop(){
  //To add: if space is not occupied, what do we do? ----------------------------------------------------------------------------------------------
  printInventory(); //shows the inventory to the user
  printBonusStats(); //prints the statistics to the user
  cout << "which item would you like to drop ? (enter integer)" << endl;
  int choice;
  cin >> choice; //waiting for users choice
  if(choice > 0 && choice <= NRings+3){ //if choice is possible (ID is shown on the screen)
    switch(choice){
      case 1: //The weapon has been chosen
	if(EqWeapon.getString() != "NONE"){//if there is a weapon equiped
	  // DROP WEAPON ON BOARD FROM BOARD CLASS---------------------------------------------------------------------------------------------
	  EqWeapon = weapon(0);
	}else{cout << "You have no weapon equiped!" << endl;}//if not: tell the user and do nothing
	break;
      case 2: //Armour has been chosen
	if(EqArmour.getString() != "NONE"){
	  // DROP ARMOUR ON BOARD FROM BOARD CLASS---------------------------------------------------------------------------------------------
	  EqArmour = armour(0);
	}else{cout << "You have no armour equiped!" << endl;}
	break;
      case 3: //the shield has been chosen
	if(EqShield.getString() != "NONE"){
	  // DROP SHIELD ON BOARD FROM BOARD CLASS---------------------------------------------------------------------------------------------
	  EqShield = shield(0);
	}else{cout << "You have no shield equiped!" << endl;}
	break;
      default://the ring has been chosen
	if(EqRings[0].getString() != "NONE"){ // if there are rings in the inventory
	  // SET SELECTED RING (EqRing[choice-4]) ON BOARD FROM BOARD CLASS--------------------------------------------------------------------
	  DeleteRing(choice-4); //calls the function DeleteRing() ranging from 0 to NRings-1
	}else{cout << "You have no Rings equiped!" << endl;} //if there are no rings, tell the user and do nothing.
    }
  }else{ //if choice is not possible (ID is not printed to the screen)
    cout << "You can not drop something that does not exist !" << endl;
  }
  Update();
}

///////////////////////////////////////////////////////////////////////////////////////////
//function Deletering(integer) : PRIVATE FUNCTION
//variables: integer representing the position in the EqArray that needs to be deleted
//description: deletes a ring and keeps all the others. Dynamically resizes the
//    EqRings.
///////////////////////////////////////////////////////////////////////////////////////////
void inventory::DeleteRing(int EMP){
  ring *TempArr = new ring[NRings-1]; //creates a new empty array with a size of Nrings-1
  if(NRings == 1){ //if the last ring has to be deleted
    EqRings[0]=ring(0);//set the last ring as "NONE"
  }
  else{
    for(int i = 0; i < NRings; i++){ //scanning the entire size of the EqRings array
      if(i < EMP){ //until we haven't reached the value to be deleted
	TempArr[i] = EqRings[i];//copy the EqRing array ring object to the TempArr array
      }
      else if(i > EMP){//when we reach the EMP value, do nothing. and then:
	TempArr[i-1] = EqRings[i];//Copy the EqRing array to the TempArr with an offset.
      }
    }//TempArr is now a value of size-1 with all the rings except the one at EqRings[EMP]

    delete[] EqRings; //delete the old EqRings object
    EqRings = new ring[--NRings]; //initiate a new ring object with the right size, lowers the value of NRings
    EqRings = TempArr; //copy the temporary array
  }
}//end of function: TempArray deleted

/////////////////////////////////////////////////////////////////////////
//Update() function, PRIVATE
//sets all the values from the items equiped to the bonus stats values.
/////////////////////////////////////////////////////////////////////////
void inventory::Update(){ //function updating the bonus values
  //Adding the bonus values from the Weapon, Shield, and armour items that are equiped
  TotWeight = EqWeapon.getWeight() + EqShield.getWeight() + EqArmour.getWeight();
  TotAttackBonus = EqWeapon.getBAttack() + EqShield.getBAttack() + EqArmour.getBAttack();
  TotDefBonus = EqWeapon.getBDefense() + EqShield.getBDefense() + EqArmour.getBDefense();
  TotHPBonus = EqWeapon.getBHP() + EqShield.getBHP() + EqArmour.getBHP();
  TotStrengthBonus = EqWeapon.getBStrength() + EqShield.getBStrength() + EqArmour.getBStrength();
  
  //Adding the values from the rings...
  for(int i = 0; i < NRings; i++){
    TotWeight += EqRings[i].getWeight();
    TotAttackBonus += EqRings[i].getBAttack();
    TotDefBonus += EqRings[i].getBDefense();
    TotHPBonus += EqRings[i].getBHP();
    TotStrengthBonus += EqRings[i].getBStrength();
  }
}

///////////////////////////////////////////////////////////////
//printBonusStats():
//Prints all the bonus stats to the screen
///////////////////////////////////////////////////////////////
void inventory::printBonusStats(){
  cout << "Total bonus from inventory items: " << "W" << TotWeight
       << " A" << TotAttackBonus << " D" << TotDefBonus
       << " HP" << TotHPBonus << " S" << TotStrengthBonus
       << endl;
}

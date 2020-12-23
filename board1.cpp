#include <iostream>
#include "enemy.h"


using namespace std;


int main()
{
  int size=200;
  int tab[size][size];
  int l, c;
  int r;
  int i,e;

  /*Choice of level between 1 and 3 
  * i is the percentage of items
  * 100-e is the percentage of enemies*/

  int level;
  cout << "Please enter the level between 1 and 3" << endl;
  cin >> level;
  if (level==1)
    {
      i=40;
      e=80;
    }
  if (level==2)
    {
      i=35;
      e=65;
    }
  if (level==3)
    {
      i=30;
      e=60;
    }
  /*Creation of the board 
  * 1 corresponds to an enemy
  * 2 corresponds to an item
  * -1 corresponds to an empty location*/
 
  for(l=0; l<size; l++)
    {
      for(c=0; c<size; c++)
	{
	  r= rand()%100;
	  if (r<=i)
	    {
	     tab[l][c]=2;
	    }
	  if (r>=e)
	    {
	     tab[l][c]=1;
	    }
	  if ((r>i)&&(r<e)) 
	    {
	      tab[l][c]=-1;
	    }
		     
	  cout << "[" << tab[l][c] << "]";
	}
      cout << endl;
    }
  cout << endl;

  return EXIT_SUCCESS;

}


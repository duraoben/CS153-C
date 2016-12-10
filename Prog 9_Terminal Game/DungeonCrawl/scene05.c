#include <stdio.h>
#include <stdlib.h>
#include "actor.h"
#include "utilities.h"

extern char buffer[132]; 
extern actor hero;
extern actor monster;
 
void scene05( int monsterHit, int monsterStr )
{

  printf("  You continue deeper into the mine.\n\n");
  printf("  The room reveals a immense body of water. It kinds of stinks.\n ");
  printf(" Do you take a dip in the pool? (y or n): ");
  gets(buffer);
  
  if(buffer[0] == 'y' || buffer[0] == 'Y')
  {
	int toss = randInt(1,12);
	
	/* Hero jumps into the water */
	
	/* and fails miserably. */
	if(toss < 5)
	{
	  printf(" You do a cannonball into the water! COWABUNGA!!!!\n");
	  printf(" A huge sea serpent awakes from the splash and eats you.\n");
	  hero.hitPoints = 0;
	}
	else /* success! */
	{
	  printf(" This water really does stink, and now you stink!\n");
	  printf(" As you are swimming, a sparkle catches your eye at the bottom of the water.\n");
	  printf(" Should you dive toward it? (y or n): ");
	  gets(buffer);
	  
	  
	  if(buffer[0] == 'y' || buffer[0] == 'Y')
	  {
		/* Hero dives to get the buried treasure! */
		printf(" You pull a mysterious ring from the sand.\n");
		printf(" Happy with the new find you get out of the water and gaze at the ring with a new obsession. MY PRECIOUS!\n");
		printf(" You decide to move on from this room and pocket your ring.\n\n");
		hero.gold += 100;
		hero.strength += 5;
		hero.maxStrength += 5;
		heroSummary();
		printf("\n");
	  }
	}
  }
  
}

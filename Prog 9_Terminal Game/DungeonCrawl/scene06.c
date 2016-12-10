#include <stdio.h>
#include <stdlib.h>
#include "actor.h"
#include "utilities.h"

extern char buffer[132]; 
extern actor hero;
extern actor monster;
 
void scene06part2()
{
	printf(" The dragon bursts into flames upon death.\n");
	printf(" You notice the chest that the beast was guarding.\n");
	printf(" Do you want to open the chest? (y or n): ");
	gets(buffer);
	
	if(buffer[0] == 'y' || buffer[0] == 'Y')
	{
		int toss = randInt(1,12);
		
		if(toss < 5)
		{
			printf(" It's a trap!\n The chest bursts into a ball of fire incinerating you and all the treasure.\n");
			hero.hitPoints = 0;
		}
		else
		{
			printf(" The chest reveals the Ancient Amulet of Truth And Awesomeness! The inscription reads:\n Belongs to Dr. Kjell.\n");
			printf(" You do a celebration dance then move on.\n\n");
			hero.gold += 10000;
		}
	}
} 

void scene06( int monsterHit, int monsterStr )
{

  printf("  You continue deeper into the mine.\n\n");
  printf("  A dragon awakes from a deep slumber and looks directly at you! \n\n ");
  
  makeActor(&monster, (char *)"Dragon", monsterHit, monsterStr, 0);
  monsterSummary();
  printf("\n");
  
  sortie();
  if (monster.hitPoints<=0 && hero.hitPoints>0)
	scene06part2();
}



// CS 153 PROGRAM ASSIGNMENT #4
//
// Dice Game
//
// Ben Durao
//
// October 7, 2016

/* Dice Game
The game consists of 7 rounds.
Each round consists of the player's turn followed by the computer's turn.
Each round is either won by the player, or won by the computer.
The winner of the game is whoever wins the most rounds.
The player's turn:
 The player throws three dice.
 The player's score for the turn is the largest value of the three dice.
 The player may choose to reject the throw and throw three dice again
(but in this case the computer will throw four dice.)
 The new score is again the largest value of the three dice.
 Only the first throw may be rejected. The outcome of the second throw
 (if done) is the final score for the turn.
The computer's turn:
 The computer throws three or four dice.
 The computer throws four dice when the player threw twice.
 The computer's score is the largest value of the dice thrown.

 The winner of the round is whoever has the highest score.
 In the case of a tie, the computer wins the round.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char input[132];   /* user input buffer */

int throwDie()
{
  static int initialized = 0;
  int num;
  
  if ( !initialized )
  {
    printf("Initializing Die!!!\n\n");
    srand( time(NULL) );
    initialized = 1;
  }
  num = rand()%6 + 1 ;
  return num;
}

/* Human turn
|
|  This is the future and it was made more interesting.
|
*/
int humanTurn(int *extra)
{
  /* reset extra turn indicator */
  *extra = 0;
  int toss1, toss2, toss3, max, c;
  /* throw dice for round */
  toss1 = throwDie();
  toss2 = throwDie();
  toss3 = throwDie();
  printf("You throw %d, %d, %d\n", toss1, toss2, toss3 );
  
  /* determine highest value Die */
  if(toss1 >= toss2 && toss1 >= toss3)
    {max = toss1;}
  else if(toss2 >= toss1 && toss2 >= toss3)
    {max = toss2;}
  else
    {max = toss3;}
	/* print score */
   printf("Your score is: %d\n", max);
   printf("Do you wish to throw again? [Y or N]\t");
   fflush(stdout);
   
   // get input if user wants to throw again.
   fflush(stdout);
   c = getchar();
   // if input is Y then set extra roll to true and reroll else exit and return
   if(c == 'Y')
   {
    *extra = 1;
	toss1 = throwDie();
    toss2 = throwDie();
    toss3 = throwDie();
    printf("You throw: %d, %d, %d\n", toss1, toss2, toss3 );
    if(toss1 >= toss2 && toss1 >= toss3)
      {max = toss1;}
    else if(toss2 >= toss1 && toss2 >= toss3)
      {max = toss2;}
    else
      {max = toss3;}
   printf("Your score is: %d\n", max);
   }
  return max;
}

/* Computer turn
|
|  This is still the more interesting future... but cpu still at the mercy of humans.
|
*/
int computerTurn(int *extra)
{
  int toss1, toss2, toss3, toss4, max;
  
  /* throw the dice */
  toss1 = throwDie();
  toss2 = throwDie();
  toss3 = throwDie();
  
  /* if player had an extra turn use all 4 dice */
  if(*extra == 1) { 
    toss4 = throwDie();
	if(toss1 >= toss2 && toss1 >= toss3 && toss1 >= toss4)
      {max = toss1;}
    else if(toss2 >= toss1 && toss2 >= toss3 && toss2 >= toss4)
      {max = toss2;}
    else if(toss3 >= toss1 && toss3 >= toss2 && toss3 >= toss4)
      {max = toss3;}
	else
	  {max = toss4;}
	printf("Computer throws: %d, %d, %d, %d\n", toss1, toss2, toss3, toss4 ); 
	printf("The CPU score is: %d\n", max);
  }
  else
  { 
    if(toss1 >= toss2 && toss1 >= toss3)
      {max = toss1;}
    else if(toss2 >= toss1 && toss2 >= toss3)
      {max = toss2;}
    else
      {max = toss3;}
	  
	/* print throws and score for round */
    printf("Computer throws: %d, %d, %d\n", toss1, toss2, toss3 ); 
	printf("The CPU score is: %d\n", max);
  
  }
  
  return max;
}

int main(int argc, char *argv[])
{
  int round, humanWins=0, computerWins=0;
  int extra;
  int humanToss, computerToss;
  const int numberOfRounds = 7;
  
  /* Play the Rounds */
  for ( round = 1; round<=numberOfRounds; round++ )
  {
    extra = 0;
    printf("\nRound %d\n\n", round );
	fflush(stdout);
    printf("Player's Turn: (hit enter)");
	fflush(stdout);
    gets( input ); /* pause for dramatic effect */
    humanToss = humanTurn(&extra);
    printf("\nComputer's Turn: (hit enter)\n");
	fflush(stdout);
    gets( input ); /* pause for dramatic effect */
    computerToss = computerTurn(&extra);
    
    /* Determine Winner of the Round */
    if ( humanToss > computerToss )
    {
      humanWins++;
      printf("\tHuman wins the round.    human: %3d. computer: %3d\n",
        humanWins, computerWins );
    }
    else if ( computerToss > humanToss )
    {
      computerWins++;
      printf("\tComputer wins the round. human:%3d. computer: %3d\n",
        humanWins, computerWins );
    }
    else if ( computerToss == humanToss)
    {
      printf("\tTie.                     human:%3d. computer: %3d\n",
        humanWins, computerWins );
    }
  }

  /* Determine Winner of the Game */
  if ( humanWins > computerWins )
    printf("\n\nWINNER!! The human wins the game!\n");
  else if ( computerWins > humanWins )
    printf("\n\nThe computer wins the game!\n");
  else
    printf("\n\nTie Game!\n");

  printf("\n");
  system("pause");
  return 0;
}
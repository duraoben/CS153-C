// CS 153 PROGRAM ASSIGNMENT #7
//
// More Simple Programs
//
// Ben Durao
//
// November 4, 2016

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char input[132];   /* user input buffer */
int NUMWORDS = 5;
int WORDSIZE;

void scramble(char *string)
{
	char temp;
	int j;
	int randIndex;
	
	/* go through every char in string, grab the char at a random index and swap it with the current index's char */
	for(j=0;j<strlen(string);j++)
	{
		randIndex = rand() % strlen(string);
		temp = string[j];
		string[j] = string[randIndex];
		string[randIndex] = temp;
	}
	
}

void playGame(char *word)
{
	int guesses = 3; /* user starts with 3 guesses */
	
	/* get original word */
	char origin[WORDSIZE];
	strcpy(origin, word);	
	
	/* scramble the word */
	scramble(word);
	
	/* guessing game */
	while(guesses > 0)
	{
		printf("You have %d guesses left.\n", guesses);
		printf("\nReady to play? (hit enter)\n");
		fflush(stdout);
		gets( input ); /* pause for dramatic effect */
		
		fflush(stdout);

		
		printf("Unscramble this word: %s\nYour Answer: ", word);
		fflush(stdout);
		gets(input); /* get the user's guess */

		if(strcmp(input, origin) == 0) /* if the user's guess matches the original word = WIN and exit */
		{
			printf("Winner!!!\n");
			guesses = -1;
		}
		else /* guess again */
		{
			printf("Wrong! Try Again!\n");
			guesses--;
		}
		
	}
	if(guesses == 0) /* used up all the guesses GAME OVER */
	{
		printf("Game Over You Lose!\n");
	}
}

int main()
{
	// Init Random
	srand( time(NULL) );
	
	// Init Words to potentially play with.. set global constant NUMWORDS to the number of words in play
	char const *words[NUMWORDS] = { "pumpkin", "cantalope", "watermelon", "apple", "kumquat" };
	char original[WORDSIZE];
	int randomWord = rand()%NUMWORDS;
	strcpy(original, words[randomWord]);
	
	
	playGame(original);
	return 0;
}
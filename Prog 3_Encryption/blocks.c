// CS 153 PROGRAM ASSIGNMENT #3
//
// Cipher Tools - blocks: Output characters in groups of five
//
// Ben Durao
//
// September 30, 2016

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	// read in stream of ASCII from std in and send char to std output
	int c;
	
	// get the first char
	c = getchar();
	int charInGroup = 0;
	int groupsInLine = 1;
	
	while(c!= EOF)
	{
		//remove all non-letters
		if(!isalpha(c))
		{
		  c = getchar();
		  continue;
		}
		else
		{
			// send char to std out as capital
			putchar(toupper(c));
			charInGroup++;
			
			// char are seperated in groups of 5 then space, after 10 groups = new line, ALL CAPS
			if(groupsInLine == 10 && charInGroup == 5)
			{
				putchar('\n');
				groupsInLine = 1;
				charInGroup =0;
			}
			else if(charInGroup == 5)
			{
				putchar(' ');
				groupsInLine++;
				charInGroup =0;
			}

			// get the next char
			c = getchar();
		}
	}
	
	
	return 0;
}
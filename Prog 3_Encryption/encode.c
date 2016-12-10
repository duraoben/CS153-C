// CS 153 PROGRAM ASSIGNMENT #3
//
// Cipher Tools - encode: take in input and shift letters to the right 3;
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
	
	// stream char until end of file
	while(c != EOF)
	{	
		// remove any non letter, new line, space
		if(!isalpha(c) && c != ' ' && c != '\n' )
		{
		  c = getchar();
		  continue;
		}
		else
		{
		// if there is a space or new line keep it and get the next char to transform
			if(c == ' ' || c == '\n')
			{
				putchar(c);
				c = getchar();
				continue;
			}
			else
			{
			// transform the char by shifting it 3 spots right.
				c = c + 3;
				// if the char goes over the alphabet limit, run it back to the start of the alpha
				if(c > 'Z')
				{
					c = 'A' + (c - ('Z' + 1));
				}
			}
			//send c to std output
			putchar(c);
			// read in the next char
			c = getchar();
		}
	}
	
	return 0;
}
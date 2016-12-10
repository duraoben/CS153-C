// CS 153 PROGRAM ASSIGNMENT #3
//
// Cipher Tools - decode: take in input and shift char 3 to the right.
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
			// transform the char by shifting it 3 left.
				c = c - 3;
				// if the char goes under the alphabet limit, run it back to the end of the alpha
				if(c < 'A')
				{
					c = 'Z' - ('A' - (c + 1));
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
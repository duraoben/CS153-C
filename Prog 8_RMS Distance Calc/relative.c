// CS 153 PROGRAM ASSIGNMENT #8
//
//  Computational Stylistics (big data)
// Calculates the relative frequency of the input file[1st arg]'s chars [A>Z] and outputs to the file supplied by the 2nd arg
//
// Ben Durao
//
// November 11, 2016

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[] )
{
	// init char holder
	int c;
	// init the letter counters
	double A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,count;
	A=B=C=D=E=F=G=H=I=J=K=L=M=N=O=P=Q=R=S=T=U=V=W=X=Y=Z=count=0.0;
	
	// open the input file and output file
	FILE *fr = fopen(argv[1],"r");
	FILE *fw = fopen(argv[2],"w");
	// get the first char from input file
	c = fgetc(fr);
	
	while(c!= EOF)
	{
		//remove all non-letters
		if(!isalpha(c))
		{
		  c = fgetc(fr);
		  continue;
		}
		else
		{
			// if lowercase change to uppercase
			if( !isupper(c) ) { c = toupper(c); }

			if(c == 'A'){A++;}
			else if(c == 'B'){B++;}
			else if(c == 'C'){C++;}
			else if(c == 'D'){D++;}
			else if(c == 'E'){E++;}
			else if(c == 'F'){F++;}
			else if(c == 'G'){G++;}
			else if(c == 'H'){H++;}
			else if(c == 'I'){I++;}
			else if(c == 'J'){J++;}
			else if(c == 'K'){K++;}
			else if(c == 'L'){L++;}
			else if(c == 'M'){M++;}
			else if(c == 'N'){N++;}
			else if(c == 'O'){O++;}
			else if(c == 'P'){P++;}
			else if(c == 'Q'){Q++;}
			else if(c == 'R'){R++;}
			else if(c == 'S'){S++;}
			else if(c == 'T'){T++;}
			else if(c == 'U'){U++;}
			else if(c == 'V'){V++;}
			else if(c == 'W'){W++;}
			else if(c == 'X'){X++;}
			else if(c == 'Y'){Y++;}
			else if(c == 'Z'){Z++;}
			else {printf("\nError!\n");}
			
			// get the next char
			count++;
			c = fgetc(fr); 	
		}
	}
	// calculate relative frequency and print it to output file
	fprintf(fw,"A %lf\n", A/count);
	fprintf(fw,"B %lf\n", B/count);
	fprintf(fw,"C %lf\n", C/count);
	fprintf(fw,"D %lf\n", D/count);
	fprintf(fw,"E %lf\n", E/count);
	fprintf(fw,"F %lf\n", F/count);
	fprintf(fw,"G %lf\n", G/count);
	fprintf(fw,"H %lf\n", H/count);
	fprintf(fw,"I %lf\n", I/count);
	fprintf(fw,"J %lf\n", J/count);
	fprintf(fw,"K %lf\n", K/count);
	fprintf(fw,"L %lf\n", L/count);
	fprintf(fw,"M %lf\n", M/count);
	fprintf(fw,"N %lf\n", N/count);
	fprintf(fw,"O %lf\n", O/count);
	fprintf(fw,"P %lf\n", P/count);
	fprintf(fw,"Q %lf\n", Q/count);
	fprintf(fw,"R %lf\n", R/count);
	fprintf(fw,"S %lf\n", S/count);
	fprintf(fw,"T %lf\n", T/count);
	fprintf(fw,"U %lf\n", U/count);
	fprintf(fw,"V %lf\n", V/count);
	fprintf(fw,"W %lf\n", W/count);
	fprintf(fw,"X %lf\n", X/count);
	fprintf(fw,"Y %lf\n", Y/count);
	fprintf(fw,"Z %lf\n", Z/count);
	
	return 0;
}
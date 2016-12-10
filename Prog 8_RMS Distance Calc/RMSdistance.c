// CS 153 PROGRAM ASSIGNMENT #8
//
//  Computational Stylistics (big data)
// RMSdifference computes the root mean square of the difference between 
// relative frequencies of letters used by two authors.
//
// Ben Durao
//
// November 11, 2016

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[] )
{
	// init the arrays that will hold the relative freq of each file
	double freq1[26];
	double freq2[26];
	double diffSq, average, meanSq, rms;
	
	// open the input file1 and input file2
	FILE *fr1 = fopen(argv[1],"r");
	FILE *fr2 = fopen(argv[2],"r");
	// scan for the relative freq and place in appropriate array & sum their difference
	int i;
	for(i=0;i<26;i++)
	{
		fscanf(fr1, "%*c %lf ",&freq1[i]);
		fscanf(fr2, "%*c %lf ",&freq2[i]);
		diffSq += (freq1[i] - freq2[i]) * (freq1[i] - freq2[i]);
	}
	
	meanSq = diffSq / 26;
	rms = sqrt(meanSq);
	
	printf("The RMS of the Files: %lf\n", rms);
	fclose(fr1);
	fclose(fr2);
	return 0;
}
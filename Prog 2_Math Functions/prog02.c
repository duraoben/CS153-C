// CS 153 PROGRAM ASSIGNMENT #2
//
// More Simple Programs
//
// Ben Durao
//
// September 20, 2016

#define _USE_MATH_DEFINES /* needed to use M_PI */
#include <math.h>
#include <stdio.h>

int main01()
{
	double u, sd, N, x, f; /* mean = u, sd = standard deviation */
	
	printf("Enter the mean: ");
	fflush(stdout);
	scanf("%lf", &u);
	
	printf("Enter the standard deviation: ");
	fflush(stdout);
	scanf("%lf", &sd);
	
	printf("Enter N (number of values): ");
	fflush(stdout);
	scanf("%lf", &N);

	int j;
	for(j=0; j<=N; j++)
	{
		printf("Enter value: ");
		fflush(stdout);
		scanf("%lf", &x);
		
		f = ( 1 / (sd * (sqrt(2 * M_PI))) ) * exp( (-1/2) * ( ((x-u)/sd) * ((x-u)/sd) ) );
		printf("The function of %lf is %lf\n", x, f);
	}
	
	return 0;
}

#include <stdio.h>

int sumDivisors(int num)
{
	int sum = 0; 
	int i;
	for(i=1;i <= num/2;i++)
		{
			if(num%i==0)
				sum += i;
		}
	return sum;
}

int main02()
{
	int low, hi, N, S, a; // low limit and high limit
	
	printf("Enter the lower limit: ");
	fflush(stdout);
	scanf("%d", &low);
	
	printf("Enter the high limit: ");
	fflush(stdout);
	scanf("%d", &hi);
	
	for(N=low; N<= hi;N++)
	{
		S = sumDivisors(N);
		a = sumDivisors(S);
		if(S == N){
			printf("%d is perfect.\n", N);
			fflush(stdout);
		}
		else if(a == N) {
			printf("%d and %d are amicable pairs.\n", N, S);
			fflush(stdout);
			}
	}
	
	return 0;
}
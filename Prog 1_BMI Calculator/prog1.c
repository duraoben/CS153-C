// CS 153 PROGRAM ASSIGNMENT #1
//
// BMI and Quadratic Formula
//
// Ben Durao
//
// September 13, 2016

#include <stdio.h>
#include <math.h>

int main01(void)
{
	double bmi, w, h;
	int weight, height;
	
	/* Get user weight and height as doubles. */
	printf("Enter your weight in pounds -> ");
	fflush(stdout);
	scanf("%d", &weight);
	
	printf("Enter your height in inches -> ");
	fflush(stdout);
	scanf("%d", &height);
	
	/* Convert inches to feet */
	h = (double)height / 12.0;
	w = (double)weight;
	
	/* Calculate BMI and print out correct label*/
	bmi = (w * 4.88) / (h * h);
	
	if(bmi < 20.0) {printf("underweight");}
	else if(bmi >= 20.0 && bmi < 25.0) {printf("normal");}
	else if(bmi >= 25.0 && bmi < 30.0) {printf("slightly overweight");}
	else if(bmi >= 30.0 && bmi < 40.0) {printf("overweight");}
	else if(bmi >= 40.0) {printf("extremely overweight");}
	else {printf("error");}
	
	return 0;
}

int main02(void)
{
	double a, b, c, discriminant, quadp, quadm, root1, root2, running;
	
	// Init Values to start loop.
	running = 1.0;
	
	while(running == 1.0)
	{
		// Get Input from user
		printf("Enter A -> ");
		fflush(stdout);
		scanf("%lf", &a);
		
		printf("Enter B -> ");
		fflush(stdout);
		scanf("%lf", &b);
		
		printf("Enter C -> ");
		fflush(stdout);
		scanf("%lf", &c);
		
		// Run loop? Ends program if all inputs are zero.
		if(a == 0.0 && b == 0.0 && c == 0.0) {
			running = 0.0;
			break;
		}
		
		// Non Quadratic Evaluations
		if(a == 0.0 && b == 0.0) {
			printf("Error! A & B are both 0.\n");
			fflush(stdout);
		}
		else if(a == 0.0) {
			root1 = -c / b;
			printf("Linear. Root at %lf\n", root1);
			fflush(stdout);
		}
		else {
			// Quadratic Evaluations
			discriminant = (b*b) - (4.0 * a * c);
			quadp = (-b + sqrt(discriminant)) / (2.0 * a);
			quadm = (-b - sqrt(discriminant)) / (2.0 * a);
			
			if(discriminant < 0.0) {
				printf("No real roots.\n");
				fflush(stdout);
			}
			else if(discriminant == 0.0) {
				root1 = quadp;
				printf("One Root: %lf\n", root1);
				fflush(stdout);
			}
			else {
				root1 = quadp;
				root2 = quadm;
				printf("Two Roots: %lf  %lf\n", root1, root2);
				fflush(stdout);
			}
		}
	}	
		return 0;
}
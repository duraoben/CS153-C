// Ben Durao
// CS 153
// Program 06
// Oct 30, 2016

#include <stdio.h>

int arrayMax(int array[], int length)
{
	// if array is empty return 0
	if(length <= 0) {return 0;}
	
	int j;
	int max = 0;
	// traverse array and find the max value;
	for(j=0;j<length;j++)
	{
	 if(array[j] > max) {max = array[j];}
	}
	
	return max;
}

int arrayMaxP(int *array, int length)
{
	// if array is empty return 0
	if(length <= 0) {return 0;}
	
	int *max;
	max = array;
	*max = *array;
	int j;
	
	
	// traverse array and find the max value;
	for(j = 1; j<length; j++ )
	{
	 if(*(array + j) > *max) {*max = *(array + j);}
	}
	return *max;
	
}

int arrayMinMax(double array[], int length, double *min, double *max)
{
	if(length < 1) {return 0;}
	if(length == 1) 
	{
		*max = array[0];
		*min = array[0];
	}
	else
	{
		*min = 0;
		*max = 0;
		int j;
		for(j=0;j<length;j++)
		{
			if(array[j] < *min)
			{*min = array[j];}
			if(array[j] > *max)
			{*max = array[j];}
		}
	}
	return 1;
}


int main(void)
{
	int array[5] = {0,-1,3,100,-1};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("Max value of array is %d\n", arrayMax(array, length));
	
	length = 0;
	printf("Max value of array is %d\n", arrayMax(array, length));
	
	length = -1;
	printf("Max value of array is %d\n", arrayMax(array, length));
	
	int *p_array = array;
	length = sizeof(array)/sizeof(array[0]);
	printf("\nMax value of array is %d\n", arrayMaxP(p_array, length));
	
	length = 0;
	printf("\nMax value of array is %d\n", arrayMaxP(p_array, length));
	
	length = -1;
	printf("\nMax value of array is %d\n", arrayMaxP(p_array, length));
	
	double arr[5] = {0.0,0.0,-1.2,100.0,3};
	double min = 0, max = 0;
	double *p_min = &min;
	double *p_max = &max;
	length = sizeof(arr)/sizeof(arr[0]);
	arrayMinMax(arr,length, p_min, p_max);
	printf("\nMax value of array is %lf\nMin value of array is %lf\n", max, min);
	
	min = 0, max = 0;
	length = 0;
	arrayMinMax(arr,length, p_min, p_max);
	printf("\nMax value of array is %lf\nMin value of array is %lf\n", max, min);
	
	min = 0, max = 0;
	length = 1;
	arrayMinMax(arr,length, p_min, p_max);
	printf("\nMax value of array is %lf\nMin value of array is %lf\n", max, min);
	return 0;
}
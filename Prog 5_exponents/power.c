#include <stdio.h>
#include <math.h>

double myexp(double x) {
    double sum = 1, term = 1;
    int n;
    for(n=1;n<100;n++)
    {
        term = term * x / n;
        sum += term;
    }
    
    return sum;
}

double mylog(double y) {
	if(y <= 0.0)
		return 0;
	else 
	{
		double x = (y-1)/(y+1);
		int j;
		double xpow =1;
		double sum = 0;
		for(j=1;j<=201;j=j+2)
		{
			sum = sum + (x * xpow / j);
			xpow = xpow * x * x;
		}
		sum = 2 * sum;
		return sum;
	}
}

double mypow(double x, double p)
{
	double result = 0;
	result = myexp(p * mylog(x));
	return result;
}

int main(void) {
	double x, p;
	
	x = 2.4;
	printf("Enter x --> ", x);
	printf("Actual e^x: %18.14lf\n", exp( x ) );
	printf("My e^x: %18.14lf\n", myexp( x ) );
	
	x = 3.0;
	printf("Enter x --> ", x);
	printf("Actual log(x): %18.14lf\n", log( x ) );
	printf("My log(x): %18.14lf\n", mylog( x ) );
	
	x = 3.0;
	p = 2.0;
	printf("Enter x --> ", x);
	printf("Enter p --> ", p);
	printf("Actual pow(x,p): %18.14lf\n", pow( x, p ) );
	printf("My pow(x,p): %18.14lf\n", mypow( x,p ) );
	return 0;

}

#include <stdio.h>
#include <math.h>

double si(double x){
	x=floor(x-0.5)+1.0;
	return 0;
}

double main(double y){
	y=scanf("%lf",&y);
	printf("The result is %lf",si(y));
	return 0;
}




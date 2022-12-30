#include <stdio.h>
#include <math.h>

int is_leap_year(int year)
{
	int a,b;
	a=year%400;
	b=((year%4==0)&&(year%100!=0));
	printf("a=%d,b=%d",a,b);
    if((year%400==0)||((year%4==0)&&(year%100!=0)))
        printf("This year is leap year.\n");
    else
        printf("This year is not leap year.\n");
		return 0;
}

int main()
{
   //scanf("%d",&x);
   int x = 2020;
   is_leap_year(x);
   return 0;
}

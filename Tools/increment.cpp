#include <stdio.h>

int X=0;
int Y=0;
int Color = 0;

void increment()
{
	if(X<128 & Y<160)
	{
		X++;
		printf("X incremented ");
	}
	else if(X>=128 & Y<160)
	{
		X=0;
		Y++;
		printf("X = 0, Y incremented ");
	}
	else if(X<128 & Y>=160)
	{
		X++;
		printf("X incremented ");
	}
	else if(X>=128 & Y>=160)
	{
		X=0;
		Y=0;
		Color++;
		printf("X = 0, Y = 0 ");
	}
	printf("X:%d Y:%d\n", X, Y);
}

main(){
	int i=0;
	
	while(i<20000)
	{
		increment();
		i++;
	}
	
}



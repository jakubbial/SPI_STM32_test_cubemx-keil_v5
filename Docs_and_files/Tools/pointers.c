#include <stdio.h>
#include <stdlib.h>


main()
{
	int *ass = (int *)calloc(10, sizeof(int));
	
	*ass = 1;
	*(ass+1) = 2;
	
	int i, val;
	
	for(i=0; i<11; i++)
	{
		val = *(ass++);
		printf("Value of %d is: %d\n", i, val);
	}
}


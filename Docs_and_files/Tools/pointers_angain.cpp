#include <stdio.h>
#include <stdlib.h>




main()
{
	int var = 0;
	int *var_p = &var;
	printf("Var: %d, Var_p: %x\n", var, var_p);
	*var_p = 0x01111111;
	printf("Var: %d, Var_p: %x\n", var, var_p);
}


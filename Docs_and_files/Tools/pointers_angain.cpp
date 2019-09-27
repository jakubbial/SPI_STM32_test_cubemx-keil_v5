#include <stdio.h>
#include <stdlib.h>

#define uint32_t int


main()
{
	uint32_t *timer7_register = (uint32_t *)malloc(4);
	*timer7_register = 0x40001024;
			
	printf("timer_reg_p: %x\n", *timer7_register);
	printf("timer_reg_p: %x\n", timer7_register);
}


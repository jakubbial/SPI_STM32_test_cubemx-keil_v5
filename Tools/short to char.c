#include <stdio.h>


main()
{
	unsigned short Dana_16 = 0xABCD;
	unsigned short* Dana_16_p = &Dana_16;
	
	printf("Dana: %X Dana_p: %X Dana_p po wskazniku %X\n", Dana_16, Dana_16_p, *Dana_16_p);
	
	unsigned char* Dana_starszy_p = (unsigned char*)Dana_16_p;
	printf("Dana_starszy_p: %X Dana_starszy_p po wskazniku: %X\n", Dana_starszy_p, *Dana_starszy_p);
	Dana_starszy_p++;
	printf("Dana_mlodszy_p: %X Dana_mlodszy_p po wskazniku: %X\n", Dana_starszy_p, *Dana_starszy_p);
}


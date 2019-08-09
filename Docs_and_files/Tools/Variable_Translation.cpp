#include <stdio.h>

unsigned char* Konwert_Danych(unsigned short data, unsigned char* Arr);

main()
{
	unsigned short	DwuBajtowa	= 0x1234;
	unsigned char*	Arr;
	unsigned char	Data_Arr[2] = {0,0};
	
	Konwert_Danych(DwuBajtowa, Data_Arr);
	
	printf("Value %X\nOlder %X\nYounger %X\n", DwuBajtowa, Data_Arr[0], Data_Arr[1]);
}


unsigned char* Konwert_Danych(unsigned short data, unsigned char* Arr)
{
	Arr[0] = data>>8;
	Arr[1] = data;
}

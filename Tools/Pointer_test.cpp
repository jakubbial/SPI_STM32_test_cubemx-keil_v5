#include <stdio.h>


main(){
	
	int Color = 0xFFFF;
	int* Color_p = &Color;
	short int* Color_p_ch = (short int*)Color_p;
	printf("Color  : %X\nColor_p: %X\nColorCh: %hd\n", Color, Color_p, Color_p_ch);
	
	int Got_Color_p = *Color_p;
	int Got_Color_ch = *Color_p_ch;
	
	printf("Got_Color_p: %X\nGot_Color_Ch: %hd\n", Got_Color_p, Got_Color_ch);
}

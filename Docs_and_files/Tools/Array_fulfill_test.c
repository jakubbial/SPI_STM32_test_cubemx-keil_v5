#include <stdio.h>


int Number_of_pixels = 20480;
int LCD_Data[20480];



void LCD_Data_Preparation(int Color);


main(){
	LCD_Data_Preparation(0xFFFF);
	printf("%X\n", LCD_Data[1]);
}


void LCD_Data_Preparation(int Color){
	int i;
	for(i=0;i<Number_of_pixels;i++){
		LCD_Data[i] = Color;
		//printf("%X\n", LCD_Data[i]);
	}
}

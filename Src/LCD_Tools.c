#include "LCD_Tools.h"
#include "spi.h"
#include "gpio.h"

#define DATA 0
#define COMMAND 1


//enum Display_Type {1_8_Small=1, 2_8_Big=2};


/* Procedure to initialize LCD display */
void LCD_Init_procedure(void)
{
	DC_Pin(RES);
	CS_Pin(RES);
	RESX_Pin(RES);
	HAL_Delay(5);
	
	RESX_Pin(SET);
	HAL_Delay(5);
	RESX_Pin(RES);
	HAL_Delay(5);
	RESX_Pin(SET);
	CS_Pin(SET);
	HAL_Delay(5);
	CS_Pin(RES);
}


/* Setup and configure displaying method*/
void LCD_Init(void)
{
	// start procesure 
	LCD_Init_procedure();
	HAL_Delay(10);
	
	// data/commands to send
	uint8_t LcdInitVal_Array[74][2] = {
	{COMMAND ,0x11},
	{COMMAND ,0xB1},
	{DATA ,0x05},
	{DATA ,0x3C},
	{DATA ,0x3C},
	{COMMAND ,0xB2},
	{DATA ,0x05},
	{DATA ,0x3C},
	{DATA ,0x3C},
	{COMMAND ,0xB3},
	{DATA ,0x05},
	{DATA ,0x3C},
	{DATA ,0x3C},
	{DATA ,0x05},
	{DATA ,0x3C},
	{DATA ,0x3C},
	{COMMAND ,0xB4},
	{DATA ,0x03},
	{COMMAND ,0xC0},
	{DATA ,0x28},
	{DATA ,0x08},
	{DATA ,0x04},
	{COMMAND ,0xC1},
	{DATA ,0XC0},
	{COMMAND ,0xC2},
	{DATA ,0x0D},
	{DATA ,0x00},
	{COMMAND ,0xC3},
	{DATA ,0x8D},
	{DATA ,0x2A},
	{COMMAND ,0xC4},
	{DATA ,0x8D},
	{DATA ,0xEE},
	{COMMAND ,0xC5},
	{DATA ,0x1A},
	{COMMAND ,0x36},
	{DATA ,0xC0},
	{COMMAND ,0xE0},
	{DATA ,0x04},
	{DATA ,0x22},
	{DATA ,0x07},
	{DATA ,0x0A},
	{DATA ,0x2E},
	{DATA ,0x30},
	{DATA ,0x25},
	{DATA ,0x2A},
	{DATA ,0x28},
	{DATA ,0x26},
	{DATA ,0x2E},
	{DATA ,0x3A},
	{DATA ,0x00},
	{DATA ,0x01},
	{DATA ,0x03},
	{DATA ,0x13},
	{COMMAND ,0xE1},
	{DATA ,0x04},
	{DATA ,0x16},
	{DATA ,0x06},
	{DATA ,0x0D},
	{DATA ,0x2D},
	{DATA ,0x26},
	{DATA ,0x23},
	{DATA ,0x27},
	{DATA ,0x27},
	{DATA ,0x25},
	{DATA ,0x2D},
	{DATA ,0x3B},
	{DATA ,0x00},
	{DATA ,0x01},
	{DATA ,0x04},
	{DATA ,0x13},
	{COMMAND ,0x3A},  //COLMOD: Interface Pixel Format (03h - 12-bit/pixel, 05h - 16-bit/pixel, 06h - 18-bit/pixel)
	{DATA ,0x05},
	{COMMAND ,0x29}
	};
	
	//send data / commands each one by one
	int i;
	for(i=0; i<74; i++) {
			if(LcdInitVal_Array[i][0] == 1){
				SPI_Send_Command_8bit(&LcdInitVal_Array[i][1]);
			}
			else if (LcdInitVal_Array[i][0] == 0){
				SPI_Send_Data_8bit(&LcdInitVal_Array[i][1]);
			}
		}
}


/*
Color mode is set as 16 bit/pixel. Data have to be 16-bit.
Display types:	1 - 1.8, 128x160
								2 - 2.8, 240x320
*/
void Fill_display(uint8_t Display_Type, uint16_t Color)
{
	uint32_t i;
	uint32_t Number_of_pixels = 0;
	
	/*	1.8 - 128x160 (20480 piksels) */
	if(Display_Type == 1){
		Number_of_pixels = 20480;
	}
	/* 2.8 - 240x320 (76800 piksels) */
	else if(Display_Type == 2){
		Number_of_pixels = 76800;
	}
	
	uint16_t color_table[Number_of_pixels];
	
	for(i=0; i<Number_of_pixels; i++){
		color_table[i] = Color;
		SPI_Send_Data_16bit(&Color, 1);
	}
	
	//uint16_t an = 0xFFFF;
	//SPI_Send_Data_16bit(&an, 1);
	
	SPI_Send_Data_16bit(color_table, Number_of_pixels);
}

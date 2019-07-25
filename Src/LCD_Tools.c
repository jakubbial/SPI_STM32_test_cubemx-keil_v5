#include "LCD_Tools.h"
#include "spi.h"

#define DATA 0
#define COMMAND 1

/*
	void SPI_Send_Data(uint8_t *Data);
	void SPI_Send_Command(uint8_t *Data);
*/


void LCD_Init()
{
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
	{COMMAND ,0x3A},
	{DATA ,0x05},
	{COMMAND ,0x29}
	};
	
	//send initialize procedure
	int i;
	for(i=0; i<74; i++) {
			if(LcdInitVal_Array[i][0] == 1){
				SPI_Send_Command(&LcdInitVal_Array[i][1]);
			}
			else if (LcdInitVal_Array[i][0] == 0){
				SPI_Send_Data(&LcdInitVal_Array[i][1]);
			}
		}
}

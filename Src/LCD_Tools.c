#include "LCD_Tools.h"
#include "spi.h"
#include "gpio.h"
#define SMALL_DISPLAY


#ifdef SMALL_DISPLAY
uint32_t Number_of_pixels = 128;
uint16_t LCD_Data[128];
#endif

#ifdef BIG_DISPLAY
uint32_t Number_of_pixels = 76800;
uint16_t LCD_Data[76800];
#endif


/* Fulfill LCD_Data array with Color */
void LCD_Data_Preparation(uint16_t Color){
	uint8_t i;
	for(i=0;i<Number_of_pixels;i++){
		LCD_Data[i] = Color;
	}
}


/* Color mode is set as 16 bit/pixel. Data have to be 16-bit. */
void Fill_display(void)
{	
	SPI_Send_Data_16bit(LCD_Data, Number_of_pixels);
}


/* Procedure to initialize LCD display */
void LCD_Init_HW(void){
	
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
void LCD_Configure(void)
{

	
	
	// Configure display (data/commands to send)
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



void Set_Address (void){
	uint8_t Address_1 = 0x2A;
	uint8_t Dat_1 = 0;
	uint8_t Dat_2 = 0x64;
	
	SPI_Send_Command_8bit(&Address_1);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_2);
	
	uint8_t Address_2 = 0x2B;
	SPI_Send_Command_8bit(&Address_2);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_1);
	SPI_Send_Data_8bit(&Dat_2);
	
	uint8_t Address_3 = 0x2C;
	SPI_Send_Command_8bit(&Address_3);
}



void LCD_Init(void){
	LCD_Init_HW();
	HAL_Delay(10);
	LCD_Configure();
	LCD_Data_Preparation(0xFB01);
	Set_Address();
	MX_SPI2_Init_16BIT();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
	Fill_display();
}



#include "LCD_Tools.h"
#include "spi.h"
#include "gpio.h"
#define SMALL_DISPLAY


#ifdef SMALL_DISPLAY									// 128x160 pixels
uint32_t Num_of_pixels_row = 128; 		// 128d
uint32_t Num_of_pixels_col = 160; 		// 160d
uint16_t LCD_Data[128];
#endif

#ifdef BIG_DISPLAY										 // 240x320 pixels
uint32_t Number_of_pixels_row = 0xF0;  // 240d
uint32_t Number_of_pixels_col = 0x140; // 320d
uint16_t LCD_Data[240];
#endif

/* Procedure to run LCD HW */
/* Tested and work correctly */
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
void LCD_Configure(void){
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
	uint8_t i;
	for(i=0; i<74; i++)
	{
		if(LcdInitVal_Array[i][0] == 1)
		{
			SPI_Send_Command(LcdInitVal_Array[i][1]);
		}
		else if (LcdInitVal_Array[i][0] == 0)
		{
			SPI_Send_Data_8bit(&LcdInitVal_Array[i][1], 1);
		}
	}
}


/* Function that is setting area to write */
void Set_Address (uint8_t Start_X, uint8_t End_X, uint8_t Start_Y, uint8_t End_Y){
	uint8_t Zero = 0;
	
	SPI_Send_Command(PIXEL_ADDR_REG_1);
	SPI_Send_Data_8bit(&Zero, 1);			// Starting point X-axis 1st byte - MSB XS
	SPI_Send_Data_8bit(&Start_X, 1);	// Starting point X-axis 2nd byte - LSB XS
	SPI_Send_Data_8bit(&Zero, 1);			// Ending point X-axis 1st byte - MSB XE
	SPI_Send_Data_8bit(&End_X, 1);		// Ending point X-axis 2nd byte - MSB XE
	
	SPI_Send_Command(PIXEL_ADDR_REG_2);
	SPI_Send_Data_8bit(&Zero, 1);			// Starting point Y-axis 1st byte - MSB XS
	SPI_Send_Data_8bit(&Start_Y, 1);	// Starting point Y-axis 2nd byte - LSB XS
	SPI_Send_Data_8bit(&Zero, 1);			// Ending point Y-axis 1st byte - MSB XE
	SPI_Send_Data_8bit(&End_Y, 1);		// Ending point Y-axis 2nd byte - MSB XE
	
	SPI_Send_Command(PIXEL_ADDR_REG_3);
}

/* Fulfill LCD_Data array with Color */
void LCD_Data_Preparation(uint16_t Color){
	uint8_t i;
	for(i=0;i<Num_of_pixels_row;i++){
		LCD_Data[i] = Color;
	}
}


/* Color mode is set as 16 bit/pixel. Data have to be 16-bit. */
void Fill_display(uint16_t Color)
{
	uint8_t i = 0;
	LCD_Data_Preparation(Color);
	for(i=0;i<Num_of_pixels_col;i++)
	{
		HAL_Delay(1);
		SPI_Send_Data_16bit(LCD_Data, Num_of_pixels_row);
	}
}

/* LCD initialize procedure */
void LCD_Init(void)
{
	LCD_Init_HW();
	LCD_Configure();
	HAL_Delay(5);
	Set_Address(0, Num_of_pixels_row, 0, Num_of_pixels_col);
	Fill_display(0xB7cB);
}

void Draw_Point(uint8_t X, uint8_t Y, uint16_t Color)
{
	Set_Address(X, X, Y, Y);
	SPI_Send_Data_16bit(&Color, 1);
}

void Fill_Display_By_Points(uint16_t Color)
{
	uint8_t X=0;
	uint8_t Y=0;
		
	while(X<128 & Y<160)
	{
		Draw_Point(X, Y, Color);
		// HAL_Delay(1);
		if(X<127 & Y<159)
		{
			X++;
		}
		else if(X>=127 & Y<159)
		{
			X=0;
			Y++;
		}
		else if(X<127 & Y>=159)
		{
			X++;
		}
		else if(X>=127 & Y>=159)
		{
			X=0;
			Y=0;
		}
	}
}
	

void LCD_DrawLine(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color)
{						
	if (Xstart > Num_of_pixels_row || Ystart > Num_of_pixels_col || Xend > Num_of_pixels_row || Yend > Num_of_pixels_col)
	{
		return;
	}

	uint8_t Xpoint = Xstart; 
	uint8_t Ypoint = Ystart; 
	int32_t dx = (int32_t)Xend - (int32_t)Xstart >= 0 ? Xend - Xstart : Xstart - Xend;
	int32_t dy = (int32_t)Yend - (int32_t)Ystart <= 0 ? Yend - Ystart : Ystart - Yend;
	
	// Increment direction, 1 is positive, -1 is counter;
	int32_t XAddway = Xstart < Xend ? 1 : -1;
	int32_t YAddway = Ystart < Yend ? 1 : -1;
	
	//Cumulative error
	int32_t Esp = dx + dy;
	int8_t Line_Style_Temp = 0;

	for (;;)
	{
		Line_Style_Temp++;
		Draw_Point(Xpoint, Ypoint, Color);
				
    if(2 * Esp >= dy)
		{
			if (Xpoint == Xend) break;
			Esp += dy;
			Xpoint += XAddway;
		}
		if(2 * Esp <= dx) 
		{
			if (Ypoint == Yend) break;
			Esp += dx;
			Ypoint += YAddway;
		}
	}
}



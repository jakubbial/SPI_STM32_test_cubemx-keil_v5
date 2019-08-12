#include "LCD_Tools.h"
#include "spi.h"
#include "gpio.h"
#include "string.h"
#include "stdlib.h"

#define SMALL_DISPLAY


#ifdef SMALL_DISPLAY									// 128x160 pixels
uint32_t Num_of_pixels_row = 128; 		// 128d
uint32_t Num_of_pixels_col = 160; 		// 160d
uint16_t LCD_Data[128];
#endif

#ifdef BIG_DISPLAY										 // 240x320 pixels
uint32_t Number_of_pixels_row = 240;  // 240d
uint32_t Number_of_pixels_col = 320; // 320d
uint16_t LCD_Data[240];
#endif


/* LCD initialize procedure */
void LCD_Init(void)
{
	LCD_Init_HW();
	LCD_Configure();
	HAL_Delay(1);
	Fill_display(RED);
}

/* Procedure to run LCD HW */
void LCD_Init_HW(void)
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
void LCD_Configure(void)
{
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
void Set_Address(uint8_t Start_X, uint8_t End_X, uint8_t Start_Y, uint8_t End_Y)
{
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

/* Prepare array that contains Num_of_pixels_row in unsigned short int data type (uint16_t) */
void LCD_Data_Preparation(uint16_t Color)
{
	uint8_t i;
	for(i=0; i<Num_of_pixels_row; i++)
	{
		LCD_Data[i] = Color;
	}
}

/* Color mode is set as 16 bit/pixel. Data have to be 16-bit. */
void Fill_display(uint16_t Color)
{
	Set_Address(0, Num_of_pixels_row, 0, Num_of_pixels_col);
	uint8_t i = 0;
	LCD_Data_Preparation(Color);
	for(i=0;i<Num_of_pixels_col;i++)
	{
		SPI_Send_Data_16bit(LCD_Data, Num_of_pixels_row);
	}
}

/* Function that can draw single specified pixel on specified color */
void Draw_Point(uint8_t X, uint8_t Y, uint16_t Color)
{
	Set_Address(X, X, Y, Y);
	SPI_Send_Data_16bit(&Color, 1);
}

/* Function is able to draw line in speciffic color */
void LCD_DrawLine(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color)
{		
	/* If line is too long don't draw it and return */
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
				
    if(2*Esp>=dy)
		{
			if(Xpoint==Xend)
			{
				break;
			}
			Esp += dy;
			Xpoint += XAddway;
		}
		if(2 * Esp <= dx) 
		{
			if(Ypoint == Yend)
			{
				break;
			}
			Esp += dx;
			Ypoint += YAddway;
		}
	}
}

/* Function that can draw rectangle */
void LCD_DrawRectangle(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color)
{
	LCD_DrawLine ( Xstart, Ystart, Xend, Ystart, Color);
	LCD_DrawLine ( Xstart, Ystart, Xstart, Yend, Color);
	LCD_DrawLine ( Xend, Yend, Xend, Ystart, Color);
	LCD_DrawLine ( Xend, Yend, Xstart, Yend, Color);		
}


/* Draw a circle from (0, R) as a starting point */
void LCD_DrawCircle(uint8_t X_Center, uint8_t Y_Center, uint8_t Radius, uint16_t Color)
{
	int16_t XCurrent, YCurrent;
	XCurrent = 0; 
	YCurrent = Radius;	
	
	//Cumulative error,judge the next point of the logo
	int16_t Esp = 3 - ( Radius << 1 );
	
	while ( XCurrent <= YCurrent )
	{
		Draw_Point(X_Center + XCurrent, Y_Center + YCurrent, Color);
		Draw_Point(X_Center - XCurrent, Y_Center + YCurrent, Color);
		Draw_Point(X_Center - YCurrent, Y_Center + XCurrent, Color);
		Draw_Point(X_Center - YCurrent, Y_Center - XCurrent, Color);
		Draw_Point(X_Center - XCurrent, Y_Center - YCurrent, Color);
		Draw_Point(X_Center + XCurrent, Y_Center - YCurrent, Color);
		Draw_Point(X_Center + YCurrent, Y_Center - XCurrent, Color);
		Draw_Point(X_Center + YCurrent, Y_Center + XCurrent, Color);
		
		if ( Esp < 0 )
		{
			Esp += 4 * XCurrent + 6;
		}
		else
		{
			Esp += 10 + 4 * ( XCurrent - YCurrent );
			YCurrent --;
		}
		XCurrent ++;
	}
}

/* Draw char in speciffic place */
void LCD_DisplayChar(uint8_t Xpoint, uint8_t Ypoint, const char Acsii_Char,	sFONT* Font, uint16_t Color_Background,	uint16_t Color_Foreground)
{
	uint8_t Page, Column;
	uint32_t Char_Offset = (Acsii_Char - ' ') * Font->Height * (Font->Width / 8 + (Font->Width % 8 ? 1 : 0));
	const unsigned char* ptr = &Font->table[Char_Offset];

	for(Page=0; Page<Font->Height; Page++)
	{
		for ( Column = 0; Column < Font->Width; Column ++ )
		{
			if (*ptr & (0x80 >> (Column % 8)))
			{
				Draw_Point(Xpoint+Column, Ypoint+Page, Color_Foreground);
			}
			else
			{
				Draw_Point(Xpoint+Column, Ypoint+Page, Color_Background);
			}
			//One pixel is 8 bits
      if (Column % 8 == 7)
			{
				ptr++;
			}	
		}
		/* Write a line */
		if(Font->Width % 8 != 0)
		{
			ptr++;
		}
	}
}

/* Can display all string */
void LCD_DisplayString (uint8_t Xstart, uint8_t Ystart, const char * pString, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground )
{
	uint8_t Xpoint = Xstart;
	uint8_t Ypoint = Ystart;
	
	while ( * pString != '\0')
	{
		LCD_DisplayChar ( Xpoint, Ypoint, * pString, Font, Color_Background, Color_Foreground );
		//The next character of the address
		pString ++;
		//The next word of the abscissa increases the font of the broadband
		Xpoint += Font->Width;
	}
}

/* Can display number */
void LCD_DisplayNum(uint8_t Xpoint, uint8_t  Ypoint, int32_t Nummber, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground)
{
	int16_t Num_Bit = 0, Str_Bit = 0;
	uint8_t Str_Array[ARRAY_LEN]={0} ,Num_Array[ARRAY_LEN]={0};
	uint8_t *pStr = Str_Array;
	
	//Converts a number to a string
	while(Nummber)
	{
		Num_Array[Num_Bit] = Nummber % 10 + '0';
		Num_Bit++;
		Nummber /= 10;
  }
	//The string is inverted
	while( Num_Bit > 0)
	{
		Str_Array[Str_Bit] = Num_Array[Num_Bit -1];
		Str_Bit ++;
		Num_Bit --;
	}
	//show
	LCD_DisplayString( Xpoint, Ypoint,  (const char*)pStr, Font, Color_Background, Color_Foreground );
}

void LCD_Features_Selftest(void)
{
	uint8_t i, j;
	for(i=0; i<4; i++)
	{
		Fill_display(RED);
		HAL_Delay(333);
		Fill_display(GREEN);
		HAL_Delay(333);
		Fill_display(BLUE);
		HAL_Delay(333);		
	}
	Fill_display(WHITE);
	
	uint8_t X=1, Y=1;
	for(i=0; i<79; i++)
	{
		for(j=0; j<63; j++)
		{
			Draw_Point(X, Y, BLACK);
			X = X + 2;
		}
		X = 1;
		Y = Y + 2;
	}
	
	Fill_display(WHITE);
	X=1;
	Y=1;
	
	for(i=0; i<39; i++)
	{
		LCD_DrawLine(X, Y, X+126, Y, BLACK);
		Y=Y+4;
		HAL_Delay(50);
	}
	
	Fill_display(WHITE);
	X=1;
	Y=1;
	
	for(i=0; i<39; i++)
	{
		LCD_DrawLine(X, Y, X, Y+158, BLACK);
		X=X+4;
		HAL_Delay(50);
	}
	
	Fill_display(WHITE);
	X=1;
	Y=1;
	
	LCD_DisplayChar(1, 1, 'A', &Font20, WHITE, BLACK);
	LCD_DisplayString(1, 30, "Test!!!", &Font20, WHITE, BLACK);
	LCD_DisplayNum(1, 60, 2019, &Font20, WHITE, BLACK);
	HAL_Delay(1000);
	LCD_DisplayChar(1, 1, 'A', &Font20, WHITE, WHITE);
	LCD_DisplayString(1, 30, "Test!!!", &Font20, WHITE, WHITE);
	LCD_DisplayNum(1, 60, 2019, &Font20, WHITE, WHITE);
	HAL_Delay(1000);
	LCD_DisplayChar(1, 1, 'A', &Font20, WHITE, BLACK);
	LCD_DisplayString(1, 30, "Test!!!", &Font20, WHITE, BLACK);
	LCD_DisplayNum(1, 60, 2019, &Font20, WHITE, BLACK);
	HAL_Delay(1000);
}

uint8_t Generate_Item_Index(uint8_t Item_Position)
{	
	uint8_t Y_Index = Item_Position * Font12.Height - Font12.Height;
	return Y_Index;
}

void Create_Header(const char* Header, uint8_t item)
{
	uint8_t Number_of_chars = (Num_of_pixels_row / Font12.Width)-7;	
	uint8_t Y_Index = Generate_Item_Index(item);
	
	if(strlen(Header) >= Number_of_chars)
	{
		char* String_p = malloc(Number_of_chars+4);
		String_p = memcpy(String_p, Header, Number_of_chars);
		String_p[Number_of_chars] = '.';
		String_p[Number_of_chars+1] = '.';
		String_p[Number_of_chars+2] = '.';
		String_p[Number_of_chars+3] = 0;
		LCD_DisplayString(0, Y_Index, String_p, &Font12, WHITE, BLACK);
	}else
	{
		LCD_DisplayString(0, Y_Index, Header, &Font12, WHITE, BLACK);
	}
}
	

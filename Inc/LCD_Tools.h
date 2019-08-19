#include "main.h"
#include "fonts.h"

#define SET 1
#define RES 0
#define DATA 0
#define COMMAND 1
#define ARRAY_LEN 255

#define PIXEL_ADDR_REG_1 0x2A
#define PIXEL_ADDR_REG_2 0x2B
#define PIXEL_ADDR_REG_3 0x2C

#define RED			0x001F
#define GREEN		0xF800
#define BLUE		0x07E0
#define WHITE		0xFFFF
#define BLACK		0

#define SMALL_DISPLAY

#ifdef SMALL_DISPLAY
#define X_PIXELS 128
#define Y_PIXELS 160
#endif

#ifdef BIG_DISPLAY
#define X_PIXELS 240
#define Y_PIXELS 320
#endif


struct LCD_Params
{
	uint16_t Number_of_pixels_X;
	uint16_t Number_of_pixels_Y;
	uint16_t Color;
};

struct Item_Params
{
	sFONT Used_Font;
	uint16_t Background_Color;
	uint16_t Font_Color;
};


void Set_LCD_Params(struct LCD_Params* Params_Set, uint16_t Color);
void Set_Item_Params(struct Item_Params* Item, sFONT Font, uint16_t Font_Color, uint16_t BG_Color);
void LCD_Init_HW(void);
void LCD_Configure(void);
void Set_Address (uint8_t Start_X, uint8_t End_X, uint8_t Start_Y, uint8_t End_Y);
void Fill_display(uint16_t Color);
void LCD_Init(void);
void Draw_Point(uint8_t X, uint8_t Y, uint16_t Color);
void LCD_DrawLine(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color);
void LCD_DrawRectangle(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color, char Fulfilled);
void LCD_DrawCircle(uint8_t X_Center, uint8_t Y_Center, uint8_t Radius, uint16_t Color);
void LCD_DisplayChar(uint8_t Xpoint, uint8_t Ypoint, const char Acsii_Char,	sFONT* Font, uint16_t Color_Background,	uint16_t Color_Foreground);
void LCD_DisplayString (uint8_t Xstart, uint8_t Ystart, const char * pString, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground );
void LCD_DisplayNum(uint8_t Xpoint, uint8_t  Ypoint, int32_t Nummber, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground );
void LCD_Features_Selftest(void);
void LCD_Create_Item(struct Item_Params Params_Set, const char* Text, uint8_t Item);



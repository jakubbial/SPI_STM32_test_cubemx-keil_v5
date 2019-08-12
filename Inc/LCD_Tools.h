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
#define GREEN		0x07E0
#define BLUE		0xF800
#define WHITE		0
#define BLACK		0xFFFF


void LCD_Init_HW(void);
void LCD_Configure(void);
void Set_Address (uint8_t Start_X, uint8_t End_X, uint8_t Start_Y, uint8_t End_Y);
void LCD_Data_Preparation(uint16_t Color);
void Fill_display(uint16_t Color);
void LCD_Init(void);
void Draw_Point(uint8_t X, uint8_t Y, uint16_t Color);
void LCD_DrawLine(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color);
void LCD_DrawRectangle(uint8_t Xstart, uint8_t Ystart, uint8_t Xend, uint8_t Yend, uint16_t Color);
void LCD_DrawCircle(uint8_t X_Center, uint8_t Y_Center, uint8_t Radius, uint16_t Color);
void LCD_DisplayChar(uint8_t Xpoint, uint8_t Ypoint, const char Acsii_Char,	sFONT* Font, uint16_t Color_Background,	uint16_t Color_Foreground);
void LCD_DisplayString (uint8_t Xstart, uint8_t Ystart, const char * pString, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground );
void LCD_DisplayNum(uint8_t Xpoint, uint8_t  Ypoint, int32_t Nummber, sFONT* Font, uint16_t Color_Background, uint16_t Color_Foreground );
void LCD_Features_Selftest(void);

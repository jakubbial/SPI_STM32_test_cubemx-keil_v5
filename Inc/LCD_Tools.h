#include "main.h"

#define SET 1
#define RES 0
#define DATA 0
#define COMMAND 1

#define PIXEL_ADDR_REG_1 0x2A
#define PIXEL_ADDR_REG_2 0x2B
#define PIXEL_ADDR_REG_3 0x2C




void LCD_Data_Preparation(uint16_t Color);
void Fill_display(uint16_t Color);
void LCD_Init_HW(void);
void LCD_Configure(void);
void LCD_Init(void);
void Set_Address (uint8_t Start_X, uint8_t End_X, uint8_t Start_Y, uint8_t End_Y);
void Draw_Point(uint8_t X, uint8_t Y, uint16_t Color);

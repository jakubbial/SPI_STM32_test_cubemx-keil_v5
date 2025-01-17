#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

#include <stdint.h>
#include "DEV_Config.h"
#include "../Fonts/fonts.h"

#define	COLOR				uint16_t		//The variable type of the color (unsigned short) 
#define	POINT				uint16_t		//The type of coordinate (unsigned short) 
#define	LENGTH				uint16_t		//The type of coordinate (unsigned short) 

/********************************************************************************
function:
		Define the full screen height length of the display
********************************************************************************/
//#define LCD_1IN44
#define LCD_1IN8
#if defined(LCD_1IN44)
#define LCD_WIDTH  128  //LCD width
#define LCD_HEIGHT  128 //LCD height
#define LCD_X	2
#define LCD_Y	1
#elif defined(LCD_1IN8)
#define LCD_WIDTH  160  //LCD width
#define LCD_HEIGHT  128 //LCD height
#define LCD_X	 2
#define LCD_Y	 1
#endif

#define LCD_X_MAXPIXEL  132  //LCD width maximum memory 
#define LCD_Y_MAXPIXEL  162 //LCD height maximum memory

//LCD
#define LCD_CS_0		DEV_Digital_Write(LCD_CS,0)
#define LCD_CS_1		DEV_Digital_Write(LCD_CS,1)

#define LCD_RST_0		DEV_Digital_Write(LCD_RST,0)
#define LCD_RST_1		DEV_Digital_Write(LCD_RST,1)

#define LCD_DC_0		DEV_Digital_Write(LCD_DC,0)
#define LCD_DC_1		DEV_Digital_Write(LCD_DC,1)

#define LCD_BL_0		DEV_Digital_Write(LCD_BL,0)
#define LCD_BL_1		DEV_Digital_Write(LCD_BL,1)

/********************************************************************************
function:
			scanning method
********************************************************************************/
typedef enum {
    L2R_U2D  = 0,	//The display interface is displayed , left to right, up to down
    L2R_D2U  ,
    R2L_U2D  ,
    R2L_D2U  ,

    U2D_L2R  ,
    U2D_R2L  ,
    D2U_L2R  ,
    D2U_R2L  ,
} LCD_SCAN_DIR;
#define SCAN_DIR_DFT  U2D_R2L  //Default scan direction = L2R_U2D

/********************************************************************************
function:
	Defines the total number of rows in the display area
********************************************************************************/

typedef struct {
    LENGTH LCD_Dis_Column;	//COLUMN
    LENGTH LCD_Dis_Page;	//PAGE
    LCD_SCAN_DIR LCD_Scan_Dir;
    POINT LCD_X_Adjust;		//LCD x actual display position calibration
    POINT LCD_Y_Adjust;		//LCD y actual display position calibration
} LCD_DIS;

/********************************************************************************
function:
			Macro definition variable name
********************************************************************************/
void LCD_Init( LCD_SCAN_DIR Lcd_ScanDir );
void LCD_SetGramScanWay(LCD_SCAN_DIR Scan_dir);

//LCD set cursor + windows + color
void LCD_SetWindows( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend );
void LCD_SetCursor ( POINT Xpoint, POINT Ypoint );
void LCD_SetColor( COLOR Color ,POINT Xpoint, POINT Ypoint);
void LCD_SetPointlColor ( POINT Xpoint, POINT Ypoint, COLOR Color );
void LCD_SetArealColor ( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend,COLOR  Color);
void LCD_Clear(COLOR  Color);

void LCD_DisplayWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD *Image);
void LCD_Display(UWORD *Image);

#endif

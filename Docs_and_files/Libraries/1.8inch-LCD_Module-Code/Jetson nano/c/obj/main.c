#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include <time.h>

#include "image.h"
#include "GUI_Paint.h"
#include "LCD_Driver.h"
#include "DEV_Config.h"


void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Program  End\r\n");
    DEV_ModuleExit();

    exit(0);
}


int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    if(DEV_ModuleInit())
        exit(0);

    printf("Jetson Nano Test program\r\n");
    printf("Longer refresh time\r\n");
    printf("Please wait for the screen\r\n");
	LCD_Init();
	LCD_Clear(0x0000);
	Paint_NewImage(LCD_WIDTH, LCD_HEIGHT,0,WHITE);
	Paint_Clear(WHITE);
	Paint_SetRotate(180);
	Paint_DrawString_EN(0, 0, "123", &Font24, 0x000f, 0xfff0);
	Paint_DrawString_EN(0, 23, "ABC", &Font24, BLUE, CYAN);
	Paint_DrawString_CN(20,42, "微雪电子",  &Font24CN, WHITE, RED);
	Paint_DrawRectangle(70, 10, 100, 40, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2 );
	Paint_DrawLine(70, 10, 100, 40, MAGENTA, LINE_STYLE_SOLID, DOT_PIXEL_2X2);
	Paint_DrawLine(100, 10, 70, 40, MAGENTA, LINE_STYLE_SOLID, DOT_PIXEL_2X2);
	Paint_DrawImage(gImage_40X40,110, 0,40, 40); 
	Paint_DrawImage(gImage_160X80,0, 60, 160, 80); 
    while(1){
        
    }
    //3.System Exit
    DEV_ModuleExit();
    return 0;

}


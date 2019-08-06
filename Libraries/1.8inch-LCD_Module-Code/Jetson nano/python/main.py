import config
import LCD_1in8
import time
import traceback
import RPi.GPIO as GPIO
from PIL import Image,ImageDraw,ImageFont

try:
    LCD = LCD_1in8.LCD()
    print("\r\nJetson Nano 1.8inch_LCD_Module Test program")
    print("Longer refresh time")
    print "**********Init LCD**********"
    Lcd_ScanDir = LCD_1in8.SCAN_DIR_DFT  #SCAN_DIR_DFT = D2U_L2R
    LCD.LCD_Init(Lcd_ScanDir)

    image = Image.new("RGB", (LCD.LCD_Dis_Column, LCD.LCD_Dis_Page), "WHITE")
    draw = ImageDraw.Draw(image)
    #font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeMonoBold.ttf', 16)

    print "***draw line"
    draw.line([(0,0),(159,0)], fill = "BLUE",width = 5)
    draw.line([(159,0),(159,127)], fill = "BLUE",width = 5)
    draw.line([(159,127),(0,127)], fill = "BLUE",width = 5)
    draw.line([(0,127),(0,0)], fill = "BLUE",width = 5)
    print "***draw rectangle"
    draw.rectangle([(18,10),(142,20)],fill = "RED")

    print "***draw text"
    draw.text((33, 22), 'WaveShare ', fill = "BLUE")
    draw.text((32, 36), 'Electronic ', fill = "BLUE")
    draw.text((28, 48), '1.8inch LCD ', fill = "BLUE")
    LCD.LCD_ShowImage(image,0,0)
    time.sleep(0.5)

    image = Image.open('time.bmp')
    LCD.LCD_ShowImage(image,0,0)
	

except KeyboardInterrupt, Exception:
    print '\r\ntraceback.format_exc():\n%s' % traceback.format_exc()
    config.module_exit()
    GPIO.cleanup()
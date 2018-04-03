#!/usr/bin

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
from io import StringIO
import TFT as GLCD
import time
#import os
import sys
import Adafruit_MCP3008
import RPi.GPIO as GPIO

#constants
CLK  = 5
MISO = 6
MOSI = 13
CS   = 12
mcp  = Adafruit_MCP3008.MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)
IR = 0
TEMP = 0
def main(argv):
    print("Testing")
    height = GLCD.TFT_HEIGHT
    width = GLCD.TFT_WIDTH
    disp = GLCD.TFT()   # create TFT LCD display class
    disp.initialize()   # initialize display
    disp.clear()        # Alternatively can clear to a black screen by calling
    draw = disp.draw()  # get a PIL Draw object to start drawing on the display buffer
    font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 14)   # use a truetype font
    font2 = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 14)

    disp.setRotation(5)
    disp.turnOn()
    disp.clear(color=(0,0,0))
    while True:
        TEMP = mcp.read_adc(0)
        IR = mcp.read_adc(1)
        disp.clear(color=(0,0,0))
        draw.text((20,60),"Temp: " + str(TEMP), font = font)
        draw.text((20,80),"IR:" + str(IR), font = font)

        disp.display()
        
        time.sleep(3)
        disp.clear()

if __name__=='__main__':
    try:
        main(sys.argv[1:])
    except KeyboardInterrupt:
        print("")

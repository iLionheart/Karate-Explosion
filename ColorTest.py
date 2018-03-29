#!/usr/bin/

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
from io import StringIO
import TFT as GLCD
import time
import Adafruit_MCP3008

CLK  = 5
MISO = 6
MOSI = 13
CS   = 12
mcp  = Adafruit_MCP3008.MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)


height = GLCD.TFT_HEIGHT
width = GLCD.TFT_WIDTH
disp = GLCD.TFT()
disp.initialize()
disp.clear()
disp.display()
draw = disp.draw()
##font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 14)
##big = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 50)
disp.setRotation(5)
disp.turnOn()
toggle = 0
IRN = mcp.read_adc(1)

while True:
    IR = mcp.read_adc(1)
    print("IR Value: {0}-{1}".format(IR,IRN))
    if(IR > IRN + 150):
        IRN = IR
        toggle = 1
    if(IR < IRN - 150):
        IRN = IR
        toggle = 0

    if(toggle == 0):
        disp.clear(color=(0,0,255))
        disp.display()
        disp.clear(0)
        toggle = 3
    if(toggle == 1):
        disp.clear(color=(255,0,0))
        disp.display()
        disp.clear(0)
        toggle = 3

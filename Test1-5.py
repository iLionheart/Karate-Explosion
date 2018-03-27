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
draw = disp.draw()
font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 14)
big = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 50)
disp.setRotation(5)
disp.turnOff()
disp.turnOn()
x = 1
while True:
    IR   = mcp.read_adc(1)
    
    if(IR > 150):
        disp.clear(color=(10,10,255))
        if(x == 0):
            i = 1
        x = 1
    else:
        disp.clear(color=(255,100,100))
        if(x == 1):
            i = 1
        x = 0

    if(i == 1):
        disp.display()
        i = 0
    time.sleep(.5)
    

    

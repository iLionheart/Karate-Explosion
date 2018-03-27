


from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import os
import sys
import json
import urllib
from io import StringIO
import time
import TFT as GLCD


print("First test of a code")

height = GLCD.TFT_HEIGHT
width = GLCD.TFT_WIDTH

disp = GLCD.TFT()
disp.initialize()
disp.clear()
draw = disp.draw()
disp.invert(True)

font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 14)
big = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeSansBold.ttf', 50)
disp.setRotation(5)

String = "Test Test"
STRING = str(String)
disp.clear(0)
draw.text((0,15),STRING[0:],font = font)
disp.display()
time.sleep(5)
disp.turnOff()
time.sleep(5)
disp.turnOn()
disp.clear(0)
for i in range(11):
    st = str(i)
    draw.text(((45+(i*2)),(60-(i*5))),st[0:], font = big)
    disp.display()
    time.sleep(1)
    disp.clear(0)
disp.clear(color = (255,0,255))
disp.display()
for i in range(11):
    st = str(i)
    draw.text(((45+(i*2)),(60-(i*5))),st[0:], font = big)
    disp.display()
    time.sleep(1)
    disp.clear(color = (255,0,255))

disp.clear(0)
x = 0
i = 0
b = 0
while i < 3:
    draw.text(((x-(b*75)),0),"Hello World",font = font)
    disp.display()
    if (x) >= (128+(b*75)):
        x = 0
        b = 1
        i += 1
    x += 2
    time.sleep(0.001)
    disp.clear(0)
disp.turnOff()

while True:
    disp.turnOn()
    disp.clear(0)
    y = 0
    i = 0
    b = 0
    while i < 3:
        draw.text((25,(y-(b*15))),"Hello World",font = font)
        disp.display()
        if (y) >= (160+(b*15)):
            y = 0
            b = 1
            i += 1
        y += 2
        time.sleep(0.001)
        disp.clear(0)
    disp.turnOff()


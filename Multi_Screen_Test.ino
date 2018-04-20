#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define ATFT_CS    10
#define TFT_RST    9
#define ATFT_DC    8
#define BTFT_CS    5
#define BTFT_DC    4

Adafruit_ST7735 tft1 = Adafruit_ST7735(ATFT_CS, ATFT_DC, TFT_RST);
Adafruit_ST7735 tft2 = Adafruit_ST7735(BTFT_CS, ATFT_DC, TFT_RST);


float p = 3.1415926;
void setup() {
  Serial.begin(9600);
  Serial.println("Multi ST7735 Screen Test");

  //Init the screens
  tft1.initR(INITR_BLACKTAB);
  tft2.initR(INITR_BLACKTAB);

  Serial.println("Initialized");
  uint16_t time = millis();
  tft1.fillScreen(ST7735_BLACK);
  time = millis()-time;
  Serial.println(time,DEC);
  delay(500);

}

void loop() {
  tft1.fillScreen(ST7735_BLACK);
  testdrawtext1("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
  delay(1000);

  // tft print function!
  tftPrintTest1();
  delay(4000);

  // a single pixel
  tft1.drawPixel(tft1.width()/2, tft1.height()/2, ST7735_GREEN);
  delay(500);

  // line draw test
  testlines1(ST7735_YELLOW);
  delay(500);

  // optimized lines
  testfastlines1(ST7735_RED, ST7735_BLUE);
  delay(500);

  testdrawrects1(ST7735_GREEN);
  delay(500);

  testfillrects1(ST7735_YELLOW, ST7735_MAGENTA);
  delay(500);

  tft1.fillScreen(ST7735_BLACK);
  testfillcircles1(10, ST7735_BLUE);
  testdrawcircles1(10, ST7735_WHITE);
  delay(500);

  testroundrects1();
  delay(500);

  testtriangles1();
  delay(500);

  mediabuttons1();
  delay(500);
  tft1.invertDisplay(true);
  delay(500);
  tft1.invertDisplay(false);
  delay(500);
  
  tft2.fillScreen(ST7735_BLACK);
  testdrawtext2("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
  delay(1000);

  // tft print function!
  tftPrintTest2();
  delay(4000);

  // a single pixel
  tft2.drawPixel(tft2.width()/2, tft2.height()/2, ST7735_GREEN);
  delay(500);

  // line draw test
  testlines2(ST7735_YELLOW);
  delay(500);

  // optimized lines
  testfastlines2(ST7735_RED, ST7735_BLUE);
  delay(500);

  testdrawrects2(ST7735_GREEN);
  delay(500);

  testfillrects2(ST7735_YELLOW, ST7735_MAGENTA);
  delay(500);

  tft2.fillScreen(ST7735_BLACK);
  testfillcircles2(10, ST7735_BLUE);
  testdrawcircles2(10, ST7735_WHITE);
  delay(500);

  testroundrects2();
  delay(500);

  testtriangles2();
  delay(500);

  mediabuttons2();
  delay(500);
  tft2.invertDisplay(true);
  delay(500);
  tft2.invertDisplay(false);
  delay(500);

}

void testlines1(uint16_t color) {
  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawLine(0, 0, x, tft1.height()-1, color);
  }
  for (int16_t y=0; y < tft1.height(); y+=6) {
    tft1.drawLine(0, 0, tft1.width()-1, y, color);
  }

  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawLine(tft1.width()-1, 0, x, tft1.height()-1, color);
  }
  for (int16_t y=0; y < tft1.height(); y+=6) {
    tft1.drawLine(tft1.width()-1, 0, 0, y, color);
  }

  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawLine(0, tft1.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft1.height(); y+=6) {
    tft1.drawLine(0, tft1.height()-1, tft1.width()-1, y, color);
  }

  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawLine(tft1.width()-1, tft1.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft1.height(); y+=6) {
    tft1.drawLine(tft1.width()-1, tft1.height()-1, 0, y, color);
  }
}

void testdrawtext1(char *text, uint16_t color) {
  tft1.setCursor(0, 0);
  tft1.setTextColor(color);
  tft1.setTextWrap(true);
  tft1.print(text);
}

void testfastlines1(uint16_t color1, uint16_t color2) {
  tft1.fillScreen(ST7735_BLACK);
  for (int16_t y=0; y < tft1.height(); y+=5) {
    tft1.drawFastHLine(0, y, tft1.width(), color1);
  }
  for (int16_t x=0; x < tft1.width(); x+=5) {
    tft1.drawFastVLine(x, 0, tft1.height(), color2);
  }
}

void testdrawrects1(uint16_t color) {
  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawRect(tft1.width()/2 -x/2, tft1.height()/2 -x/2 , x, x, color);
  }
}

void testfillrects1(uint16_t color1, uint16_t color2) {
  tft1.fillScreen(ST7735_BLACK);
  for (int16_t x=tft1.width()-1; x > 6; x-=6) {
    tft1.fillRect(tft1.width()/2 -x/2, tft1.height()/2 -x/2 , x, x, color1);
    tft1.drawRect(tft1.width()/2 -x/2, tft1.height()/2 -x/2 , x, x, color2);
  }
}

void testfillcircles1(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft1.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft1.height(); y+=radius*2) {
      tft1.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles1(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft1.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft1.height()+radius; y+=radius*2) {
      tft1.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles1() {
  tft1.fillScreen(ST7735_BLACK);
  int color = 0xF800;
  int t;
  int w = tft1.width()/2;
  int x = tft1.height()-1;
  int y = 0;
  int z = tft1.width();
  for(t = 0 ; t <= 15; t++) {
    tft1.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects1() {
  tft1.fillScreen(ST7735_BLACK);
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft1.width()-2;
    int h = tft1.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft1.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest1() {
  tft1.setTextWrap(false);
  tft1.fillScreen(ST7735_BLACK);
  tft1.setCursor(0, 30);
  tft1.setTextColor(ST7735_RED);
  tft1.setTextSize(1);
  tft1.println("Hello World!");
  tft1.setTextColor(ST7735_YELLOW);
  tft1.setTextSize(2);
  tft1.println("Hello World!");
  tft1.setTextColor(ST7735_GREEN);
  tft1.setTextSize(3);
  tft1.println("Hello World!");
  tft1.setTextColor(ST7735_BLUE);
  tft1.setTextSize(4);
  tft1.print(1234.567);
  delay(1500);
  tft1.setCursor(0, 0);
  tft1.fillScreen(ST7735_BLACK);
  tft1.setTextColor(ST7735_WHITE);
  tft1.setTextSize(0);
  tft1.println("Hello World!");
  tft1.setTextSize(1);
  tft1.setTextColor(ST7735_GREEN);
  tft1.print(p, 6);
  tft1.println(" Want pi?");
  tft1.println(" ");
  tft1.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft1.println(" Print HEX!");
  tft1.println(" ");
  tft1.setTextColor(ST7735_WHITE);
  tft1.println("Sketch has been");
  tft1.println("running for: ");
  tft1.setTextColor(ST7735_MAGENTA);
  tft1.print(millis() / 1000);
  tft1.setTextColor(ST7735_WHITE);
  tft1.print(" seconds.");
}

void mediabuttons1() {
  // play
  tft1.fillScreen(ST7735_BLACK);
  tft1.fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
  tft1.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
  delay(500);
  // pause
  tft1.fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);
  tft1.fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);
  tft1.fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);
  delay(500);
  // play color
  tft1.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
  delay(50);
  // pause color
  tft1.fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);
  tft1.fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);
  // play color
  tft1.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);
}

void testlines2(uint16_t color) {
  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft2.width(); x+=6) {
    tft2.drawLine(0, 0, x, tft2.height()-1, color);
  }
  for (int16_t y=0; y < tft2.height(); y+=6) {
    tft2.drawLine(0, 0, tft2.width()-1, y, color);
  }

  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft2.width(); x+=6) {
    tft2.drawLine(tft2.width()-1, 0, x, tft2.height()-1, color);
  }
  for (int16_t y=0; y < tft2.height(); y+=6) {
    tft2.drawLine(tft2.width()-1, 0, 0, y, color);
  }

  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft2.width(); x+=6) {
    tft2.drawLine(0, tft2.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft2.height(); y+=6) {
    tft2.drawLine(0, tft2.height()-1, tft2.width()-1, y, color);
  }

  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft2.width(); x+=6) {
    tft2.drawLine(tft2.width()-1, tft2.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft2.height(); y+=6) {
    tft2.drawLine(tft2.width()-1, tft2.height()-1, 0, y, color);
  }
}

void testdrawtext2(char *text, uint16_t color) {
  tft2.setCursor(0, 0);
  tft2.setTextColor(color);
  tft2.setTextWrap(true);
  tft2.print(text);
}

void testfastlines2(uint16_t color1, uint16_t color2) {
  tft2.fillScreen(ST7735_BLACK);
  for (int16_t y=0; y < tft2.height(); y+=5) {
    tft2.drawFastHLine(0, y, tft2.width(), color1);
  }
  for (int16_t x=0; x < tft2.width(); x+=5) {
    tft2.drawFastVLine(x, 0, tft2.height(), color2);
  }
}

void testdrawrects2(uint16_t color) {
  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft2.width(); x+=6) {
    tft2.drawRect(tft2.width()/2 -x/2, tft2.height()/2 -x/2 , x, x, color);
  }
}

void testfillrects2(uint16_t color1, uint16_t color2) {
  tft2.fillScreen(ST7735_BLACK);
  for (int16_t x=tft2.width()-1; x > 6; x-=6) {
    tft2.fillRect(tft2.width()/2 -x/2, tft2.height()/2 -x/2 , x, x, color1);
    tft2.drawRect(tft2.width()/2 -x/2, tft2.height()/2 -x/2 , x, x, color2);
  }
}

void testfillcircles2(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft2.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft2.height(); y+=radius*2) {
      tft2.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles2(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft2.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft2.height()+radius; y+=radius*2) {
      tft2.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles2() {
  tft2.fillScreen(ST7735_BLACK);
  int color = 0xF800;
  int t;
  int w = tft2.width()/2;
  int x = tft2.height()-1;
  int y = 0;
  int z = tft2.width();
  for(t = 0 ; t <= 15; t++) {
    tft2.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects2() {
  tft2.fillScreen(ST7735_BLACK);
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft2.width()-2;
    int h = tft2.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft2.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest2() {
  tft2.setTextWrap(false);
  tft2.fillScreen(ST7735_BLACK);
  tft2.setCursor(0, 30);
  tft2.setTextColor(ST7735_RED);
  tft2.setTextSize(1);
  tft2.println("Hello World!");
  tft2.setTextColor(ST7735_YELLOW);
  tft2.setTextSize(2);
  tft2.println("Hello World!");
  tft2.setTextColor(ST7735_GREEN);
  tft2.setTextSize(3);
  tft2.println("Hello World!");
  tft2.setTextColor(ST7735_BLUE);
  tft2.setTextSize(4);
  tft2.print(1234.567);
  delay(1500);
  tft2.setCursor(0, 0);
  tft2.fillScreen(ST7735_BLACK);
  tft2.setTextColor(ST7735_WHITE);
  tft2.setTextSize(0);
  tft2.println("Hello World!");
  tft2.setTextSize(1);
  tft2.setTextColor(ST7735_GREEN);
  tft2.print(p, 6);
  tft2.println(" Want pi?");
  tft2.println(" ");
  tft2.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft2.println(" Print HEX!");
  tft2.println(" ");
  tft2.setTextColor(ST7735_WHITE);
  tft2.println("Sketch has been");
  tft2.println("running for: ");
  tft2.setTextColor(ST7735_MAGENTA);
  tft2.print(millis() / 1000);
  tft2.setTextColor(ST7735_WHITE);
  tft2.print(" seconds.");
}

void mediabuttons2() {
  // play
  tft2.fillScreen(ST7735_BLACK);
  tft2.fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
  tft2.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
  delay(500);
  // pause
  tft2.fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);
  tft2.fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);
  tft2.fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);
  delay(500);
  // play color
  tft2.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
  delay(50);
  // pause color
  tft2.fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);
  tft2.fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);
  // play color
  tft2.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);
}

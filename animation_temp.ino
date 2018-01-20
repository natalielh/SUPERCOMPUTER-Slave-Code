
/*
Basic Setup 1 - runs faster, but uses more memory
*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
*/

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//// GLOBAL VARIABLES
const int framesPerSecond = 3;
int petStatus = 0; // 0=HAPPY, 1=SAD
////


////////// HERE ARE WHERE THE INSTRUCTIONS FOR ANIMATION FRAMES GO
//NOTE: screen dimensions: 128x64
//NOTE: use the u8g2 library to write instructions for drawing images (for example using the shape and line functions)
//NOTE: only add your desired drawing functions, buffering/clearing/timing is handled for you :)
// https://github.com/olikraus/u8g2/wiki/u8g2reference#drawbox
//
void happyFrame1(void) {  //THE FIRST FRAME OF THE 'HAPPY' ANIMATION
  u8g2.drawStr(0,15,":D frame 1");
  u8g2.drawEllipse(64, 40, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 42, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 44, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 46, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 48, 15, 10, U8G2_DRAW_ALL);
}
void happyFrame2(void) {  //THE SECOND FRAME OF THE 'HAPPY' ANIMATION
  u8g2.drawStr(0,15,":D frame 2");
  u8g2.drawEllipse(64, 39, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 41, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 43, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 45, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 47, 15, 11, U8G2_DRAW_ALL);
}
void happyFrame3(void) {  //THE THIRD FRAME OF THE 'HAPPY' ANIMATION
  u8g2.drawStr(0,15,":D frame 3");
  u8g2.drawEllipse(64, 38, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 40, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 42, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 44, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 46, 15, 12, U8G2_DRAW_ALL);
}

void sadFrame1(void) {  //THE FIRST FRAME OF THE 'SAD' ANIMATION
  u8g2.drawStr(0,15,":( frame 1");
  u8g2.drawEllipse(64, 40, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 42, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 44, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 46, 15, 10, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 48, 15, 10, U8G2_DRAW_ALL);
}
void sadFrame2(void) {  //THE SECOND FRAME OF THE 'SAD' ANIMATION
  u8g2.drawStr(0,15,":( frame 2");
  u8g2.drawEllipse(64, 39, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 41, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 43, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 45, 15, 11, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 47, 15, 11, U8G2_DRAW_ALL);
}
void sadFrame3(void) {  //THE THIRD FRAME OF THE 'SAD' ANIMATION
  u8g2.drawStr(0,15,":( frame 3");
  u8g2.drawEllipse(64, 38, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 40, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 42, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 44, 15, 12, U8G2_DRAW_ALL);
  u8g2.drawEllipse(64, 46, 15, 12, U8G2_DRAW_ALL);
}
//////////END OF ANIMATION FRAME INSTRUCTIONS

void setup(void) {
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB14_tr);
}

void loop(void) {
  animateScreen();
}

//// YOU DO NOT HAVE TO MODIFY THE REST OF THE CODE:
void animateScreen() {
  // the pet's status is checked every time animateScreen() is called
  if (petStatus == 0) { //IF PET IS HAPPY, DO THIS CODE:
    u8g2.clearBuffer();
    happyFrame1();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    happyFrame2();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    happyFrame3();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    happyFrame2();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);
  }  
  else { //IF PET IS NOT HAPPY, IT'S SAD. DO THIS CODE:
    u8g2.clearBuffer();
    sadFrame1();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    sadFrame2();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    sadFrame3();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);

    u8g2.clearBuffer();
    sadFrame2();
    u8g2.sendBuffer();
    delay(1000/framesPerSecond);
}
  }


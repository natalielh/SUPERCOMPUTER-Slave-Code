#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include <SoftwareSerial.h>

int incoming;

SoftwareSerial mySerial(8, 9); // RX, TX

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  
  pinMode(13, OUTPUT); 
  
  // pins for oled
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  u8g2.begin(4, 5, 6);
  
  mySerial.begin(4800);
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // OLED clear buffer
  u8g2.clearBuffer(); // clear the internal memory
  
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    incoming = mySerial.read();
    //mySerial.println(incoming);
    Serial.println(mySerial.read());

    if (incoming > 1) {
      digitalWrite(13, HIGH);
      drawSnowman(0, 50);
    } 

    if (incoming == 0) {
      digitalWrite(13, LOW);
    }
  }
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
}

void drawSnowman(int x, int y) {
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawGlyph(x, y, 0x2603);  /* dec 9731/hex 2603 Snowman */
}

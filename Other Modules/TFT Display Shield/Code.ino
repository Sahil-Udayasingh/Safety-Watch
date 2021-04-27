/*
Code to check if the display is working is not
*/
#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"

#define BLUE 0x111F //RBG for different colors
#define RED  0xF400 

#define CS  17 // LCD_CS A3    - Chip Select goes to Digital 17
#define RS  16 // LCD_CD A2    - Command/Data goes to Digital 16
#define WR  15 // LCD_WR A1    - LCD Write goes to Digital 15
#define RD  14 // LCD_RD A0    - LCD Read goes to Analog 18
#define RST 18 // LCD_RESET A4 - Can alternately just connect to Arduino's reset pin

MCUFRIEND_kbv tftDisplay(CS, RS, WR, RD, RST);

void setup() {  
  Serial.begin(9600);
  Serial.println("TFT BLINK");
  Serial.println("=========");
  uint16_t ID = tftDisplay.readID();
  Serial.print("Display ID: 0x");
  Serial.println(ID, HEX);
  tftDisplay.begin(ID);
  Serial.print("Width: ");
  Serial.println(tftDisplay.width(), DEC);
  Serial.print("Height: ");
  Serial.println(tftDisplay.height(), DEC); 
}

void loop() {  
  delay(1000);   
  tftDisplay.fillScreen(RED);
  delay(1000);   
  tftDisplay.fillScreen(BLUE);

}

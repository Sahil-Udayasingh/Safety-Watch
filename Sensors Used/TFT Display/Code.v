/*
  Blink TFT

  Muestra una pantalla roja durante 1 segundo y despues una pantalla azul durante un segundo

  Conexion paralelo 8-bit con display TFT con la libreria MCUFRIEND

  This example code is in the public domain.

*/

// nucleo de la libreria grafica para displays de Adafruit
#include "Adafruit_GFX.h"
// Soporte de los controladores de display para shields Arduino MCUFRIEND
#include "MCUFRIEND_kbv.h"

#define BLUE 0x111F
#define RED  0xF400

// Pinout para ARDUINO UNO
#define CS  17 // LCD_CS A3    - Chip Select goes to Digital 17
#define RS  16 // LCD_CD A2    - Command/Data goes to Digital 16
#define WR  15 // LCD_WR A1    - LCD Write goes to Digital 15
#define RD  14 // LCD_RD A0    - LCD Read goes to Analog 18
#define RST 18 // LCD_RESET A4 - Can alternately just connect to Arduino's reset pin

// Creacion del tft display
MCUFRIEND_kbv tftDisplay(CS, RS, WR, RD, RST);

void setup() {  
  Serial.begin(9600);
  Serial.println("TFT BLINK");
  Serial.println("=========");
  // Intento de lectura del ID del display
  uint16_t ID = tftDisplay.readID();
  Serial.print("Display ID: 0x");
  Serial.println(ID, HEX);
  // Inicio del display
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

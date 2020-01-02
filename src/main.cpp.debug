#include <Arduino.h>
#include "FastLED.h"
#include "timer-api.h"

#define NUM_LEDS 30
#define PIN 13
#define basicSATURATION 255
#define basicLIGHTNES 255

CRGB leds[NUM_LEDS];
//CHSV hsvLed;

byte counter;
volatile byte currentSATURATION = basicSATURATION;
volatile byte currentLIGHTNESS = basicLIGHTNES;

long randNum;
String RGBcolorString;
//String HSVcolorString;


void setup() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(50);
  pinMode(PIN, OUTPUT);

  Serial.begin(9600);
  while (!Serial){;}
  Serial.println("Serial port initialised\n------------------------");

  // timer_init_ISR_1KHz(TIMER_DEFAULT);

  for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    leds[i] = CHSV(i * (255/NUM_LEDS), currentSATURATION, currentLIGHTNESS /** randNum*/);  // HSV. Увеличивать HUE (цвет)

    RGBcolorString = "rgb(";
    RGBcolorString.concat(leds[i].r); RGBcolorString.concat(","); 
    RGBcolorString.concat(leds[i].g); RGBcolorString.concat(","); 
    RGBcolorString.concat(leds[i].b); RGBcolorString.concat(")");
    

    Serial.print(i); Serial.print(".\t" + RGBcolorString); 
    Serial.print("\t<tr><td style=\"background-color: " + RGBcolorString); 
    Serial.print(";\">&nbsp;&nbsp;&nbsp;"+ RGBcolorString); Serial.println("&nbsp;&nbsp;&nbsp;</td></tr>");
/*
    hsvLed = CRGB(leds[i].r,leds[i].g,leds[i].b);
    HSVcolorString = "hsv(";
    HSVcolorString.concat(hsvLed.h); HSVcolorString.concat(","); 
    HSVcolorString.concat((byte)(hsvLed.s/255)*100.0); HSVcolorString.concat("%,"); 
    HSVcolorString.concat((byte)(hsvLed.v/255)*100); HSVcolorString.concat("%)");

    Serial.print("<td style=\"background-color: " + HSVcolorString); 
    Serial.print(";\">&nbsp;&nbsp;&nbsp;"+ HSVcolorString); Serial.println("&nbsp;&nbsp;&nbsp;</td></tr>");
*/

    // currentSATURATION = basicSATURATION;
    // currentLIGHTNESS = basicLIGHTNES;
  }

  Serial.println("done");

}

void loop() {}

void timer_handle_interrupts(int timer) {
  if (timer == TIMER_DEFAULT) {  
    if ((int)random(25) == 1) {
      int ledPosition = (int)random(NUM_LEDS+1);
      leds[ledPosition] = CHSV(0, 0, 255);
    }
  }
}
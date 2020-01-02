#include <Arduino.h>
#include "FastLED.h"
#include "timer-api.h"

#define NUM_LEDS 30
#define PIN 13
#define basicSATURATION 255
#define basicLIGHTNES 127

CRGB leds[NUM_LEDS];
byte counter;
volatile byte currentSATURATION = basicSATURATION;
volatile byte currentLIGHTNESS = basicLIGHTNES;

long randNum;

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

    Serial.print(i); Serial.print(".\t RGB = ("); 
      Serial.print(leds[i].r); Serial.print(", ");
      Serial.print(leds[i].g); Serial.print(", ");
      Serial.print(leds[i].b); Serial.println(")");

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
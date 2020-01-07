#include <Arduino.h>
#include "FastLED.h"
#include "timer-api.h"

#define NUM_LEDS 30
#define PIN 13
#define basicSATURATION 255
#define basicLIGHTNES 127
#define RANDOM_DEVIDER 10

CRGB leds[NUM_LEDS];
byte counter;
volatile int flashLedPosition = -1;

long randNum;

void setup() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(50);
  pinMode(PIN, OUTPUT);

  // Serial.begin(9600);
  // while (!Serial){;}

  timer_init_ISR_10Hz(TIMER_DEFAULT);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    leds[i] = CHSV(counter + i * (255/NUM_LEDS), basicSATURATION, basicLIGHTNES);  // HSV. Увеличивать HUE (цвет)
  }

  counter++;        // counter меняется от 0 до 255 (тип данных byte)

  if (flashLedPosition >= 0 ){
    // Serial.println(flashLedPosition);
    leds[(byte)flashLedPosition] =  0xffffff;// CRGB(255, 255, 255);
    flashLedPosition = -1;
  }

  FastLED.show();
  delay(30);         // скорость движения радуги
}

void timer_handle_interrupts(int timer) {
  if (timer == TIMER_DEFAULT) {  
    if ((int)random(RANDOM_DEVIDER) == 1) {
      
      flashLedPosition = (int)random(NUM_LEDS+1);
      
      // Serial.println(flashLedPosition);
      // int ledPosition = (int)random(NUM_LEDS+1);
      // leds[ledPosition] = 0xFFFFFF;
    }
  }
}
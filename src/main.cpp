#include <Arduino.h>
#include "FastLED.h"

#define NUM_LEDS 30
#define PIN 2

CRGB leds[NUM_LEDS];
byte counter = 0;

void setup() {
  FastLED.addLeds<WS2811, PIN, RGB>(leds, NUM_LEDS);
  // FastLED.setBrightness(10);
  pinMode(PIN, OUTPUT);

  // FastLED.clearData();
}

void loop() {
 
 /*
  for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    leds[i] = CHSV(counter + i * 2, 255, 255);  // HSV. Увеличивать HUE (цвет)
    // умножение i уменьшает шаг радуги
  }
*/
 // counter++;        // counter меняется от 0 до 255 (тип данных byte)
  // leds[counter] = CHSV(counter * 10, 127, 127);

  leds[counter] = CRGB::Blue;
  FastLED.show();
  counter++;

  delay(1000);         // скорость движения радуги
}
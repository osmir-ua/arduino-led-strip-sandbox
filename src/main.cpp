#include <Arduino.h>
#include "FastLED.h"
#include "timer-api.h"

#define NUM_LEDS 30
#define PIN 13

CRGB leds[NUM_LEDS];
byte counter;

long randNum;

void setup() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(50);
  pinMode(PIN, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    //randNum = random(85,101);
  //  Serial.println(randNum);

    leds[i] = CHSV(counter + i * (255/NUM_LEDS), 255, 127 /** randNum*/);  // HSV. Увеличивать HUE (цвет)
    // умножение i уменьшает шаг радуги
  }

  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  delay(30);         // скорость движения радуги
}
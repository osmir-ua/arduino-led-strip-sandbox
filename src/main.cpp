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
  //Serial.begin(9600);
  timer_init_ISR_10KHz(TIMER_DEFAULT);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++ ) {         // от 0 до первой трети
    //randNum = random(85,101);
  //  Serial.println(randNum);

    leds[i] = CHSV(counter + i * (255/NUM_LEDS), currentSATURATION, currentLIGHTNESS /** randNum*/);  // HSV. Увеличивать HUE (цвет)
    currentSATURATION = basicSATURATION;
    currentLIGHTNESS = basicLIGHTNES;
  }

  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  delay(30);         // скорость движения радуги
}

void timer_handle_interrupts(int timer) {
  if (timer = TIMER_DEFAULT) {  
    if (random(5) = 1) {
      int ledPosition = (int)random(NUM_LEDS+1);
      leds[ledPosition].sat = 0;
      leds[ledPosition].val = 255;
    }
  }
}
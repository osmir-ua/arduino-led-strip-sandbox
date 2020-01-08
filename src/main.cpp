#include <Arduino.h>
#include "FastLED.h"
#include "timer-api.h"

#define NUM_LEDS 30
#define PIN 13
#define basicSATURATION 255
#define basicLIGHTNES 127
#define RANDOM_DEVIDER 10
#define SPEED 30

CRGB leds[NUM_LEDS];
byte counter = 0;
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
  for (int i = 0; i < NUM_LEDS; i++ ) {        
    leds[i] = CHSV(counter + i * (255/NUM_LEDS), basicSATURATION, basicLIGHTNES);  
  }

  counter++;  // от 0 до 255

  if (flashLedPosition >= 0 ){
    // Serial.println(flashLedPosition);
    leds[(byte)flashLedPosition] =  0xffffff;
    flashLedPosition = -1;
  }

  FastLED.show();
  delay(SPEED);       
}

void timer_handle_interrupts(int timer) {
  if (timer == TIMER_DEFAULT) {  
    if ((int)random(RANDOM_DEVIDER) == 1) flashLedPosition = (int)random(NUM_LEDS+1);
  }
}
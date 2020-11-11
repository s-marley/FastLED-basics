#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];
uint8_t patternCounter = 0;
bool isRunning = false;

void checkTimer();

#include "Fire2012.h"
#include "Pacifica.h"
#include "Pride2015.h"

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(57600);
}

void loop() {
  
  switch (patternCounter) {
    case 0:
      runFire2012();
      break;
    case 1:
      runPacifica();
      break;
    case 2:
      runPride2015();
      break;
  }
}

void checkTimer() {
  EVERY_N_SECONDS(50) {
    nextPattern();
  }
}

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 3;
}

void runFire2012(){
  isRunning = true;
  Fire2012 fire2012 = Fire2012();
  while(isRunning) fire2012.runPattern();
}

void runPacifica(){
  isRunning = true;
  Pacifica pacifica = Pacifica();
  while(isRunning) pacifica.runPattern();
}

void runPride2015(){
  isRunning = true;
  Pride2015 pride2015 = Pride2015();
  while(isRunning) pride2015.runPattern();
}

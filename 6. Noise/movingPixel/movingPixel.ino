#include <FastLED.h>

#define NUM_LEDS 18
#define LED_PIN 2

CRGB leds[NUM_LEDS];
CRGB background[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  Serial.begin(57600);
}

void loop() {

  drawBackground();
  drawMovingPixel();

  EVERY_N_MILLISECONDS(20) {
    fadeToBlackBy(leds, NUM_LEDS, 10); 
    nblend(leds, background, NUM_LEDS, 30);
  } 
  
  FastLED.show();
}

void drawBackground() {
  // A simple plasma effect
  fill_noise16 (background, NUM_LEDS, 1, millis(), 30, 1, 0, 50, millis() / 3, 10);
}

void drawMovingPixel() {
  // A pixel that moves back and forth using noise
  uint16_t pos = inoise16(millis() * 100);
  pos = constrain(pos, 13000, 51000);
  pos = map(pos, 13000, 51000, 0, NUM_LEDS - 1);
  leds[pos] = CRGB::Red;
}

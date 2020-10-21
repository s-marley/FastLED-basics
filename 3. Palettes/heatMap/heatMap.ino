#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE (heatmap_gp) {
    0,   0,   0,   0,   //black
  128, 255,   0,   0,   //red
  200, 255, 255,   0,   //bright yellow
  255, 255, 255, 255    //full white 
};

CRGBPalette16 myPal = heatmap_gp;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
  
  EVERY_N_MILLISECONDS(10){
    paletteIndex++;
  }
  
  FastLED.show();
}

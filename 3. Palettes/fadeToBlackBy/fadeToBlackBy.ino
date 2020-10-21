#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

CRGBPalette16 purplePalette = CRGBPalette16 (
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::Linen,
    CRGB::Linen,
    
    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::Linen,
    CRGB::Linen
);


CRGBPalette16 myPal = purplePalette;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  
  EVERY_N_MILLISECONDS(50){
    //Switch on an LED at random, choosing a random color from the palette
    leds[random8(0, NUM_LEDS - 1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
  }

   // Fade all LEDs down by 1 in brightness each time this is called
   fadeToBlackBy(leds, NUM_LEDS, 1);
  
  FastLED.show();
}

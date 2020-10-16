#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(200);
  
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(200);
  
}

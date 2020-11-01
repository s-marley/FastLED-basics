#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  resetStrip();
}

void loop() {

  EVERY_N_SECONDS(2) {
    for (int i = 0; i < 4; i++) {
      blur1d(leds, NUM_LEDS, 150);
    }
  }

  EVERY_N_SECONDS(4) {
    resetStrip();
  }

  FastLED.show();
}

void resetStrip() {
  // Fill strip with R, G and B stripes
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  fill_solid(leds, (NUM_LEDS / 3) * 2, CRGB::Green);
  fill_solid(leds, (NUM_LEDS / 3), CRGB::Blue);
}

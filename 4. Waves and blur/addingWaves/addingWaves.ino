#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {

  // Waves for LED position
  uint8_t posBeat  = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
  uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);

  uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
  uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 10);

  FastLED.show();
}

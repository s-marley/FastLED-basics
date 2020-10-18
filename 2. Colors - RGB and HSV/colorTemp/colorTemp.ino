#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

uint8_t tempIndex = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  fill_solid(leds, NUM_LEDS, CRGB::White);

  EVERY_N_SECONDS(1) {
    tempIndex++;
    if (tempIndex > 8) tempIndex = 0;
  }

  switch (tempIndex) {
    case 0:
      FastLED.setTemperature(Candle);
      break;
    case 1:
      FastLED.setTemperature(Tungsten40W);
    break;
    case 2:
      FastLED.setTemperature(Tungsten100W);
    break;
    case 3:
      FastLED.setTemperature(Halogen);
    break;
    case 4:
      FastLED.setTemperature(CarbonArc);
    break;
    case 5:
      FastLED.setTemperature(HighNoonSun);
    break;
    case 6:
      FastLED.setTemperature(DirectSunlight);
    break;
    case 7:
      FastLED.setTemperature(OvercastSky);
    break;
    case 8:
      FastLED.setTemperature(ClearBlueSky);
    break;
  }

  FastLED.show();
  
}

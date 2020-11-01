#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.begin(57600);
}

void loop() {

  uint8_t sinBeat   = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
  uint8_t sinBeat2  = beatsin8(30, 0, NUM_LEDS - 1, 0, 85);
  uint8_t sinBeat3  = beatsin8(30, 0, NUM_LEDS - 1, 0, 170);

  leds[sinBeat]   = CRGB::Green;
  leds[sinBeat2]  = CRGB::Blue;
  leds[sinBeat3]  = CRGB::Red;

  EVERY_N_MILLISECONDS(1){
    for(int i = 0; i < 4; i++) {
      blur1d(leds, NUM_LEDS, 50);
    }
  }
  
  //fadeToBlackBy(leds, NUM_LEDS, 10);

  FastLED.show();
}

#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

uint8_t hue = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.begin(57600);
}

void loop() {

  uint8_t pos = map(beat16(40, 0), 0, 65535, 0, NUM_LEDS -1);
  leds[pos] = CHSV( hue, 200, 255);

  fadeToBlackBy(leds, NUM_LEDS, 3);

  EVERY_N_MILLISECONDS( 10 ) {
    hue++;
  }

  EVERY_N_MILLISECONDS(10) {
    Serial.println(pos);
  }
  
  FastLED.show();

}

#include <FastLED.h>

#define NUM_LEDS 18
#define LED_PIN 2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(57600);
}


void loop() {

  uint16_t  x        = 0;
  int       scale    = 10;
  uint16_t  t        = 0;
  
  for (int i = 0; i < NUM_LEDS; i++) {
      uint8_t hue = inoise8(i * scale + x, t);
      leds[i] = CHSV(hue, 255, 255);
  }
  
  FastLED.show();
}

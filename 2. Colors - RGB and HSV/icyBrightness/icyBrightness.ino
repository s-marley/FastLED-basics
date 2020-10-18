#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2
#define POT_PIN   A1

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {

  // Read the potentiometer and set brightness
  uint16_t potRead = analogRead(POT_PIN);
  uint8_t brightness = map(potRead, 0, 1023, 0, 200);
  FastLED.setBrightness(brightness);

  // Create a new HSV color for led[0]
  leds[0] = CHSV(160, random8(), random8(100,255));
  
  EVERY_N_MILLISECONDS(30) {
    // Copy each pixel to the next one, starting at the far end
    // thereby 'moving' the pattern along the strip
    for (int i = NUM_LEDS - 1; i > 0; i--) {
      leds[i] = leds[i - 1];
    }
  
  }
  
  FastLED.show();
}

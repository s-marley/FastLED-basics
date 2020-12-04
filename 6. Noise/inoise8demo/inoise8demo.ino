#include <FastLED.h>

#define NUM_LEDS 18
#define LED_PIN 2

CRGB leds[NUM_LEDS];

uint16_t  x;
int       scale;
uint16_t  t;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(57600);
}


void loop() {

  x = 0;
  t = millis() / 5;
  scale = beatsin8(10, 10, 30);
  
  for (int i = 0; i < NUM_LEDS; i++) {
      uint8_t noise = inoise8(i * scale + x, t);
      uint8_t hue = map(noise, 50, 190, 0, 255);
      leds[i] = CHSV(hue, 255, 255);
  }
  
  FastLED.show();
}

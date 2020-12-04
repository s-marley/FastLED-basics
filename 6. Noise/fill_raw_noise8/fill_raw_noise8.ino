#include <FastLED.h>

#define NUM_LEDS 18
#define LED_PIN 2

CRGB      leds[NUM_LEDS];
uint8_t   noiseData[NUM_LEDS];

CRGBPalette16 party = PartyColors_p;

uint8_t   octaveVal   = 2;
uint16_t  xVal        = 0;
int       scaleVal    = 50;
uint16_t  timeVal     = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(115200);
}


void loop() {

  timeVal = millis() / 4;

  memset(noiseData, 0, NUM_LEDS);
  fill_raw_noise8(noiseData, NUM_LEDS, octaveVal, xVal, scaleVal, timeVal);
  
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = ColorFromPalette(party, noiseData[i], noiseData[NUM_LEDS - i - 1]);
  }
  
  FastLED.show();
}

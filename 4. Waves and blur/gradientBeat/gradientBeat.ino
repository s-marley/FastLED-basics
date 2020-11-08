#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

DEFINE_GRADIENT_PALETTE( browngreen_gp ) { 
    0,    6,  255,    0,     //green
   71,    0,  255,  153,     //bluegreen
  122,  200,  200,  200,     //gray
  181,  110,   61,    6,     //brown
  255,    6,  255,    0      //green
};

CRGB leds[NUM_LEDS];
CRGBPalette16 orangePink = browngreen_gp;

void setup() {
  
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.begin(57600);

  FastLED.clear(true);
}

void loop () {

    uint16_t beatA = beatsin16(30, 0, 255);
    uint16_t beatB = beatsin16(20, 0, 255);
    fill_palette(leds, NUM_LEDS, (beatA + beatB) / 2, 10, orangePink, 255, LINEARBLEND);

    FastLED.show();
}

#include "Arduino.h"

class RedWhiteBlue {
  public:
    RedWhiteBlue(){};
    void runPattern();
  private:
};

void RedWhiteBlue::runPattern() {

  uint16_t sinBeat   = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  uint16_t sinBeat2  = beatsin16(30, 0, NUM_LEDS - 1, 0, 21845);
  uint16_t sinBeat3  = beatsin16(30, 0, NUM_LEDS - 1, 0, 43690);

  leds[sinBeat]   = CRGB::Blue;
  leds[sinBeat2]  = CRGB::Red;
  leds[sinBeat3]  = CRGB::White;
  
  fadeToBlackBy(leds, NUM_LEDS, 10);

  btn.tick();
  FastLED.show();
}

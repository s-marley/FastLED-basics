#include "Arduino.h"

class RainbowBeat {
  public:
    RainbowBeat(){};
    void runPattern();
  private:
};

void RainbowBeat::runPattern() {
  
  uint16_t beatA = beatsin16(30, 0, 255);
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_rainbow(leds, NUM_LEDS, (beatA+beatB)/2, 8);

  btn.tick();
  FastLED.show();
}

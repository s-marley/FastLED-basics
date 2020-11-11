#include "Arduino.h"

class MovingDot {
  public:
    MovingDot(){
      // Blank constructor  
    };
    void runPattern();
  private:
};

void MovingDot::runPattern() {

  uint16_t posBeat  = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  uint16_t posBeat2 = beatsin16(60, 0, NUM_LEDS - 1, 0, 0);

  uint16_t posBeat3 = beatsin16(30, 0, NUM_LEDS - 1, 0, 32767);
  uint16_t posBeat4 = beatsin16(60, 0, NUM_LEDS - 1, 0, 32767);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 10);

  btn.tick();
  FastLED.show();
}

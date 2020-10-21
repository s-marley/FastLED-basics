#include <FastLED.h>

#define NUM_LEDS  18
#define LED_PIN   2

CRGB leds[NUM_LEDS];

uint8_t colorIndex[NUM_LEDS];
uint8_t whichPalette = 0;

DEFINE_GRADIENT_PALETTE( greenblue_gp ) { 
    0,    0,  194,  255,     //light blue
   46,    3,    0,  246,     //dark blue
  176,   55,  222,   70,     //bright green
  255,    0,  194,  255      //light blue
};

DEFINE_GRADIENT_PALETTE( orangepink_gp ) { 
    0,  255,  100,    0,     //orange
   90,  255,    0,  255,     //magenta
  150,  255,  100,    0,     //orange
  255,  255,  100,    0      //orange
};

DEFINE_GRADIENT_PALETTE( browngreen_gp ) { 
    0,    6,  255,    0,     //green
   71,    0,  255,  153,     //bluegreen
  122,  200,  200,  200,     //gray
  181,  110,   61,    6,     //brown
  255,    6,  255,    0      //green
};

CRGBPalette16 currentPalette(greenblue_gp);
CRGBPalette16 targetPalette(orangepink_gp);

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.begin(57600);

  //Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++) {
    colorIndex[i] = random8();
  }
}

void loop() {
  
  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex[i]);
  }

  nblendPaletteTowardPalette( currentPalette, targetPalette, 10 );

  switch (whichPalette) {
    case 0:
      targetPalette = orangepink_gp;
      break;
    case 1:
      targetPalette = browngreen_gp;
      break;
     case 2:
      targetPalette = greenblue_gp;
      break;
  }

  EVERY_N_SECONDS(5) {
    whichPalette++;
    if (whichPalette > 2) whichPalette = 0;
    Serial.println(currentPalette[0]);
  }
  
  EVERY_N_MILLISECONDS(5){
    for (int i = 0; i < NUM_LEDS; i++) {
      colorIndex[i]++;
    }
  }

  FastLED.show();
}

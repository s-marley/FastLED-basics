#include <Regexp.h>
#include <FastLED.h>

#define NUM_LEDS 18
#define LED_PIN 2

const uint8_t noiseDataSize = 54;
uint8_t noiseData[noiseDataSize];
String strOutput;
const uint8_t chrInputSize = 20;
char chrInput[chrInputSize];
char chrTemp[chrInputSize];
bool newData = false;
bool showOutput = true;
MatchState ms;

uint8_t octaveVal = 1;
uint16_t xVal = 0;
int scaleVal = 10;
uint16_t timeVal = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(115200);
}

void loop() {
  
  EVERY_N_MILLISECONDS(33){
    for (int i = 0; i < noiseDataSize; i++) {
      noiseData[i] = inoise8(i * scaleVal + xVal, timeVal);
    }
    printOutputData();
  }

  // Check for new Serial data
  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(chrTemp, chrInput);
    
    // Check that the data is not malformed, can happen when
    // settings are changed to quickly
    ms.Target(chrTemp);
    char regexResult = ms.Match("%d+,%d+,%d+");
    if (regexResult == REGEXP_MATCHED) {
      //Serial.println(chrTemp);
      parseInputData();
    }
    
    newData = false;
  }

  // Send data to LEDs
  if(showOutput) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(noiseData[i*3], 255, 255);
    }
  }
  
  FastLED.show();
}

void recvWithStartEndMarkers() {
  
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        chrInput[ndx] = rc;
        ndx++;
        if (ndx >= chrInputSize) {
          ndx = chrInputSize - 1;
        }
      }
      else {
        chrInput[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
        recvInProgress = true;
    }
  }
}

void parseInputData() {

  char * strtokIndx;
  
  strtokIndx = strtok(chrTemp,",");
  xVal = atoi(strtokIndx);

  strtokIndx = strtok(NULL, ",");
  scaleVal = atoi(strtokIndx);

  strtokIndx = strtok(NULL, ",");
  timeVal = atoi(strtokIndx);
}

void printOutputData() {

  // Data is sometimes a bit glitchy due to Serial transfer
  // if average of data > 220 or so, it's probably a glitch
  // so ignore it.
  int accum = 0;
  for (int i = 0; i < noiseDataSize; i++) {
    accum += noiseData[i];
  }
  if (accum / noiseDataSize < 220) showOutput = true;
  else showOutput = false;

  if(showOutput) {
    strOutput = "";
    
    for (int i = 0; i < noiseDataSize; i++) {
      strOutput = strOutput + noiseData[i];
      if (i < noiseDataSize - 1) strOutput = strOutput + ",";
    }  
    Serial.println(strOutput);
  }
}

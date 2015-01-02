#include <FastLED.h>
#define NUM_LEDS 6

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];




int UP, DOWN, LEFT, RIGHT, A, B;


void setup()
{
  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);

}

void loop()
{
  ReadButtons();
  
  if(LEFT <500) {leds[0] = CRGB::Red;} else {leds[0] = CRGB::Black;}
  if(RIGHT <500) {leds[1] = CRGB::Red;}else {leds[1] = CRGB::Black;}
  if(UP <500) {leds[2] = CRGB::Red;}else {leds[2] = CRGB::Black;}
  if(DOWN <500) {leds[3] = CRGB::Red;}else {leds[3] = CRGB::Black;}
  if(A <500) {leds[4] = CRGB::Red;}else {leds[4] = CRGB::Black;}
  if(B <500) {leds[5] = CRGB::Red;}else {leds[5] = CRGB::Black;}
  FastLED.show();
  
}

void ReadButtons()
{
  LEFT = analogRead(A6);
  RIGHT = analogRead(A5);
  UP = analogRead(A4);
  DOWN = analogRead(A7);
  A = analogRead(A2);
  B = analogRead(A3);
}

void PrintAnalogPorts()
{
  Serial.print("A0=");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print("A1=");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print("A2=");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print("A3=");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print("A4=");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print("A5=");
  Serial.print(analogRead(A5));
  Serial.print(" ");
  Serial.print("A6=");
  Serial.print(analogRead(A6));
  Serial.print(" ");
  Serial.print("A7=");
  Serial.println(analogRead(A7));
}

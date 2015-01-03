#include <FastLED.h>

#define NUM_LEDS 6

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

boolean UP, DOWN, LEFT, RIGHT, A, B;
 
boolean rotatorOn = false; 

void setup()
{
  Serial.begin(115200);
  
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  
  pinMode(4,OUTPUT);

}

void loop()
{
  ReadButtons();
  ShowButtons();
  ToggleRotator();
}

void ToggleRotator()
{
  if (B == true)
  {
   rotatorOn = !rotatorOn;
  }
  
  if(rotatorOn == true)
  {
    digitalWrite(4,LOW);
  }
  else
  {
    digitalWrite(4,HIGH);
  }
  
  while(B == true)
 {
   ReadButtons();
 } 

 Serial.println("Exit B Button Press");
 delay(5);
}
  
void ShowButtons()
{
  
  if(LEFT == true) {leds[0] = CRGB::SeaGreen;}else {leds[0] = CRGB::Black;}
  if(RIGHT == true) {leds[1] = CRGB::Aquamarine;}else {leds[1] = CRGB::Black;}
  if(UP == true) {leds[2] = CRGB::LightSkyBlue;}else {leds[2] = CRGB::Black;}
  if(DOWN == true) {leds[3] = CRGB::DarkRed;}else {leds[3] = CRGB::Black;}
  if(A == true) {leds[4] = CRGB::White;}else {leds[4] = CRGB::Black;}
  if(B ==  true) {leds[5] = CRGB::Red;}else {leds[5] = CRGB::Black;}
  FastLED.show();

}

void ReadButtons()
{
  if(analogRead(A6) >500) {LEFT = true;} else {LEFT = false;}
  if(analogRead(A5) >500) {RIGHT = true;} else {RIGHT = false;}
  if(analogRead(A4) >500) {UP = true;} else {UP = false;}
  if(analogRead(A7) >500) {DOWN = true;} else  {DOWN = false;}
  if(analogRead(A2) >500) {A = true;} else  {A = false;}
  if(analogRead(A3) >500) {B = true;} else  {B = false;}
}

void PrintButtons()
{
Serial.print("LEFT=");
  Serial.print(LEFT);
  Serial.print(" ");
  Serial.print("RIGHT=");
  Serial.print(RIGHT);
  Serial.print(" ");
  Serial.print("UP=");
  Serial.print(UP);
  Serial.print(" ");
  Serial.print("DOWN=");
  Serial.print(DOWN);
  Serial.print(" ");
  Serial.print("A=");
  Serial.print(A);
  Serial.print(" ");
  Serial.print("B=");
  Serial.print(B);
  Serial.println(" ");
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

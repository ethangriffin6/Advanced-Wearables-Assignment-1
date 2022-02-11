/*
Restaurant Light Indicator Band
Ethan Griffin
DIGF-3010-001 Avanced Wearable Electronics
OCAD University
08 Feb, 2022
Based on:
MWE_CH08_Neopixels_Three, Kate Hartman, https://github.com/katehartman/Make-Wearable-Electronics/blob/master/MWE_Ch08_Neopixels_Three/MWE_Ch08_Neopixels_Three.ino 
external_neopixels, Adafruit, https://github.com/adafruit/Adafruit_CircuitPlayground/tree/master/examples/external_neopixels
*/

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define PIN       6//A1 on CPE
#define NUMPIXELS 8//length of neopixel stick

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool switchButton;
int buttonCount = 0;//starting count

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
  pinMode(2, INPUT_PULLUP);

}

void loop() {

  switchButton = CircuitPlayground.leftButton();//using button A / left button on CPE
  Serial.println(buttonCount);//keep track of which button state im in(0-3)

  if (switchButton == true){//if button is clicked
  
    if (buttonCount >= 3){//reset button count
      buttonCount = 0;
    }else{
      buttonCount++;
    }
  }
  
  if (buttonCount == 1){//flashing green lights in button state 1("waiter needed")
    pixels.setPixelColor(0, pixels.Color(0,200,0)); 
    pixels.setPixelColor(1, pixels.Color(0,200,0)); 
    pixels.setPixelColor(2, pixels.Color(0,200,0)); 
    pixels.setPixelColor(3, pixels.Color(0,200,0)); 
    pixels.setPixelColor(4, pixels.Color(0,200,0)); 
    pixels.setPixelColor(5, pixels.Color(0,200,0)); 
    pixels.setPixelColor(6, pixels.Color(0,200,0));
    pixels.setPixelColor(7, pixels.Color(0,200,0)); 
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(150);
    pixels.clear();
    pixels.show();
    
  }
  else if (buttonCount ==2){//dripping blue lights in button state 2("Refill needed")
    for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i-3, pixels.Color(0,0,1)); // blue
    pixels.setPixelColor(i-2, pixels.Color(0,0,75)); 
    pixels.setPixelColor(i-1, pixels.Color(0,0,150)); 
    pixels.setPixelColor(i, pixels.Color(0,0,255)); 
 
    pixels.show(); 
    delay(50);
    pixels.clear();
    pixels.show();
  }
  
  }
  else if (buttonCount == 3){//solid red lights in button state 3("Don't need anything")
    for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(150,0,0)); // red
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50);
  }
  }
  else {//button state 0
    pixels.clear();
    pixels.show();
    delay(100);
  }
    delay(100);
}


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN         12 
#define NUMPIXELS   2 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int brightMax;
int brightMin;
int Delay;


void setup() {
// Declare Pin Value, Type and Start Pixels
  pinMode(12, INPUT); 
  pixels.begin();
  
// Set Variables  
  brightMax = 50;
  brightMin = 20;
  Delay = 25;
  
}

void loop() {
  
// Turn 1 Pixel On
for (int light = brightMin; light <= brightMax; light++) {
    pixels.clear();                                         // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(0, 0, light));    
    pixels.show();                                          // Send the updated pixel colors to the hardware.
    delay(Delay);
    }
    
// Turn 1 Pixel Off
for (int light = brightMax; light >= brightMin+1; light--) {
    pixels.clear();                                         // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(0, 0, light));    
    pixels.show();                                          // Send the updated pixel colors to the hardware.
    delay(Delay);
    }
}


  
  


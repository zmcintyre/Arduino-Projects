// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN         0           // Pin where neopixel strip is connected

#define NUMPIXELS   2           // Number of pixels on the strip

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL    100

int PWMpin = 9;                 // Check what PWM pin to use
int PWMduration;                // Duration of the PWM pulse received
int PWMtoledmap;                // Map PWM input to LED output (1000-2000 to 0-255)

void setup() {
    pinMode(PWMpin, INPUT);     // PWM input pin
    pixels.begin();             // Begin Pixels
}

void loop() {

    PWMduration = pulseIn(PWMpin, HIGH);                // create variable duration holding the PWM value
    PWMtoledmap = map(PWMduration, 980, 2002, 0, 255);  // Map PWM input to LED output (1000-2000 to 0-255)
    
    pixels.clear();                                     // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(0, 0, 225));   // 2nd led Blue
    pixels.setPixelColor(0, pixels.Color(225, 0, 0));   // 1st led Red
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    
    delay(DELAYVAL);
    
    pixels.clear();                                     // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(225, 0, 0));   // 1 Red
    pixels.setPixelColor(0, pixels.Color(0, 0, 225));   // 2 Blue
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    
    delay(DELAYVAL);

    pixels.clear();                                     // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(225, 0, 225)); // 1 Red
    pixels.setPixelColor(0, pixels.Color(0, 225, 0));   // 2 Blue
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    
    delay(DELAYVAL);
  }

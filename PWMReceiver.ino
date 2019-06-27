// Simple sketch to read the pulse width of a PWM signal
// Useful for reading PWM valuss from a R/C reciever
// to create actions that are not typically handled
// with a servo, such as controlling LED lighting.
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN         12 
#define NUMPIXELS   2 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//PWM Setup

int pin = 9;                    // Check what pin to use
int outblink = 13;              // LED pin to blink
int duration;                   // Duration of the pulse
int ledmap;

//Colors

int Blue;
int Red;
int Green;

void setup(){                                             // setup serial and input, output pins

  Serial.begin(9600);
  pinMode(pin, INPUT);                                    // PWM input pin
  pixels.begin(); 

}

void loop(){

  duration = pulseIn(pin, HIGH);
  ledmap = map(duration, 980, 2002, 0, 255);
  Serial.print("pulse ");
  Serial.println(ledmap);
  
  pixels.clear();                                         // Set all pixel colors to 'off'
  pixels.setPixelColor(1, pixels.Color(ledmap, 0, 0));    // 1 Blue
  pixels.show();                                          // Send the updated pixel colors to the hardware.

  delay(100);                                             //delay so you can read the scrolling output
}

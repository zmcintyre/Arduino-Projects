/* OLED */

#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
SSD1306  display(0x3c, 5, 4); // Initialise the OLED display using Wire library

/* DHT22 */
#include "DHT.h"
#define DHTPIN 14
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int localHum = 0;
int localTemp = 0;

void setup()
{
  Serial.begin(9600);
  display.init(); // Initialising the UI will init the display too.
  display.flipScreenVertically();
  display.clear();
  display.drawString(0, 5, "Welcome");
  display.display();
  pinMode(DHTPIN, INPUT);
}

void loop() 
{ 
  getDHT();
  delay(3000);
  display.clear();
  drawDHT();
  display.display();
}

void getDHT()
{
  float tempIni = localTemp;
  float humIni = localHum;
  localTemp = dht.readTemperature();
 /* for returning Fahrenheit use localTemp = dht.readTemperature(true) */
  localHum = dht.readHumidity(); 
  if (isnan(localHum) || isnan(localTemp))   // Check if any reads failed and exit early (to try again).
  {
    Serial.println("Failed to read from DHT sensor!");
    localTemp = tempIni;
    localHum = humIni;
    return;
  }
}

void drawDHT() 
{
  int x=0;
  int y=0;
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0 + x, 5 + y, "Hum");
  
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(43 + x, y, "INDOOR");

  display.setFont(ArialMT_Plain_24);
  String hum = String(localHum) + "%";
  display.drawString(0 + x, 15 + y, hum);
  int humWidth = display.getStringWidth(hum);

  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(95 + x, 5 + y, "Temp");

  display.setFont(ArialMT_Plain_24);
  String temp = String(localTemp) + "°C";
  display.drawString(70 + x, 15 + y, temp);
  int tempWidth = display.getStringWidth(temp);
}

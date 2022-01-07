#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  lcd.begin(16,2);
  lcd.backlight();
  dht.begin();
}
void loop() {

int h = dht.readHumidity();
int t = dht.readTemperature();

lcd.setCursor(0, 0);
lcd.print("Temperatura: ");
lcd.print(t);
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Wilgotnosc: ");
lcd.print(h);
lcd.print("%");
delay(100);
}

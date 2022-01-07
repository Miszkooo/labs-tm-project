# Projekt Technika Mikroprocesorowa


## Termometr z wykorzystaniem czujnika DHT11 oraz wyświetlaczem LCD
Nasze testy przeprowadzimy na popularnym, cyfrowym czujniku DHT-11. Układ ten łączy w jednej obudowie termometr oraz czujnik wilgotności. Informacje z czujnika wyświetlimy na wyświetlaczu LCD.
Najważniejsze parametry czujnika:
- Napięcie zasilania: 3 V do 5,5 V (w naszym przypadku będzie to 5 V)
- Pobór prądu: 0,2 mA
- Częstotliwość próbkowania: 1Hz (nowe informacje można odczytywać co sekundę)
- Zakres pomiarowy: 0 - 50 °C
- Dokładność: ±2°C
- Zakres pomiarowy: 20 - 95%RH
- Dokładność  ±5%RH
Czujnik DHT11 jest tanim wyborem i nie ma zakresu dla temperatur minusowych dlatego nadaje się do mierzenie temperatury w pomieszczeniu.

![img](./dht11.JPG)

Do wyświetlania pomiarów wykorzystamy wyświetlacz LCD z konwerterterem I2C LCM1602. Dzięki temu nasz projekt będzie o wiele prosty w wykonaniu, ograniczymy ilość użytych przewodów do połączeń, oraz niepotrzebny będzie nam potencjometr oraz rezystor który normalnie byłby użyty.

## Wykaz elementów 
### Do wykonania projektu będziemy potrzebować następujących elementów:
– Arduino UNO
- Czujnik temperatury i wilgotności DHT11
- Wyświetlacz LCD 2x16 znaków niebieski + konwerter I2C LCM1602
- płytka stykowa
- przewody
## Schemat
![img](./schemat.JPG)
## Szczegóły dotyczące kodu
Aby zacząć pisać program trzeba pobrać 2 bibilioteki. Pierwszą obsługującą czujniki DHT-"SDHT", oraz drugą obsługującą wyświetlacz LCD z konwerterem I2C "New-LiquidCrystal-master".

## Kod programu
```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
```
Biblioteki potrzebne do wykonanie programu. DHT.h obsługuje nasz czujnik,  LiquidCrystal_I2C.h oraz Wire.h pozwalają na komunikację z urządzeniami I2C.

```cpp
#define DHTPIN 2
#define DHTTYPE DHT11
```
W kolejnym kroku należy zadeklarować czujnik oraz poinformować bibliotekę o pinie, na którym ma odbywać się komunikacja
```cpp
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
```
Deklaracja pinów I2C
```cpp
void setup()
{
  lcd.begin(16,2);
  lcd.backlight();
  dht.begin();
}
```
W pierwszej linii setupu definiujemy 16 kolumn i 2 rzędy wyświetlacza lcd, następnie włączamy tylne swiatło wyświetlacza, w ostatniej włączamy czujnik DHT
```cpp
int h = dht.readHumidity();
int t = dht.readTemperature();
```
Pierwszą rzeczą jaką musimy zrobić w pętli to pobieranie danych z czujnika i zapisywanie ich w zmiennej
```cpp
lcd.setCursor(0, 0);
lcd.print("Temperatura: ");
lcd.print(t);
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Wilgotnosc: ");
lcd.print(h);
lcd.print("%");
delay(100);
```
W ostatniej części naszego kodu musimy zająć się wyświetlaczem. lcd.setCursor(0, 0) oznacza ustawienie kursora na 0 rząd i 0 kolumnę wyświetlacza, następnie wyświetlamy potrzebny tekst oraz zmienną. Delay ustawiamy na 100 ms ponieważ częstotliwość próbkowania wynosi 1Hz.
## 
![img](./zdj1.JPG)
![img](./zdj2.JPG)
![img](./zdj3.JPG)


#include <Wire.h>          // Подключаем необходимые библиотеки
#include "LiquidCrystal.h" // Библиотека для работы с дисплеем LCD 1602. Русификатора для LCD 1602 keypad shield нет)))
#include <DHT.h>

DHT dht(2, DHT11); // Инициация датчика

int t1 = 30, t2 = 20;  // Переменные допустимых границ температуры
int h1 = 30, h2 = 70;  // Переменные допустимых границ влажности

#define PIN_LED_1 3           // Светодиод подключен к Digital PWM пину для изменения интенсивности света от датчика света
#define PIN_LED_2 6         // Светодиод подключен к Digital пину для сигнализации критических положений параметров
#define PIN_PHOTO_SENSOR A1 // Датчик света подключен к аналоговому пину номер 1

// Наименование кнопок
#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_LEFT 3
#define BTN_RIGHT 4
#define BTN_SELECT 5
#define BTN_NONE 10

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Выводы необходимые для работы дисплея.

void blinkLed() {
  int i = 0;
  do {
    digitalWrite(PIN_LED_1, HIGH);
    digitalWrite(PIN_LED_2, HIGH);
    delay(100);
    digitalWrite(PIN_LED_1, LOW);
    digitalWrite(PIN_LED_2, LOW);
    delay(100);
    i++;
  }while (i<5);
}

int detectButton() {
  int keyAnalog = analogRead(A0);
  if (keyAnalog < 100) {
    return BTN_RIGHT;
  } else if (keyAnalog < 200) {
    return BTN_UP;
  } else if (keyAnalog < 400) {
    return BTN_DOWN;
  } else if (keyAnalog < 600) {
    return BTN_LEFT;
  } else if (keyAnalog < 800) {
    return BTN_SELECT;
  } else {
    return BTN_NONE;
  }
}

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {
  int button = detectButton();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Моргание светодиодом при выходе за пределы допустимых значений температуры
  if (temperature > t1 || temperature < t2) {
    blinkLed();
  } else {
    digitalWrite(PIN_LED_1, LOW);
  }

  // Моргание светодиодом при выходе за пределы допустимых значений влажности
  if (humidity > h1 || humidity < h2) {
    blinkLed();
  } else {
    digitalWrite(PIN_LED_1, LOW);
  }

  // Моргание светодиодами при включении устройства
  static bool startupBlink = true;
  if (startupBlink) {
    blinkLed();
    startupBlink = false;
  }

  // Моргание светодиодами при выходе за пределы температуры
  if (temperature < 20 || temperature > 30) {
    blinkLed();
  } else {
    digitalWrite(PIN_LED_1, LOW);
  }

  // Моргание светодиодами при выходе за пределы влажности
  if (humidity < 35 || humidity > 70) {
    blinkLed();
  } else {
    digitalWrite(PIN_LED_1, LOW);
  }

  int val = analogRead(PIN_PHOTO_SENSOR);
  int ledPower = map(val, 0, 1023, 0, 255);
  analogWrite(PIN_LED_2, ledPower);

  switch (button) {
    case BTN_UP:
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("NO_INFO");

      digitalWrite(3, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
      break;

    case BTN_DOWN:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("----HUMIDITY----");
      lcd.setCursor(5, 1);
      lcd.print(humidity, 1);
      lcd.setCursor(9, 1);
      lcd.print("%");

      digitalWrite(3, LOW);
      digitalWrite(6, LOW);
      digitalWrite(8, LOW);

      digitalWrite(6, HIGH);
      break;

    case BTN_LEFT:
      lcd.clear();
      lcd.setCursor(0, 0);
      if (val < 300)
        lcd.print("THE LIGHT IS ON");
      else
        lcd.println("THE LIGHT IS OFF");
      lcd.setCursor(5, 1);
      lcd.print(val, 1);

      digitalWrite(3, LOW);
      digitalWrite(6, LOW);
      digitalWrite(8, LOW);

      digitalWrite(3, HIGH);
      break;

    case BTN_RIGHT:

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("--TEMPERATURE---");
      lcd.setCursor(5, 1);
      lcd.print(temperature, 1);
      lcd.setCursor(9, 1);
      lcd.print("C");

      digitalWrite(3, LOW);
      digitalWrite(6, LOW);
      digitalWrite(8, LOW);

      digitalWrite(6, HIGH);
      break;

    case BTN_SELECT:
      lcd.clear();
      lcd.setCursor(0, 0);
      if (val < 300)
        lcd.print("THE LIGHT IS ON");
      else
        lcd.println("THE LIGHT IS OFF");
      lcd.setCursor(5, 1);
      lcd.print(val, 1);

      digitalWrite(3, LOW);
      digitalWrite(6, LOW);
      digitalWrite(8, LOW);

      digitalWrite(3, HIGH);
      break;

    default:
      break;
  }
}

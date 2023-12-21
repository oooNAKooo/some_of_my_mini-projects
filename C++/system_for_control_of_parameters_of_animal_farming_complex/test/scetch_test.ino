#include <Wire.h>
#include "LiquidCrystal.h"
#include <DHT.h>

DHT dht(2, DHT11);

int t1 = 30, t2 = 20;
int h1 = 30, h2 = 70;

#define PIN_LED 3
#define PIN_LED1 13
#define PIN_PHOTO_SENSOR A1

#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_LEFT 3
#define BTN_RIGHT 4
#define BTN_SELECT 5
#define BTN_NONE 10

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void blinkLed() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_LED1, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_LED1, LOW);
    delay(100);
  }
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
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("WAIT...");

  blinkLed();
}

void loop() {
  int button = detectButton();

  int val = analogRead(PIN_PHOTO_SENSOR);
  int ledPower = map(val, 0, 1023, 0, 255);
  analogWrite(PIN_LED, ledPower);

  if (button != BTN_NONE) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("HELLO");

    blinkLed();

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("BUTTON PRESSED");

    // В зависимости от нажатой кнопки выполните соответствующее действие
    switch (button) {
      case BTN_UP:
        // Ваш код для BTN_UP
        break;

      case BTN_DOWN:
        // Ваш код для BTN_DOWN
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
        // Ваш код для BTN_RIGHT
        break;

      case BTN_SELECT:
        // Ваш код для BTN_SELECT
        break;

      default:
        break;
    }

    delay(1000); // Дополнительная задержка для стабилизации
  }
}

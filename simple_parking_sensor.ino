#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 8
#define BUZZER_PIN 7

const int SHORT_DISTANCE = 20;
const int MIDDLE_DISTANCE = 40;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe:");

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float distance = calculateDistance();

  char buffer[8];
  dtostrf(distance, 5, 1, buffer);
  lcd.setCursor(0, 1);
  lcd.print("            ");
  lcd.setCursor(0, 1);
  lcd.print(buffer);
  lcd.print(" cm");

  if (distance <= SHORT_DISTANCE) {
    tone(BUZZER_PIN, 1000);
    delay(50);
    noTone(BUZZER_PIN);
  } else if (distance <= MIDDLE_DISTANCE) {
    tone(BUZZER_PIN, 1000);
    delay(300);
    noTone(BUZZER_PIN);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(100);
}

float calculateDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2.0;
}
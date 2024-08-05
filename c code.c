#include <LiquidCrystal.h>
#include <Ultrasonic.h>

// Define pins for LCD, ultrasonic sensor, LED, and switch
const int lcd_rs = 12, lcd_en = 11, lcd_d4 = 5, lcd_d5 = 4, lcd_d6 = 3, lcd_d7 = 2;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const int switchPin = 8;

LiquidCrystal lcd(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7);
Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  int switchState = digitalRead(switchPin);
  if (switchState == HIGH) {
    long duration, distance;
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1 / 10; // Calculate distance in cm
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm");
    if (distance < 10) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}

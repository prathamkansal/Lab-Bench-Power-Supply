#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize LCD with I2C address
const int buzzerPin = 5;  // Define buzzer pin
const int backlightPin = 6;  // Pin for controlling the backlight

void beep(int duration) {
  digitalWrite(buzzerPin, HIGH);  // Turn on buzzer
  delay(duration);                // Buzzer on for specified duration
  digitalWrite(buzzerPin, LOW);   // Turn off buzzer
  delay(30);                      // Short pause between beeps
}

void playStartupBeep() {
  // PC-like startup beep sequence using beep() function
  beep(50);  // Short beep
  beep(30);  // Short beep
  beep(30);  // Short beep

  delay(1000);  // Pause before the second sequence

  beep(50);  // Short beep
  beep(30);  // Short beep
  beep(30);  // Short beep

  delay(1000);  // Pause before the third sequence

  beep(50);  // Short beep
  beep(30);  // Short beep
  beep(30);  // Short beep

  delay(1000);  // Pause before the final long beep

  digitalWrite(buzzerPin, HIGH);  // Long beep
  delay(800);  // Long beep duration
  digitalWrite(buzzerPin, LOW);   // Turn off buzzer
}

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
  pinMode(backlightPin, OUTPUT);  // Set backlight pin as output

  lcd.init();
  lcd.backlight();  // Turn on the backlight by default

  // Adjust backlight brightness using PWM (0 to 255)
  analogWrite(backlightPin, 25);  // Set the brightness to 50% (range: 0 to 255)

  // Play PC-like startup beep
  playStartupBeep();

  // Display hello message
  lcd.setCursor(0, 0);
  lcd.print("Hello!");
  lcd.setCursor(0, 1);
  lcd.print("Power Supply ON");
}

void loop() {
  // The loop() function is left empty because the startup sound and message are only needed once
}

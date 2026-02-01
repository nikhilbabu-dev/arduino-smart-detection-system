#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change address if your LCD is 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10
#define IR_PIN 6
#define SERVO_PIN 5
#define RELAY_PIN 7

Servo myServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("System Ready");
  delay(1500);
}

void loop() {
  // Ultrasonic distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  int motion = digitalRead(IR_PIN);

  // LCD Line 1
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dist:");
  lcd.print(distance);
  lcd.print("cm ");

  // Decision logic
  lcd.setCursor(0,1);
  if (distance > 0 && distance < 20 && motion == HIGH) {
    lcd.print("State: ACTIVE");
    myServo.write(60);
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
  } else {
    lcd.print("State: IDLE  ");
    myServo.write(0);
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
  }

  // Serial Monitor output (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" | Motion: ");
  Serial.println(motion == HIGH ? "YES" : "NO");

  delay(500);
}

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Ultrasonic sensor pins
const int echoPin = 3;
const int trigPin = 4;

// LED and buzzer pins
const int redLed = 7;
const int yellowLed = 6;
const int greenLed = 5;
const int buzzerPin = 8;

// Maximum distance (ความสูงถัง)
const float maxDistance = 20.0;

// เก็บค่าก่อนหน้าเพื่อไม่ให้จอกระพริบ
String lastStatus = "";
int lastWaterLevel = -1;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // พิมพ์หัวข้อแค่ครั้งเดียว
  lcd.setCursor(0, 0);
  lcd.print("Water Level :");
}

void loop() {
  float distance = readDistance();
  if (distance > maxDistance) distance = maxDistance;

  // คำนวณ % ระดับน้ำ
  int waterLevel = (1 - (distance / maxDistance)) * 100;
  if (waterLevel < 0) waterLevel = 0;
  if (waterLevel > 100) waterLevel = 100;

  // กำหนดสถานะตามระดับ
  String status = "";
  if (distance <= 4) {
    status = "FULL";
  } else if (distance > 4 && distance <= 6) {
    status = "NEARLY FULL";
  } else if (distance > 6 && distance <= 12) {
    status = "MEDIUM";
  } else if (distance > 12 && distance <= 17) {
    status = "LOW";
  } else {
    status = "VERY LOW";
  }

  // แสดงบนบรรทัดที่ 2 เฉพาะเมื่อ status หรือ % เปลี่ยน
  if (status != lastStatus || waterLevel != lastWaterLevel) {
    String line = String(waterLevel) + "% " + status;

    // เติมช่องว่างให้ครบ 16 ตัวอักษร เพื่อทับตัวอักษรเดิม
    while (line.length() < 16) {
      line += " ";
    }

    lcd.setCursor(0, 1);
    lcd.print(line);

    // อัปเดตค่าก่อนหน้า
    lastStatus = status;
    lastWaterLevel = waterLevel;
  }

  // ไฟเตือน + Buzzer
  if (distance <= 5) {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else if (distance > 5 && distance <= 10) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin, LOW);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}

// อ่านระยะทางจาก Ultrasonic Sensor
float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float distance = pulseIn(echoPin, HIGH) / 58.0;
  return distance;
}
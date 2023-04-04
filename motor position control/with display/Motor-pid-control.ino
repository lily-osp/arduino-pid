#include <Wire.h> // library untuk komunikasi I2C
#include <LiquidCrystal_I2C.h> // library untuk LCD I2C
#include <PID_v1.h> // library PID

LiquidCrystal_I2C lcd(0x27, 20, 4); // inisialisasi objek LCD
double Setpoint, Input, Output;
double kp, ki, kd = 0; // inisialisasi konstanta
int potPin1 = A0; // pin untuk potensio ke-1
int potPin2 = A1; // pin untuk potensio ke-2
int potPin3 = A2; // pin untuk potensio ke-3
int motorPin = 9; // pin untuk motor DC

unsigned long previousMillis = 0; // variabel untuk menyimpan waktu sebelumnya
const long interval = 100; // interval waktu dalam milidetik

PID myPID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT); // inisialisasi PID

void setup() {
  pinMode(motorPin, OUTPUT); // set pin motor DC sebagai OUTPUT
  Serial.begin(9600); // buka serial monitor
  lcd.init(); // inisialisasi LCD
  lcd.backlight(); // nyalakan backlight LCD
  Setpoint = 50; // set nilai setpoint
  myPID.SetMode(AUTOMATIC); // set mode PID ke AUTOMATIC
}

void loop() {
  unsigned long currentMillis = millis(); // baca waktu saat ini

  if (currentMillis - previousMillis >= interval) { // jika sudah mencapai interval waktu
    previousMillis = currentMillis; // simpan waktu saat ini sebagai waktu sebelumnya

    potVal1 = analogRead(potPin1); // baca nilai potensio ke-1
    potVal2 = analogRead(potPin2); // baca nilai potensio ke-2
    potVal3 = analogRead(potPin3); // baca nilai potensio ke-3

    // konversi nilai analog ke range 0-1
    kp = map(potVal1, 0, 1023, 0, 1);
    ki = map(potVal2, 0, 1023, 0, 1);
    kd = map(potVal3, 0, 1023, 0, 1);

    // update konstanta PID
    myPID.SetTunings(kp, ki, kd);

    Input = analogRead(A3); // baca nilai sensor sebagai input
    myPID.Compute(); // hitung output PID

    // kendalikan motor DC dengan output PID
    if(Output > 0) {
      digitalWrite(motorPin, HIGH);
      analogWrite(motorPin, Output);
    }
    else {
      digitalWrite(motorPin, LOW);
      analogWrite(motorPin, abs(Output));
    }

    // tampilkan nilai input, output, dan konstanta di LCD
    lcd.clear(); // hapus tampilan LCD
    lcd.setCursor(0, 0);
    lcd.print("Input: ");
    lcd.print(Input);
    lcd.setCursor(0, 1);
    lcd.print("Output: ");
    lcd.print(Output);
    lcd.setCursor(0, 2);
    lcd.print("kp: ");
    lcd.print(kp);
    lcd.setCursor(0, 3);
    lcd.print("ki: ");
    lcd.print(ki);
    lcd.setCursor(10, 2);
    lcd.print("kd: ");
    lcd.print(kd);

    // tampilkan nilai input, output, dan konstanta di serial monitor
    Serial.print("Input: ");
    Serial.print(Input);
    Serial.print(", Output: ");
    Serial.print(Output);
    Serial.print(", kp: ");
    Serial.print(kp);
    Serial.print(", ki: ");
    Serial.print(ki);
    Serial.print(", kd: ");
    Serial.println(kd);
  }
}

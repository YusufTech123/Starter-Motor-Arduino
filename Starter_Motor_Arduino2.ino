// YusufTech Electronics All Rights Reserved V.2
// Programmer : Yusuf Ghazali
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

SoftwareSerial modulBluetooth(0,1); 
LiquidCrystal_I2C lcd (0x27, 16, 2);
char perintah;
const int relayStarter = 5;
const int relayMesin = 6;
const int relaySpeed = 10;
const int relayRem = 9;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight(); 
  modulBluetooth.begin(9600);
  pinMode(relayStarter, OUTPUT);
  pinMode(relayMesin, OUTPUT);
  pinMode(relaySpeed, OUTPUT);
  pinMode(relayRem, OUTPUT);
  digitalWrite(relayStarter, HIGH);
  digitalWrite(relayMesin, HIGH);
  digitalWrite(relaySpeed, HIGH);
  digitalWrite(relayRem, HIGH);
}

void loop() {
  if( modulBluetooth.available() ) 
{
  perintah = modulBluetooth.read();
  if ( perintah == 'A' ) { 
    digitalWrite(relayMesin, LOW);
    digitalWrite(relaySpeed, LOW);
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("MENGHIDUPKAN");
    lcd.setCursor(0,1);
    lcd.print("MOTOR...");
    digitalWrite(relayRem, LOW);
    delay(500);
    digitalWrite(relayStarter, LOW);
    delay(1000);
    digitalWrite(relayStarter, HIGH);
    digitalWrite(relayRem, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MOTOR HIDUP");
    delay(1000);
    lcd.clear();
  }
    if ( perintah == 'S' ) {
      lcd.setCursor(0,0);
      lcd.print("MEMATIKAN");
      lcd.setCursor(0,1);
      lcd.print("MOTOR");
      delay(1000);
      digitalWrite(relayMesin, HIGH);
      digitalWrite(relaySpeed, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MOTOR MATI");
      delay(1000);
      lcd.clear();
    }
  }
}

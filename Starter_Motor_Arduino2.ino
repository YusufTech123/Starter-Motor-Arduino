// YusufTech Electronics All Rights Reserved V.2
// Programmer : Yusuf Ghazali
#include <SoftwareSerial.h>
#include <Wire.h> 

SoftwareSerial modulBluetooth(0,1); 
char perintah;
const int relayStarter = 5;
const int relayMesin = 6;
const int relaySpeed = 10;
const int relayRem = 9;

void setup() {
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
    digitalWrite(relayRem, LOW);
    delay(500);
    digitalWrite(relayStarter, LOW);
    delay(1000);
    digitalWrite(relayStarter, HIGH);
    digitalWrite(relayRem, HIGH);
    delay(1000);
  }
    if ( perintah == 'S' ) {
      digitalWrite(relayMesin, HIGH);
      digitalWrite(relaySpeed, HIGH);
    }
  }
}

#include "wiring_private.h"

#define rxPin 2
#define txPin 1
HardwareSerial mySerial(1);

void setup() {

  mySerial.begin(115200, SERIAL_8N1, rxPin, txPin);
  mySerial.print("#0D1500\r");   // clears the servo serial buffer

  // set the LYNX led colors
  mySerial.print(String("#") + 254 + String("LED") + 0 + "\r");  // set LED
  delay(500);
  mySerial.print(String("#") + 254 + String("LED") + 2 + "\r");  // set LED
  delay(500);
  mySerial.print(String("#") + 254 + String("LED") + 3 + "\r");  // set LED
  delay(500);
}

void loop() {
  mySerial.print(String("#") + 254 + String("D") + 1800 + "\r");  // move to 180 degrees
  delay(3000);
  mySerial.print(String("#") + 254 + String("D") + 900 + "\r");  // move to 90 degrees
  delay(3000);
  mySerial.print(String("#") + 254 + String("D") + 0 + "\r");  // move to 0 degrees
  delay(3000);
}
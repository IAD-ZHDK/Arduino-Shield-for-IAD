#include <SoftwareSerial.h>


#define rxPin 8
#define txPin 9

SoftwareSerial servoSerial(rxPin, txPin);


void setup() {

  servoSerial.begin(115200);

  servoSerial.print("#0D1500\r");  // this is used to clear the serial buffer

 // set the LYNX led colors 
  servoSerial.print(String("#") + 254 + String("LED") + 0 + "\r");  // set LED
  delay(500);
  servoSerial.print(String("#") + 254 + String("LED") + 2 + "\r");  // set LED
  delay(500);
  servoSerial.print(String("#") + 254 + String("LED") + 3 + "\r");  // set LED
  delay(500);
}

void loop() {
  servoSerial.print(String("#") + 254 + String("D") + 1800  + "\r"); // move to 180 degrees
  delay(3000);
  servoSerial.print(String("#") + 254 + String("D") + 900  + "\r"); // move to 90 degrees
  delay(3000);
  servoSerial.print(String("#") + 254 + String("D") + 0  + "\r"); // move to 0 degrees
  delay(3000);
}
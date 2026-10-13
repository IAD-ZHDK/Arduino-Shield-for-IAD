#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9

SoftwareSerial servoSerial(rxPin, txPin);

void setup() {
  Serial.begin(115200);

  servoSerial.begin(115200);
  servoSerial.print("#0D1500\r");  // this is used to clear the serial buffer
 // set the LYNX ID
 // servoSerial.print(String("#") + 254 + String("CID") + 0 + "\r");  // set LED
 // delay(1000);
 // set the LYNX led colors 
  servoSerial.print(String("#") + 0 + String("LED") + 0 + "\r");  // set LED
  delay(500);
  servoSerial.print(String("#") + 0 + String("LED") + 2 + "\r");  // set LED
  delay(500);
  servoSerial.print(String("#") + 0 + String("LED") + 3 + "\r");  // set LED
  delay(500);

  // Set servo to limp mode
  servoSerial.print(String("#") + 0 + String("L") + "\r");
  delay(500);
  Serial.println("Smart servo Query Example ");
}

void loop() {
  // Read the angle from the servo
  servoSerial.print(String("#") + 0 + String("QD") + "\r");

  if (servoSerial.available()) {
    String angle = servoSerial.readStringUntil('\r');
    Serial.println(angle);
  }   
  delay(100);  // Wait before the next read  
}
#include "wiring_private.h"


#define rxPin 1
#define txPin 0
Uart mySerial(&sercom3, rxPin, txPin, SERCOM_RX_PAD_1, UART_TX_PAD_0);  // Create the new UART instance

void SERCOM3_Handler() {
  mySerial.IrqHandler();
}

void setup() {

  pinPeripheral(rxPin, PIO_SERCOM);  //Assign RX function
  pinPeripheral(txPin, PIO_SERCOM);  //Assign TX function
  mySerial.begin(115200);

  mySerial.print("#0D1500\r");  // this is used to clear the serial buffer

 // set the LYNX led colors 
  mySerial.print(String("#") + 254 + String("LED") + 0 + "\r");  // set LED
  delay(500);
  mySerial.print(String("#") + 254 + String("LED") + 2 + "\r");  // set LED
  delay(500);
  mySerial.print(String("#") + 254 + String("LED") + 3 + "\r");  // set LED
  delay(500);
}

void loop() {
  mySerial.print(String("#") + 254 + String("D") + 1800  + "\r"); // move to 180 degrees
  delay(3000);
  mySerial.print(String("#") + 254 + String("D") + 900  + "\r"); // move to 90 degrees
  delay(3000);
  mySerial.print(String("#") + 254 + String("D") + 0  + "\r"); // move to 0 degrees
  delay(3000);
}
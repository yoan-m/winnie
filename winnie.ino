#include <SoftwareSerial.h>

const byte rxPin = 11;
const byte txPin = 12;


SoftwareSerial mySerial (rxPin, txPin);
char filename[20] = {};
unsigned int lastMsg = 0;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  mySerial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sprintf(filename, "AT+SEND=1,1,%u", lastMsg);
  Serial.println(filename);
  mySerial.println(filename);
  lastMsg++;
  delay(5000);
}

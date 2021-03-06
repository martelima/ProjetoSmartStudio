/**
 * Projeto: SmartStudio
 *  "Projeto de sistema para automação de estudio caseiro usando um esp8266"
 *
 * @author Mateus Lima
 */

#define MEGA_TX 13
#define MEGA_RX 15

#include<SoftwareSerial.h>

SoftwareSerial arduinoSerial(MEGA_TX,MEGA_RX);

void setup() {
  // Start Serial Communication
  arduinoSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  char arduinoCommand = '*';
  char arduinoState = '*';

  // Read Serial Send commands to Arduino
  if (Serial.available() > 0) {
    arduinoCommand  = Serial.read();

    arduinoSerial.write( arduinoCommand );
  }

  // Print Arduino Response
  if (arduinoSerial.available() > 0) {
    arduinoState  = arduinoSerial.read();

    Serial.write( arduinoState );
  }
}

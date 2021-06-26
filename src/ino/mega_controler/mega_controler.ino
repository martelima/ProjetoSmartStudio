/**
 *  Controler
 *  @version 0.1
 */

#define RELAY_OFF 255
#define RELAY_ON 0

enum Relay
{
  Relay_PORT_A = 3,
  Relay_PORT_B = 4,
  Relay_PORT_C = 5,
};

int state = 0;

void setup() {

  // ESP Comunication
  Serial.begin(9600);
  
  // Turn All ports OFF
  analogWrite( Relay_PORT_A, RELAY_OFF );
  analogWrite( Relay_PORT_B, RELAY_OFF );
  analogWrite( Relay_PORT_C, RELAY_OFF );
}

void loop() {

  char espCommand = '*';

  // Read ESP Commands  
  if (Serial.available() > 0) {
    espCommand  = Serial3.read();
    Serial.write( espCommand );
  }

  controlRelayPorts( espCommand );
}

/**
 * Control Relay Port State
 *  a-z: turn port [A-Z] off
 *  A-Z: turn port [A-Z] on
 */
void controlRelayPorts( char command )
{

  switch( command )
  {
    case 'a':
    {
      analogWrite( Relay_PORT_A, RELAY_OFF );
      break;
    }

    case 'b':
    {
      analogWrite( Relay_PORT_B, RELAY_OFF );
      break;
    }

    case 'c':
    {
      analogWrite( Relay_PORT_C, RELAY_OFF );
      break;
    }

    case 'A':
    {
      analogWrite( Relay_PORT_A, RELAY_ON );
      break;
    }

    case 'B':
    {
      analogWrite( Relay_PORT_B, RELAY_ON );
      break;
    }

    case 'C':
    {
      analogWrite( Relay_PORT_C, RELAY_ON );
      break;
    }
  }
}

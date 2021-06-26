/**
 *  Controler
 *  @version 0.1
 */

#define RELAY_OFF 255
#define RELAY_ON 0

enum Relay
{
  Relay_PORT_A = 2,
  Relay_PORT_B = 3,
  Relay_PORT_C = 4,
  Relay_PORT_D = 5,
  Relay_PORT_E = 6,
  Relay_PORT_F = 7,
  Relay_PORT_G = 8,
  Relay_PORT_H = 9,
  Relay_PORT_I = 10,
  Relay_PORT_J = 11,

};

int state = 0;

void setup() {

  // ESP Comunication
  Serial.begin(9600);
  
  // Turn All ports OFF
  analogWrite( Relay_PORT_A, RELAY_OFF );
  analogWrite( Relay_PORT_B, RELAY_OFF );
  analogWrite( Relay_PORT_C, RELAY_OFF );
  analogWrite( Relay_PORT_D, RELAY_OFF );
  analogWrite( Relay_PORT_E, RELAY_OFF );
  analogWrite( Relay_PORT_F, RELAY_OFF );
  analogWrite( Relay_PORT_G, RELAY_OFF );
  analogWrite( Relay_PORT_H, RELAY_OFF );
  analogWrite( Relay_PORT_I, RELAY_OFF );
  analogWrite( Relay_PORT_J, RELAY_OFF );
}

void loop() {

  char espCommand = '*';

  // Read ESP Commands  
  if (Serial.available() > 0) {
    espCommand  = Serial.read();
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

    case 'd':
    {
      analogWrite( Relay_PORT_D, RELAY_OFF );
      break;
    }

    case 'e':
    {
      analogWrite( Relay_PORT_E, RELAY_OFF );
      break;
    }

    case 'f':
    {
      analogWrite( Relay_PORT_F, RELAY_OFF );
      break;
    }

    case 'g':
    {
      analogWrite( Relay_PORT_G, RELAY_OFF );
      break;
    }

    case 'h':
    {
      analogWrite( Relay_PORT_H, RELAY_OFF );
      break;
    }

    case 'i':
    {
      analogWrite( Relay_PORT_I, RELAY_OFF );
      break;
    }
    case 'j':
    {
      analogWrite( Relay_PORT_J, RELAY_OFF );
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

    case 'D':
    {
      analogWrite( Relay_PORT_D, RELAY_ON );
      break;
    }

    case 'E':
    {
      analogWrite( Relay_PORT_E, RELAY_ON );
      break;
    }

    case 'F':
    {
      analogWrite( Relay_PORT_F, RELAY_ON );
      break;
    }

    case 'G':
    {
      analogWrite( Relay_PORT_G, RELAY_ON );
      break;
    }

    case 'H':
    {
      analogWrite( Relay_PORT_H, RELAY_ON );
      break;
    }

    case 'I':
    {
      analogWrite( Relay_PORT_I, RELAY_ON );
      break;
    }
    case 'J':
    {
      analogWrite( Relay_PORT_J, RELAY_ON );
      break;
    }
  }
}

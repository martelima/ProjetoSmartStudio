/**
   Controlador dos dipo
*/

#define BUFFER_SIZE

enum Relay
{
  Relay_PORT_A = 5,
  Relay_PORT_B = 4,
  Relay_PORT_C = 3,
};

int state = 0;

void setup() {
  // put your setup code here, to run once:

  // ESP Comunication
  Serial.begin(9600);

  digitalWrite( 13, 1 );
  
  digitalWrite( Relay_PORT_A, LOW );
  digitalWrite( Relay_PORT_B, LOW );
  digitalWrite( Relay_PORT_C, LOW );

  delay(500);
  digitalWrite( 13, LOW );

  digitalWrite( Relay_PORT_A, HIGH );
  digitalWrite( Relay_PORT_B, HIGH );
  digitalWrite( Relay_PORT_C, HIGH );
}

void loop() {

  // Read ESP Commands
  char espCommand = '*';
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

  const char portOFF = 255;
  const char portON = 0;

  switch( command )
  {
    case 'a':
    {
      analogWrite( Relay_PORT_A, portOFF );
      break;
    }

    case 'b':
    {
      analogWrite( Relay_PORT_B, portOFF );
      break;
    }

    case 'c':
    {
      analogWrite( Relay_PORT_C, portOFF );
      break;
    }

    case 'A':
    {
      analogWrite( Relay_PORT_A, portON );
      break;
    }

    case 'B':
    {
      analogWrite( Relay_PORT_B, portON );
      break;
    }

    case 'C':
    {
      analogWrite( Relay_PORT_C, portON );
      break;
    }
  }
}

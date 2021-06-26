/**
 * Projeto: SmartStudio
 *  "Projeto de sistema para automação de estudio caseiro usando um esp8266"
 *
 * @author Mateus Lima
 */

#define MEGA_TX 13
#define MEGA_RX 15

#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>

SoftwareSerial ArduinoSerial(MEGA_TX,MEGA_RX);

// Enter your wifi network name and Wifi Password
const char* ssid = "WifiName";
const char* password = "Password";

WiFiServer server(80);

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000; // ms

// These variables store current output state of LED
String state_outputA = "off";
String outputGreenState = "off";
String outputYellowState = "off";

void setup() {
  ArduinoSerial.begin(9600);
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Conectando em ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi Conectado.");
  Serial.println("IP Endereço: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  String header;
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) { // If a new client connects,
    Serial.println("Novo cliente."); // print a message out in the serial port
    String currentLine = ""; // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      
      if (client.available()) { // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c); // print it out the serial monitor
        header += c;
        if (c == '\n') { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("Led vermelho esta ligado");
              state_outputA = "on";
              ArduinoSerial.write( "A" );
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("Led vermelho esta desligado");
              state_outputA = "off";
              ArduinoSerial.write( "a" );
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("Led verde esta ligado");
              outputGreenState = "on";
              ArduinoSerial.write( "B" );
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("Led verde esta desligado");
              outputGreenState = "off";
              ArduinoSerial.write( "b" );
            } else if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("Led amarelo esta ligado");
              outputYellowState = "on";
              ArduinoSerial.write( "C" );
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("Led amarelo esta ligado");
              outputYellowState = "off";
              ArduinoSerial.write( "c" );
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".buttonRed { background-color: #ff0000; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonGreen { background-color: #00ff00; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonYellow { background-color: #feeb36; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 16px 40px; border-radius: 70%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>SmartStudio</h1>");

            // Display current state, and ON/OFF buttons for GPIO 2 Red LED
            client.println("<p>Port A is " + state_outputA + "</p>");
            // If the state_outputA is off, it displays the OFF button
            if (state_outputA == "off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button buttonRed\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button buttonGreen\">ON</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4 Green LED
            client.println("<p>Green LED is " + outputGreenState + "</p>");
            // If the outputGreenState is off, it displays the OFF button
            if (outputGreenState == "off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button buttonGreen\">ON</button></a></p>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<p>Yellow LED is " + outputYellowState + "</p>");
            // If the outputYellowState is off, it displays the OFF button
            if (outputYellowState == "off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button buttonYellow\">ON</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') { // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

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
String state_outputB = "off";
String state_outputC = "off";
String state_outputD = "off";
String state_outputE = "off";
String state_outputF = "off";
String state_outputG = "off";
String state_outputH = "off";
String state_outputI = "off";
String state_outputJ = "off";
String state_outputK = "off";
String state_outputL = "off";
String state_outputM = "off";
String state_outputN = "off";
String state_outputO = "off";
String state_outputP = "off";

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
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("R1 esta ligado");
              state_outputA = "on";
              ArduinoSerial.write( "A" );
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("R1 esta desligado");
              state_outputA = "off";
              ArduinoSerial.write( "a" );
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("R2 esta ligado");
              state_outputB = "on";
              ArduinoSerial.write( "B" );
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("R2 esta desligado");
              state_outputB = "off";
              ArduinoSerial.write( "b" );
            } else if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("R3 esta ligado");
              state_outputC = "on";
              ArduinoSerial.write( "C" );
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("R3 esta desligado");
              state_outputC = "off";
              ArduinoSerial.write( "c" );
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("R4 esta ligado");
              state_outputD = "on";
              ArduinoSerial.write( "D" );
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("R4 esta desligado");
              state_outputD = "off";
              ArduinoSerial.write( "d" );
            } else if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("R5 esta ligado");
              state_outputE = "on";
              ArduinoSerial.write( "E" );
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("R5 esta desligado");
              state_outputE = "off";
              ArduinoSerial.write( "e" );
            } else if (header.indexOf("GET /6/on") >= 0) {
              Serial.println("R6 esta ligado");
              state_outputF = "on";
              ArduinoSerial.write( "F" );
            } else if (header.indexOf("GET /6/off") >= 0) {
              Serial.println("R6 esta desligado");
              state_outputF = "off";
              ArduinoSerial.write( "f" );
            } else if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("R6 esta ligado");
              state_outputG = "on";
              ArduinoSerial.write( "G" );
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("R7 esta desligado");
              state_outputG = "off";
              ArduinoSerial.write( "g" );
            } else if (header.indexOf("GET /8/on") >= 0) {
              Serial.println("R8 esta ligado");
              state_outputH = "on";
              ArduinoSerial.write( "H" );
            } else if (header.indexOf("GET /8/off") >= 0) {
              Serial.println("R8 esta desligado");
              state_outputH = "off";
              ArduinoSerial.write( "h" );
            } else if (header.indexOf("GET /9/on") >= 0) {
              Serial.println("R9 esta ligado");
              state_outputI = "on";
              ArduinoSerial.write( "I" );
            } else if (header.indexOf("GET /9/off") >= 0) {
              Serial.println("R9 esta desligado");
              state_outputI = "off";
              ArduinoSerial.write( "i" );
            } else if (header.indexOf("GET /10/on") >= 0) {
              Serial.println("R2 esta ligado");
              state_outputJ = "on";
              ArduinoSerial.write( "J" );
            } else if (header.indexOf("GET /10/off") >= 0) {
              Serial.println("R2 esta desligado");
              state_outputJ = "off";
              ArduinoSerial.write( "j" );
            } else if (header.indexOf("GET /11/on") >= 0) {
              Serial.println("R11 esta ligado");
              state_outputK = "on";
              ArduinoSerial.write( "K" );
            } else if (header.indexOf("GET /11/off") >= 0) {
              Serial.println("R11 esta desligado");
              state_outputK = "off";
              ArduinoSerial.write( "k" );
            } else if (header.indexOf("GET /12/on") >= 0) {
              Serial.println("R12 esta ligado");
              state_outputL = "on";
              ArduinoSerial.write( "L" );
            } else if (header.indexOf("GET /12/off") >= 0) {
              Serial.println("R12 esta desligado");
              state_outputL = "off";
              ArduinoSerial.write( "l" );
            } else if (header.indexOf("GET /13/on") >= 0) {
              Serial.println("R13 esta ligado");
              state_outputM = "on";
              ArduinoSerial.write( "M" );
            } else if (header.indexOf("GET /13/off") >= 0) {
              Serial.println("R13 esta desligado");
              state_outputM = "off";
              ArduinoSerial.write( "m" );
            } else if (header.indexOf("GET /14/on") >= 0) {
              Serial.println("R14 esta ligado");
              state_outputN = "on";
              ArduinoSerial.write( "N" );
            } else if (header.indexOf("GET /14/off") >= 0) {
              Serial.println("R14 esta desligado");
              state_outputN = "off";
              ArduinoSerial.write( "n" );
            } else if (header.indexOf("GET /15/on") >= 0) {
              Serial.println("R15 esta ligado");
              state_outputO = "on";
              ArduinoSerial.write( "O" );
            } else if (header.indexOf("GET /15/off") >= 0) {
              Serial.println("R15 esta desligado");
              state_outputO = "off";
              ArduinoSerial.write( "o" );
            } else if (header.indexOf("GET /16/on") >= 0) {
              Serial.println("R16 esta ligado");
              state_outputP = "on";
              ArduinoSerial.write( "P" );
            } else if (header.indexOf("GET /16/off") >= 0) {
              Serial.println("R16 esta desligado");
              state_outputP = "off";
              ArduinoSerial.write( "p" );
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".buttonRed { background-color: #ff0000; border: none; color: white; padding: 4px 10px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonGreen { background-color: #00ff00; border: none; color: white; padding: 4px 10px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonYellow { background-color: #feeb36; border: none; color: white; padding: 4px 10px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 4px 10px; border-radius: 70%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>SmartStudio</h1>");
            client.println("<table border=0 align=center>");

            client.println("<tr>");
            // Display current state, and ON/OFF buttons for GPIO 2 Red LED
            client.println("<td><p>R1 esta " + state_outputA + "</p>");
            // If the state_outputA is off, it displays the OFF button
            if (state_outputA == "off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4 Green LED
            client.println("<td><p>R2 esta " + state_outputB + "</p>");
            // If the state_outputB is off, it displays the OFF button
            if (state_outputB == "off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R3 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputC == "off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R4 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputD == "off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");
            client.println("</tr>");
            client.println("<tr>");
            // Display current state, and ON/OFF buttons for GPIO 2 Red LED
            client.println("<td><p>R5 esta " + state_outputA + "</p>");
            // If the state_outputA is off, it displays the OFF button
            if (state_outputE == "off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4 Green LED
            client.println("<td><p>R6 esta " + state_outputB + "</p>");
            // If the state_outputB is off, it displays the OFF button
            if (state_outputF == "off") {
              client.println("<p><a href=\"/6/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/6/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R7 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputG == "off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/7/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R8 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputH == "off") {
              client.println("<p><a href=\"/8/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");
            client.println("</tr>");
            client.println("<tr>");
            // Display current state, and ON/OFF buttons for GPIO 2 Red LED
            client.println("<td><p>R9 esta " + state_outputA + "</p>");
            // If the state_outputA is off, it displays the OFF button
            if (state_outputI == "off") {
              client.println("<p><a href=\"/9/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/9/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4 Green LED
            client.println("<td><p>R10 esta " + state_outputB + "</p>");
            // If the state_outputB is off, it displays the OFF button
            if (state_outputJ == "off") {
              client.println("<p><a href=\"/10/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/10/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R11 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputK == "off") {
              client.println("<p><a href=\"/11/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/11/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R12 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputL == "off") {
              client.println("<p><a href=\"/12/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/12/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");
            client.println("</tr>");
            client.println("<tr>");
            // Display current state, and ON/OFF buttons for GPIO 2 Red LED
            client.println("<td><p>R13 esta " + state_outputA + "</p>");
            // If the state_outputA is off, it displays the OFF button
            if (state_outputM == "off") {
              client.println("<p><a href=\"/13/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/13/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4 Green LED
            client.println("<td><p>R14 esta " + state_outputB + "</p>");
            // If the state_outputB is off, it displays the OFF button
            if (state_outputN == "off") {
              client.println("<p><a href=\"/14/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/14/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R15 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputO == "off") {
              client.println("<p><a href=\"/15/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/15/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO 5 Yellow LED
            client.println("<td><p>R16 esta " + state_outputC + "</p>");
            // If the state_outputC is off, it displays the OFF button
            if (state_outputP == "off") {
              client.println("<p><a href=\"/16/on\"><button class=\"button buttonRed\">OFF</button></a></p></td>");
            } else {
              client.println("<p><a href=\"/16/off\"><button class=\"button buttonGreen\">ON</button></a></p></td>");
            }
            client.println("</body></html>");
            client.println("</tr>");

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

/*
 Automate your krups xn 2001 machine using esp8266
 */

#include <ESP8266WiFi.h>

const char* ssid     = "YOUR WIFI SSID";
const char* password = "YOURPASSWORD";
const int NESPRESSO_POWER_BUTTON = 0;
const int NESPRESSO_COFFEE_BUTTON = 2;

const int PENDING_ACTION = 0;
const int POWER_ACTION = 1;
const int COFFEE_ACTION = 2;
const int SMALL_ACTION = 3;
const int MEDIUM_ACTION = 4;
const int LARGE_ACTION = 5;

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(NESPRESSO_POWER_BUTTON, OUTPUT);
    digitalWrite(NESPRESSO_POWER_BUTTON, HIGH);
    pinMode(NESPRESSO_COFFEE_BUTTON, OUTPUT); 
    digitalWrite(NESPRESSO_COFFEE_BUTTON, HIGH);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;
int waitressAction = PENDING_ACTION;

void loop(){
  WiFiClient client = server.available();   

  if (client) {                             
    Serial.println("New Client.");         
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {            
        char c = client.read();             
        Serial.write(c);

        if (c == '\n') {                    

          if (currentLine.length() == 0) {
            
            printMenu(client, waitressAction);

            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

        
        waitressAction = getStatus(currentLine, waitressAction);
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");


  }
  
  waitress(waitressAction);  
}

void printMenu(WiFiClient client, const int waitressAction)
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.print("<html><body><style>a{display:block;height:50px;margin:2px;font-size:60px;text-align:center;background-color:#dbdbdb;color:white;padding:100px;text-decoration:none;border-radius:5px;}</style>");

  if (PENDING_ACTION == waitressAction) {    
    client.print("<a href=\"/p\">Power</a>");
    client.print("<a href=\"/c\">Coffee</a>");
    client.print("<a href=\"/s\">Small</a>");
    client.print("<a href=\"/m\">Medium</a>");
    client.print("<a href=\"/l\">Large</a>");
  } else {
    client.print("Sorry waitress actually working, please wait<br><a href=\"/\">Refresh</a>");
  }

  client.println("<body></html>");
}

int getStatus(const String currentLine, const int waitressAction)
{
    if (currentLine.endsWith("GET /p")) {
      return POWER_ACTION;
    } else if (currentLine.endsWith("GET /c")) {
      return COFFEE_ACTION;
    } else if (currentLine.endsWith("GET /s")) {
      return SMALL_ACTION;
    } else if (currentLine.endsWith("GET /m")) {
      return MEDIUM_ACTION;
    } else if (currentLine.endsWith("GET /l")) {
      return LARGE_ACTION;
    }

    return waitressAction;
}

void waitress(const int waitressCurrentAction)
{
   if (PENDING_ACTION != waitressCurrentAction){
      Serial.print("Calling waitress with action:");
      Serial.print(waitressCurrentAction);
      server.stop();
      Serial.end();
      switch(waitressCurrentAction){
        case POWER_ACTION:
          pushButton(NESPRESSO_POWER_BUTTON);
          break;
        case COFFEE_ACTION:
          pushButton(NESPRESSO_COFFEE_BUTTON);
          break;
        case SMALL_ACTION:
          serve(15000);
          break;
        case MEDIUM_ACTION:
          serve(20000);
          break;
        case LARGE_ACTION:
          serve(25000);
          break;
      }
      server.begin();
      Serial.begin(115200);
      waitressAction = PENDING_ACTION;
   }
}

void pushButton(const int button)
{
    digitalWrite(button, LOW);
    delay(1000);
    digitalWrite(button, HIGH);
}

void serve(const int timetowait)
{
  pushButton(NESPRESSO_POWER_BUTTON);
  delay(75000);
  pushButton(NESPRESSO_COFFEE_BUTTON);
  delay(timetowait);
  pushButton(NESPRESSO_POWER_BUTTON);
}

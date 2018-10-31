#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>

WiFiClient client;
ESP8266WebServer server(80);

String Argument_Name, Clients_Response;
int flag = 0;
int pins[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8};
int s[] = {0,0,0,0,0};
char response[5][24];
int l[24][5];

volatile unsigned long t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
volatile float rpm = t3, linet = rpm/90; 
volatile int timerA = 0, timerB = 0;  

void setup() {
  for(int i = 0; i <= 5; i++)
  {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }

  attachInterrupt(digitalPinToInterrupt(D6), isr, CHANGE);

  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.setTimeout(180);
  if(!wifiManager.autoConnect("ESP8266_AP")) {
    Serial.println("failed to connect and timeout occurred");
    delay(3000);
    ESP.reset(); //reset and try again
    delay(5000);
  }
  Serial.println("WiFi connected..");
  server.begin(); Serial.println("Webserver started..."); // Start the webserver
  Serial.print("Use this URL to connect: http://");// Print the IP address
  Serial.print(WiFi.localIP());Serial.println("/");

  digitalWrite(D5, 1);
  delay(500);
  digitalWrite(D5, 0);
  
  server.on("/", HandleClient);
  while(1){
    server.handleClient();
    if (flag == 1)
    break;
  }
  for (int x = 0; x < 24; x++){
    for (int y = 0; y < 5; y++)
      l[x][y] = response[y][x] - '0';
  }
  Serial.println("POV SKETCH");
  for (int x = 0; x < 24; x++){
    for (int y = 0; y < 5; y++)
      Serial.print(l[x][y]);
    Serial.println();
  }
  digitalWrite(D5, 1);
  delay(500);
  digitalWrite(D5, 0);
    
}

void HandleClient() {
  String webpage;
  server.send(200, "text/html", webpage); // Send a response to the client asking for input*/
  if (server.args() > 0 ) { // Arguments were received
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      Serial.print(server.argName(i)); // Display the argument
      Argument_Name = server.argName(i);
      if (server.argName(i) == "user_input") {
        flag = 1;
        Serial.print(" Input received was: ");
        Serial.println(server.arg(i));
        for(int z = 0; z < 24; z++)
          response[i][z] = server.arg(i)[z];
        Clients_Response = server.arg(i);
        // e.g. range_maximum = server.arg(i).toInt();   // use string.toInt()   if you wanted to convert the input to an integer number
        // e.g. range_maximum = server.arg(i).toFloat(); // use string.toFloat() if you wanted to convert the input to a floating point number
      }
    }
  }
}

void isr(){
  if (digitalRead(D6) == HIGH) {
      
    t1 = t2;
    t2 = millis() ;
    t3 = t2 - t1;
    
    digitalWrite(pins[0],LOW);
    
    rpm = t3; linet = rpm/90; 
    timerA = millis();    
  }
  else
    digitalWrite(pins[0],HIGH);
}

void gohighlow(int a[]){
    digitalWrite(pins[5], a[0]);    
    digitalWrite(pins[4], a[1]);    
    digitalWrite(pins[3], a[2]);    
    digitalWrite(pins[2], a[3]);    
    digitalWrite(pins[1], a[4]);    
}

void loop() {
  rpm = t3, linet = rpm/90;   

  int t = millis() - timerA;

  if (t > (linet * 9) && t < (linet * 10)){
    gohighlow(l[23]);  
  }
  else if (t > (linet * 11) && t < (linet * 12)){
    gohighlow(l[22]);  
  }
  else if (t > (linet * 12) && t < (linet * 13)){
    gohighlow(l[21]);  
  }
  else if (t > (linet * 13) && t < (linet * 14)){
    gohighlow(l[20]);  
  }
  else if (t > (linet * 14) && t < (linet * 15)){
    gohighlow(l[19]);  
  }
  else if (t > (linet * 15) && t < (linet * 16)){
    gohighlow(l[18]);  
  }
  else if (t > (linet * 16) && t < (linet * 17)){
    gohighlow(l[17]);  
  }
  else if (t > (linet * 17) && t < (linet * 18)){
    gohighlow(l[16]);  
  }
  else if (t > (linet * 18) && t < (linet * 19)){
    gohighlow(l[15]);  
  }
  else if (t > (linet * 19) && t < (linet * 20)){
    gohighlow(l[14]);  
  }
  else if (t > (linet * 20) && t < (linet * 21)){
    gohighlow(l[13]);  
  }
  else if (t > (linet * 21) && t < (linet * 22)){
    gohighlow(l[12]);  
  }
  else if (t > (linet * 22) && t < (linet * 23)){
    gohighlow(l[11]);  
  }
  else if (t > (linet * 23) && t < (linet * 24)){
    gohighlow(l[10]);  
  }
  else if (t > (linet * 24) && t < (linet * 25)){
    gohighlow(l[9]);  
  }
  else if (t > (linet * 25) && t < (linet * 26)){
    gohighlow(l[8]);  
  }
  else if (t > (linet * 26) && t < (linet * 27)){
    gohighlow(l[7]);  
  }
  else if (t > (linet * 27) && t < (linet * 28)){
    gohighlow(l[6]);  
  }
  else if (t > (linet * 28) && t < (linet * 29)){
    gohighlow(l[5]);  
  }
  else if (t > (linet * 29) && t < (linet * 30)){
    gohighlow(l[4]);  
  }
  else if (t > (linet * 30) && t < (linet * 31)){
    gohighlow(l[3]);  
  }
  else if (t > (linet * 31) && t < (linet * 32)){
    gohighlow(l[2]);  
  }
  else if (t > (linet * 32) && t < (linet * 33)){
    gohighlow(l[1]);  
  }
  else if (t > (linet * 33) && t < (linet * 34)){
    gohighlow(l[0]);  
  }
  else
    gohighlow(s);         
}


#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define Hall_Sensor A0          //A0 used with analog output, D2 with digital output
#define Hall_Sensor_D 2

int Val1=0,Val2=0;   

WiFiClient client;

long myChannelNumber = 1792385;
const char myWriteAPIKey[] = "WMBURB6L80RO368X";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Hall_Sensor_D,INPUT);
  WiFi.begin("Bhuvan", "password");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
//  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
   Val1=analogRead(Hall_Sensor);            //We read both values and display them raw on the serial monitor
   Serial.print(Val1);
   Val2=digitalRead(Hall_Sensor_D);
   Serial.println("Analog Val", Val1);
   Serial.println("Digital Val",Val2);
   ThingSpeak.writeField(myChannelNumber, 1, Val1, myWriteAPIKey);
   ThingSpeak.writeField(myChannelNumber, 2, Val2, myWriteAPIKey);
   delay(2000);
}

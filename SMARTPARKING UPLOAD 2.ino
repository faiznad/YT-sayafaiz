
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "-oo7FYV4AnhYtY3Nu65NZESd8KbhFWNm";
char ssid[] = "g";
char pass[] = "ggjhfa12";
WidgetLED led1(V1);


int sensor =D4;

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(sensor,INPUT);
  while(Blynk.connect() == false){
    Serial.println("tidak terdeteksi");
  }
  
}

void loop()
{
  int sensorval1 = digitalRead(sensor);
  delay(1000);
  
  if (sensorval1 ==1){
    led1.on();
  }
  if (sensorval1 ==0){
    led1.off();
  }
  
  Blynk.run();
}

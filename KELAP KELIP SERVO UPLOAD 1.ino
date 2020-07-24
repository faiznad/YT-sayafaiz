
#define BLYNK_PRINT Serial

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo servo;
char auth[] = "1eTy7cTX8lcEg2LKQACpqgTF9dppb9Y4";
char ssid[] = "ZTE_2.4G_4hrGUt";
char pass[] = "Amp7Qefm";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(16); 
}

void loop(){
  Blynk.run(); 
}
BLYNK_WRITE(V1) {
  servo.write(param.asInt());
}

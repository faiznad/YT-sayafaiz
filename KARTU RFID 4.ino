#include <dummy.h>

#include "DHT.h"
#include "UbidotsMicroESP8266.h"
#define DHTPIN 4
#define TOKEN "BBFF-Rh64hdFyQ6q1HnCJqXfXEA7YFvjmq7"
#define ssid "Upi"
#define psswd "wlan4843ef"
DHT dht (DHTPIN, DHT11);
Ubidots client(TOKEN);
unsigned long last =0;

void setup(){
  Serial.begin(9600)
  
  dht.begin();
  
  delay(20);
  
  client.wifiConnection(ssid,psswd);
  
}

void loop(){
  if (millis()-last>1000){
    float hum = dht.readHumidity();

    float temp = dht.readTemperature();

    last=millis();

    client.add("kelembapan" ,hum);

    client.add("Temp" ,temp);

    client.sendAll(true);
  }
}

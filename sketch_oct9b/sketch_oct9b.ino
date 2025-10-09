#include <Bonezegei_DHT22.h>

//param (2) = pin used for data
Bonezegei_DHT22 dht(2);
// millis zone
unsigned long ms_from_start = 0;
unsigned long ms_from_start = 0;

void setup() {

  Serial.begin(9600);
  dht.begin();

}

void loop() {
  
  ms_from_start = millis();

  if (dht.getData()) {
    
    // get temperatur in celsius
    float tempDeg = dht.getTemperature();
    // get humidity
    int hum = dht.getHumidity();

    // Print output
    Serial.print("Success : ");
    Serial.println(ms_from_start);
    Serial.print("temp : ");
    Serial.println(tempDeg);
    Serial.print("hum : ");
    Serial.println(hum);

  }

  else {

    Serial.print("Fail unable to get data : ");
    Serial.println(ms_from_start);

  }

}

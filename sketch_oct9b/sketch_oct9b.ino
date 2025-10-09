#include <Bonezegei_DHT22.h>

//param (2) = pin used for data
Bonezegei_DHT22 dht(2);
// millis zone
unsigned long ms_from_start = 0;
unsigned long ms_from_start_looped = 0;

void setup() {

  Serial.begin(9600);
  dht.begin();

  ms_from_start = millis();

}

void loop() {
  
  ms_from_start_looped = millis();

  if (dht.getData()) {
    
    // get temperatur in celsius
    float tempDeg = dht.getTemperature();
    // get humidity
    int hum = dht.getHumidity();

    // Print output
    Serial.printfln("Success, %0.1lf, %d", tempDeg, hum);
    Serial.printfln(ms_from_start);
    Serial.printfln(ms_from_start_looped);

  }

  else {
    Serial.printfln("Fail unable to get data")
    Serial.printfln(ms_from_start);
    Serial.printfln(ms_from_start_looped);
  }

}

#include <Bonezegei_DHT22.h>

//param (2) = pin used for data
Bonezegei_DHT22 dht(2);

// millis zone
unsigned long ms_from_start = 0;
unsigned long last_read = 0;
unsigned long interval = 5000;

void setup() {

  Serial.begin(115200);
  dht.begin();

}

void loop() {
  
  ms_from_start = millis();

  if (ms_from_start - last_read >= interval) 
  {

    last_read = ms_from_start;

    if (dht.getData()) {
    
    // get temperatur in celsius
    float tempDeg = dht.getTemperature();
    // get humidity
    float hum = dht.getHumidity();

    // Print output
    Serial.print("{\"deviceID\":\"jla-01\",\"sensor\":\"DHT22\",");
    Serial.print("\"ok\":true");
    Serial.print(",\"temp_c\":");
    Serial.print(tempDeg, 1);
    Serial.print(",\"hum\":");
    Serial.print(hum, 1);
    Serial.print(",\"ts_ms\":");
    Serial.print(ms_from_start);
    Serial.println("}");

    }

    else {

      Serial.print("{\"sensor\":\"just 1 liam\",");
      Serial.print("\"ok\":false,");
      Serial.print("\"error\":\"Unable to retrieve data\"");
      Serial.print(",\"ts_ms\":");
      Serial.print(ms_from_start);
      Serial.println("}");

    }

  }

}

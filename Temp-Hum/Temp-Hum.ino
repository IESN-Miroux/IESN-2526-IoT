#include <Bonezegei_DHT22.h>

#define PIN 11
#define LED 6

//param (2) = pin used for data
Bonezegei_DHT22 dht(2);

// millis zone
unsigned long ms_from_start = 0;
unsigned long last_read = 0;
unsigned long interval = 5000;

float control = 255;
float tempDeg = 0;

int tempDeg100 = 0;

void setup() {

  pinMode(PIN, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  dht.begin();

}


// Set variables used for serial com
String Buffer = "";


void loop() {

  if (Serial.available() > 0) {

    Buffer = "";
    Buffer = Serial.readStringUntil('\n');
    Serial.flush();
    Buffer = Buffer.substring(0,4);
    
  }

  if (Buffer == "over") {
    control = 255;
  }

  else if (Buffer == "unde") {
    control = 0;
  }
  
  analogWrite(PIN, control);

  ms_from_start = millis();

  if (ms_from_start - last_read >= interval) 
  {

    last_read = ms_from_start;

    if (dht.getData()) {
    
    // get temperatur in celsius
    tempDeg = dht.getTemperature();
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

      Serial.print("{\"deviceID\":\"jla-01\",\"sensor\":\"DHT22\",");
      Serial.print("\"ok\":false,");
      Serial.print("\"error\":\"Unable to retrieve data\"");
      Serial.print(",\"ts_ms\":");
      Serial.print(ms_from_start);
      Serial.println("}");

    }

    tempDeg100 = tempDeg * 10;

    unsigned int tempvalue = map(tempDeg100, 220, 235, 0, 255);
    analogWrite(LED, tempvalue);

  }

}

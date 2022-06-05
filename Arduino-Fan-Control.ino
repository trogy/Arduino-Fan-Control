#include <OneWire.h>
#include <DallasTemperature.h>

const int RELAY_PIN = 3;
const int TEMP_SETPOINT = 23;
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);  

DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.print("Temp Setpoint:");
  Serial.print(TEMP_SETPOINT);
  Serial.print("\n");
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(" C");
  Serial.print("\n");
  if(sensors.getTempCByIndex(0) > TEMP_SETPOINT){
    digitalWrite(RELAY_PIN, HIGH);
  }
  else{
    digitalWrite(RELAY_PIN, LOW);
  }
  delay(500);
}

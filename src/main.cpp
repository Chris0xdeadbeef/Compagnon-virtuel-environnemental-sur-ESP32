#include <Arduino.h>
#include "Config.h"
#include "Sensors.h"
#include "Types.h"

EnvironmentalData environmentalData;

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    if (!initSensors())
    {
        Serial.println("Erreur initialisation capteurs");

        while (true) {}
    }
}

void loop()
{
    updateSensors(environmentalData);

    Serial.print("Temperature: ");
    Serial.print(environmentalData.temperature);
    Serial.println(" C");

    Serial.print("Humidite: ");
    Serial.print(environmentalData.humidity);
    Serial.println(" %");

    Serial.print("Nuit: ");
    Serial.println(environmentalData.isNight);

    delay(300);
}
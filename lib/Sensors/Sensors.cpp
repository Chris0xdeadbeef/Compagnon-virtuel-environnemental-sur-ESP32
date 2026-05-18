/**
 * @file Sensors.cpp
 * @brief Implémentation de la gestion des capteurs.
 */

#include "Sensors.h"
#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include "../../include/Config.h"

/**
 * @brief Instance du capteur environnemental SCD30.
 */
SCD30 airSensor;

bool initSensors()
{
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

    if (!airSensor.begin())
    {
        return false;
    }

    pinMode(LIGHT_SENSOR_D0_PIN, INPUT);

    return true;
}

void updateSensors(EnvironmentalData& data)
{
    if (airSensor.dataAvailable())
    {
        data.temperature = airSensor.getTemperature() + TEMPERATURE_OFFSET;
        data.humidity = airSensor.getHumidity() + HUMIDITY_OFFSET;
    }

    data.isNight = digitalRead(LIGHT_SENSOR_D0_PIN);
}
/**
 * @file Sensors.cpp
 * @brief Implémentation de la gestion des capteurs.
 */

#include "Sensors.h"
#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_SCD4x_Arduino_Library.h>
#include "Config.h"

/**
 * @brief Instance du capteur environnemental SCD40.
 */
SCD4x airSensor;

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
    if (airSensor.readMeasurement())
    {
        data.temperature = airSensor.getTemperature();
        data.humidity = airSensor.getHumidity();
    }

    data.isNight = digitalRead(LIGHT_SENSOR_D0_PIN);
}
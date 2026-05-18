/**
 * @file main.cpp
 * @brief Point d'entrée principal du projet.
 */

#include <Arduino.h>

#include "AnimationManager.h"
#include "DisplayManager.h"
#include "Sensors.h"
#include "SpriteManager.h"
#include "StateResolver.h"
#include "Config.h"
#include "Types.h"

/**
 * @brief Données environnementales globales.
 */
EnvironmentalData environmentalData;

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    if (!initSensors())
    {
        Serial.println(
            "Erreur initialisation capteurs");

        while (true)
        {
        }
    }

    if (!initSprites())
    {
        Serial.println(
            "Erreur initialisation SPIFFS");

        while (true)
        {
        }
    }

    initDisplay();

    Serial.println("Systeme pret");
}

void loop()
{
    updateSensors(environmentalData);

    const TemperatureState
        temperatureState =
            resolveTemperatureState(
                environmentalData.temperature);

    const HumidityState
        humidityState =
            resolveHumidityState(
                environmentalData.humidity);

    const LightState
        lightState =
            resolveLightState(
                environmentalData.isNight);

    const SpriteState spriteState
    {
        temperatureState,
        humidityState,
        lightState
    };

    Serial.print("Temperature: ");
    Serial.print(environmentalData.temperature);
    Serial.println(" C");

    Serial.print("Humidite: ");
    Serial.print(environmentalData.humidity);
    Serial.println(" %");

    Serial.print("Nuit: ");
    Serial.println(environmentalData.isNight);

    playAnimation(spriteState);
}
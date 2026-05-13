/**
 * @file Types.h
 * @brief Types utilisés pour les états environnementaux et les données capteurs.
 */

#pragma once

/**
 * @brief États possibles de la température.
 */
enum class TemperatureState
{
    COLD,
    NORMAL,
    HOT
};

/**
 * @brief États possibles de l'humidité.
 */
enum class HumidityState
{
    DRY,
    NORMAL,
    WET
};

/**
 * @brief États possibles de la luminosité.
 */
enum class LightState
{
    DAY,
    NIGHT
};

/**
 * @brief Données environnementales mesurées par les capteurs.
 */ 
struct EnvironmentalData
{
    /**
     * @brief Température mesurée en degrés Celsius.
     */
    float temperature;

    /**
     * @brief Humidité mesurée en pourcentage.
     */
    float humidity;

    /**
     * @brief Valeur logique de luminosité mesurée.
     */
    bool isNight;
};
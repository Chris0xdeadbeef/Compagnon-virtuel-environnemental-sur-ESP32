// lib/StateResolver/StateResolver.cpp

/**
 * @file StateResolver.cpp
 * @brief Implémentation de la résolution des états.
 */

#include "StateResolver.h"

#include "../../include/Config.h"

TemperatureState resolveTemperatureState(const float temperature)
{
    if (temperature < TEMP_COLD_MAX)
    {
        return TemperatureState::COLD;
    }

    if (temperature > TEMP_HOT_MIN)
    {
        return TemperatureState::HOT;
    }

    return TemperatureState::NORMAL;
}

HumidityState resolveHumidityState(const float humidity)
{
    if (humidity < HUMIDITY_DRY_MAX)
    {
        return HumidityState::DRY;
    }

    if (humidity > HUMIDITY_WET_MIN)
    {
        return HumidityState::WET;
    }

    return HumidityState::NORMAL;
}

LightState resolveLightState(const bool isNight)
{
    return isNight ? LightState::NIGHT : LightState::DAY;
}
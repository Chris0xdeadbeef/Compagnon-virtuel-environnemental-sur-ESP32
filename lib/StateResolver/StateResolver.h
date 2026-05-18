/**
 * @file StateResolver.h
 * @brief Résolution des états environnementaux.
 */

#pragma once

#include "../../include/Types.h"

/**
 * @brief Résout l'état de température.
 *
 * @param temperature Température mesurée.
 * @return TemperatureState état correspondant.
 */
[[nodiscard]] TemperatureState resolveTemperatureState(const float temperature);

/**
 * @brief Résout l'état d'humidité.
 *
 * @param humidity Humidité mesurée.
 * @return HumidityState état correspondant.
 */
[[nodiscard]] HumidityState resolveHumidityState(const float humidity);

/**
 * @brief Résout l'état de luminosité.
 *
 * @param isNight Indique si la luminosité est faible.
 * @return LightState état correspondant.
 */
[[nodiscard]] LightState resolveLightState(const bool isNight);
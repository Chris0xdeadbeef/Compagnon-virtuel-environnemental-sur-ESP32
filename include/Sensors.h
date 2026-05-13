/**
 * @file Sensors.h
 * @brief Interface de gestion des capteurs
 */

#pragma once

#include "Types.h"

/**
 * @brief Initialise les capteurs du système.
 * 
 * @return true Initialisation réussie.
 * @return false Échec de l'initialisation.
 */
[[nodiscard]] bool initSensors();

/**
 * @brief Met à jour les données environnementales.
 * 
 * @param data Structure contenant les données des capteurs.
 */
void updateSensors(EnvironmentalData& data);
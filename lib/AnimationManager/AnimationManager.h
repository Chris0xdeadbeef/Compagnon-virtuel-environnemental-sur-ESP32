/**
 * @file AnimationManager.h
 * @brief Gestion des animations du compagnon.
 */

#pragma once

#include "../../include/Types.h"


/**
 * @brief Représente un état complet du compagnon.
 */
struct SpriteState
{
    TemperatureState temperatureState;
    HumidityState humidityState;
    LightState lightState;

    /**
     * @brief Compare deux états.
     *
     * @param other État à comparer.
     * @return true états identiques.
     * @return false états différents.
     */
    [[nodiscard]] bool operator==(const SpriteState &other) const;
};

/**
 * @brief Groupe d’animations associé à un état.
 */
struct FrameGroup
{
    SpriteState state;

    const char* frames[3];
};

/**
 * @brief Retourne le groupe correspondant à un état.
 *
 * @param state État recherché.
 * @return const FrameGroup* Groupe trouvé.
 * @return nullptr Aucun groupe trouvé.
 */
[[nodiscard]] const FrameGroup* findFrameGroup(const SpriteState &state);

/**
 * @brief Joue l’animation associée à un état.
 *
 * @param state État du compagnon.
 */
void playAnimation(const SpriteState &state);
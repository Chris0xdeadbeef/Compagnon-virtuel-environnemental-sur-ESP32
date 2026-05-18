/**
 * @file AnimationManager.cpp
 * @brief Implémentation des animations.
 */

#include <Arduino.h>
#include "AnimationManager.h"
#include "SpriteManager.h"


/**
 * @brief Table de vérité des animations.
 */
constexpr FrameGroup FRAME_GROUPS[] =
    {
        // -------- COLD --------

        {{TemperatureState::COLD, HumidityState::DRY, LightState::NIGHT},
         {"/cold/cold_dry_night_0.bin",
          "/cold/cold_dry_night_1.bin",
          "/cold/cold_dry_night_2.bin"}},

        {{TemperatureState::COLD, HumidityState::DRY, LightState::DAY},
         {"/cold/cold_dry_day_0.bin",
          "/cold/cold_dry_day_1.bin",
          "/cold/cold_dry_day_2.bin"}},

        {{TemperatureState::COLD, HumidityState::NORMAL, LightState::NIGHT},
         {"/cold/cold_normal_night_0.bin",
          "/cold/cold_normal_night_1.bin",
          "/cold/cold_normal_night_2.bin"}},

        {{TemperatureState::COLD, HumidityState::NORMAL, LightState::DAY},
         {"/cold/cold_normal_day_0.bin",
          "/cold/cold_normal_day_1.bin",
          "/cold/cold_normal_day_2.bin"}},

        {{TemperatureState::COLD, HumidityState::WET, LightState::NIGHT},
         {"/cold/cold_wet_night_0.bin",
          "/cold/cold_wet_night_1.bin",
          "/cold/cold_wet_night_2.bin"}},

        {{TemperatureState::COLD, HumidityState::WET, LightState::DAY},
         {"/cold/cold_wet_day_0.bin",
          "/cold/cold_wet_day_1.bin",
          "/cold/cold_wet_day_2.bin"}},

        // -------- NORMAL --------

        {{TemperatureState::NORMAL, HumidityState::DRY, LightState::NIGHT},
         {"/normal/normal_dry_night_0.bin",
          "/normal/normal_dry_night_1.bin",
          "/normal/normal_dry_night_2.bin"}},

        {{TemperatureState::NORMAL, HumidityState::DRY, LightState::DAY},
         {"/normal/normal_dry_day_0.bin",
          "/normal/normal_dry_day_1.bin",
          "/normal/normal_dry_day_2.bin"}},

        {{TemperatureState::NORMAL, HumidityState::NORMAL, LightState::NIGHT},
         {"/normal/normal_normal_n_0.bin",
          "/normal/normal_normal_n_1.bin",
          "/normal/normal_normal_n_2.bin"}},

        {{TemperatureState::NORMAL, HumidityState::NORMAL, LightState::DAY},
         {"/normal/normal_normal_day_0.bin",
          "/normal/normal_normal_day_1.bin",
          "/normal/normal_normal_day_2.bin"}},

        {{TemperatureState::NORMAL, HumidityState::WET, LightState::NIGHT},
         {"/normal/normal_wet_night_0.bin",
          "/normal/normal_wet_night_1.bin",
          "/normal/normal_wet_night_2.bin"}},

        {{TemperatureState::NORMAL, HumidityState::WET, LightState::DAY},
         {"/normal/normal_wet_day_0.bin",
          "/normal/normal_wet_day_1.bin",
          "/normal/normal_wet_day_2.bin"}},

        // -------- HOT --------

        {{TemperatureState::HOT, HumidityState::DRY, LightState::NIGHT},
         {"/hot/hot_dry_night_0.bin",
          "/hot/hot_dry_night_1.bin",
          "/hot/hot_dry_night_2.bin"}},

        {{TemperatureState::HOT, HumidityState::DRY, LightState::DAY},
         {"/hot/hot_dry_day_0.bin",
          "/hot/hot_dry_day_1.bin",
          "/hot/hot_dry_day_2.bin"}},

        {{TemperatureState::HOT, HumidityState::NORMAL, LightState::NIGHT},
         {"/hot/hot_normal_night_0.bin",
          "/hot/hot_normal_night_1.bin",
          "/hot/hot_normal_night_2.bin"}},

        {{TemperatureState::HOT, HumidityState::NORMAL, LightState::DAY},
         {"/hot/hot_normal_day_0.bin",
          "/hot/hot_normal_day_1.bin",
          "/hot/hot_normal_day_2.bin"}},

        {{TemperatureState::HOT, HumidityState::WET, LightState::NIGHT},
         {"/hot/hot_wet_night_0.bin",
          "/hot/hot_wet_night_1.bin",
          "/hot/hot_wet_night_2.bin"}},

        {{TemperatureState::HOT, HumidityState::WET, LightState::DAY},
         {"/hot/hot_wet_day_0.bin",
          "/hot/hot_wet_day_1.bin",
          "/hot/hot_wet_day_2.bin"}}
    };

bool SpriteState::operator==(const SpriteState &other) const
{
    return temperatureState == other.temperatureState &&
           humidityState == other.humidityState &&
           lightState == other.lightState;
}

constexpr size_t FRAME_GROUP_COUNT = sizeof(FRAME_GROUPS) / sizeof(FRAME_GROUPS[0]);

const FrameGroup *findFrameGroup(const SpriteState &state)
{
    for (const auto &frameGroup : FRAME_GROUPS)
    {
        if (frameGroup.state == state)
        {
            return &frameGroup;
        }
    }

    return nullptr;
}

void playAnimation(const SpriteState &state)
{
    const FrameGroup *frameGroup =
        findFrameGroup(state);

    if (frameGroup == nullptr)
    {
        Serial.println(
            "Aucun groupe d'animation trouvé");

        return;
    }

    for (uint8_t i = 0; i < 3; ++i)
    {
        drawSprite(frameGroup->frames[i]);
    }
}
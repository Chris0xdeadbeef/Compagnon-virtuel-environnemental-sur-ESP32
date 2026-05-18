/**
 * @file SpriteManager.cpp
 * @brief Implémentation de la gestion des sprites.
 */

#include "SpriteManager.h"

#include <Arduino.h>
#include <SPIFFS.h>
#include "../../include/Config.h"
#include "DisplayManager.h"

static uint16_t lineBuffer[SPRITE_WIDTH];

bool initSprites()
{
    return SPIFFS.begin(true);
}

void drawSprite(const char* filename)
{
    File file = SPIFFS.open(filename, "r");

    if (!file)
    {
        Serial.println("Erreur ouverture sprite");
        return;
    }

    file.seek(4);

    tft.startWrite();

    for (uint16_t y = 0; y < SPRITE_HEIGHT; ++y)
    {
        file.read(
            reinterpret_cast<uint8_t*>(lineBuffer),
            SPRITE_WIDTH * sizeof(uint16_t));

        tft.setAddrWindow(
            SPRITE_X_OFFSET,
            SPRITE_Y_OFFSET + y,
            SPRITE_X_OFFSET + SPRITE_WIDTH - 1,
            SPRITE_Y_OFFSET + y);

        tft.writePixels(lineBuffer, SPRITE_WIDTH);
    }

    tft.endWrite();

    file.close();
}
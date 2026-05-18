/**
 * @file SpriteManager.h
 * @brief Gestion des sprites RGB565 stockés dans SPIFFS.
 */

#pragma once

/**
 * @brief Initialise SPIFFS.
 *
 * @return true Initialisation réussie.
 * @return false Échec de l'initialisation.
 */
[[nodiscard]] bool initSprites();

/**
 * @brief Affiche un sprite RGB565 depuis SPIFFS.
 *
 * @param filename Chemin du fichier sprite.
 */
void drawSprite(const char* filename);
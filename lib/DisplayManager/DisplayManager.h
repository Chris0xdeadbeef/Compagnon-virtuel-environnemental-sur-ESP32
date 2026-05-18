/**
 * @file DisplayManager.h
 * @brief Gestion de l'écran TFT ST7735.
 */

#pragma once

#include <Adafruit_ST7735.h>

/**
 * @brief Instance globale de l'écran TFT.
 */
extern Adafruit_ST7735 tft;

/**
 * @brief Initialise l'écran TFT.
 */
void initDisplay();

/**
 * @brief Nettoie complètement la mémoire graphique du ST7735.
 * @details L'écran est 128x160, mais le contrôleur ST7735 dispose d'une GRAM
 *          de 132x162 pixels. INITR_BLACKTAB applique un offset matériel de (2,1)
 *          qui décale la fenêtre d'adressage Adafruit, laissant les bords droit
 *          et bas non initialisés. Cette fonction adresse directement toute la
 *          GRAM du contrôleur via SPI pour les couvrir.
 * @note    À appeler une seule fois dans setup(), juste après initR().
 */
void clearFullDisplay();
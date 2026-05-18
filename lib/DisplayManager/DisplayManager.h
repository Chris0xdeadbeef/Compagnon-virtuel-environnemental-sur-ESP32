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
 */
void clearFullDisplay();
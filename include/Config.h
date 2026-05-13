#pragma once

#include <Arduino.h>

/**
 * @file Config.h
 * @brief Configuration globale du projet.
 * @brief Débit de communication série UART.
 */
constexpr uint32_t SERIAL_BAUD_RATE = 115200;

// --------------
// TFT ST7735
// --------------

/**
 * @brief Pin Chip Select du TFT ST7735.
 */
constexpr uint8_t TFT_CS_PIN = 5;

/**
 * @brief Pin Data/Command du TFT ST7735.
 */
constexpr uint8_t TFT_DC_PIN = 16;

/**
 * @brief Pin Reset du TFT ST7735.
 */
constexpr uint8_t TFT_RST_PIN = 4;

/**
 * @brief Pin SPI Clock du TFT ST7735.
 */
constexpr uint8_t TFT_SCK_PIN = 18;

/**
 * @brief Pin SPI MOSI du TFT ST7735.
 */
constexpr uint8_t TFT_MOSI_PIN = 23;

// --------------
// I2C SCD40
// --------------

/**
 * @brief Pin SDA du bus I2C.
 */
constexpr uint8_t I2C_SDA_PIN = 27;

/**
 * @brief Pin SCL du bus I2C.
 */
constexpr uint8_t I2C_SCL_PIN = 14;

// --------------
// Capteur de lumière
// --------------

/**
 * @brief Pin digitale du capteur de lumière.
 */
constexpr uint8_t LIGHT_SENSOR_D0_PIN = 32;

// --------------
// Écran
// --------------

/**
 * @brief Largeur de l'écran TFT en pixels.
 */
constexpr uint16_t SCREEN_WIDTH = 128;

/**
 * @brief Hauteur de l'écran TFT en pixels.
 */
constexpr uint16_t SCREEN_HEIGHT = 160;

/**
 * @brief Largeur des sprites en pixels.
 */
constexpr uint16_t SPRITE_WIDTH = 128;

/**
 * @brief Hauteur des sprites en pixels.
 */
constexpr uint16_t SPRITE_HEIGHT = 128;

/**
 * @brief Offset horizontal des sprites.
 */
constexpr uint8_t SPRITE_X_OFFSET = 2;

/**
 * @brief Offset vertical des sprites.
 */
constexpr uint8_t SPRITE_Y_OFFSET = 10;

// --------------
// Couleurs
// --------------

/**
 * @brief Couleur de fond principale au format RGB565.
 */
constexpr uint16_t BACKGROUND_COLOR = 0xEE31;

// --------------
// Seuils température
// --------------

/**
 * @brief Température maximale avant état froid.
 */
constexpr float TEMP_COLD_MAX = 18.0f;

/**
 * @brief Température minimale avant état chaud.
 */
constexpr float TEMP_HOT_MIN = 25.0f;

// --------------
// Seuils humidité
// --------------

/**
 * @brief Humidité maximale avant état sec.
 */
constexpr float HUMIDITY_DRY_MAX = 40.0f;

/**
 * @brief Humidité minimale avant état très humide.
 */
constexpr float HUMIDITY_WET_MIN = 60.0f;

// --------------
// Seuils luminosité
// --------------

/**
 * @brief Valeur correspondant à l'état nuit.
 */
constexpr uint8_t LIGHT_DARK_STATE = HIGH;

/**
 * @brief Valeur correspondant à l'état jour.
 */
constexpr uint8_t LIGHT_BRIGHT_STATE = LOW;

// --------------
// Animation
// --------------

/**
 * @brief Nombre de frames par animation.
 */
constexpr uint8_t ANIMATION_FRAME_COUNT = 3;

/**
 * @brief Temps entre deux frames en millisecondes.
 */
constexpr uint16_t FRAME_DELAY_MS = 15;
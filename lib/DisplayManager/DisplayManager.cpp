/**
 * @file DisplayManager.cpp
 * @brief Implémentation de la gestion de l'écran TFT.
 */

#include <SPI.h>
#include "DisplayManager.h"
#include "../../include/Config.h"

Adafruit_ST7735 tft(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);

void initDisplay()
{
    SPI.begin(
        TFT_SCK_PIN,
        -1,
        TFT_MOSI_PIN,
        TFT_CS_PIN);

    tft.initR(INITR_BLACKTAB);

    clearFullDisplay();
    tft.fillScreen(BACKGROUND_COLOR);
}

void clearFullDisplay()
{
    tft.startWrite();

    tft.writeCommand(ST77XX_CASET);

    tft.SPI_WRITE16(0x0000);
    tft.SPI_WRITE16(0x0083);

    tft.writeCommand(ST77XX_RASET);

    tft.SPI_WRITE16(0x0000);
    tft.SPI_WRITE16(0x00A1);

    tft.writeCommand(ST77XX_RAMWR);

    for (uint32_t i = 0; i < 132 * 162; ++i)
    {
        tft.SPI_WRITE16(BACKGROUND_COLOR);
    }

    tft.endWrite();
}
/**
 * @file board_diy_esp32s3_st7789_1.9.h
 * Board definition: DIY ESP32-S3 + ST7789 1.9" + 6 Buttons + CC1101 + SPI MicroSD
 *
 * MCU:      ESP32-S3 (preferably N16R8 — 16MB Flash + 8MB PSRAM)
 * Display:  ST7789 320×170 RGB565 via SPI
 * Input:    6× tactile buttons (active-low to GND)
 * SubGHz:   external CC1101 via SPI3
 * NFC:      external PN532 via I2C (optional)
 * SD Card:  SPI MicroSD module (CS/SCK/MOSI/MISO)
 * IR:       TX only
 * RGB LED:  WS2812 ×1
 *
 * Pinout designed for common DIY breadboard / protoboard builds.
 * SD module is the standard SPI MicroSD adapter (VCC/GND/MISO/MOSI/SCK/CS).
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "DIY ESP32-S3 ST7789 1.9\""
#define BOARD_ID          "diy-st7789-1.9"
#define BOARD_TARGET      "esp32s3"

/* ---- Hardware Button Pins (active-low, internal pull-up) ---- */
#define BOARD_PIN_BTN_UP        41
#define BOARD_PIN_BTN_DOWN      40
#define BOARD_PIN_BTN_LEFT      38
#define BOARD_PIN_BTN_RIGHT     39
#define BOARD_PIN_BTN_OK        0
#define BOARD_PIN_BTN_BACK      4
#define BOARD_PIN_BUTTON_BOOT   0
#define BOARD_PIN_BATTERY_ADC   2   /* optional voltage divider on GPIO2 */

/* ---- LCD Pins (ST7789 via SPI2) ---- */
#define BOARD_PIN_LCD_MOSI      17
#define BOARD_PIN_LCD_SCLK      18
#define BOARD_PIN_LCD_DC        15
#define BOARD_PIN_LCD_CS        7
#define BOARD_PIN_LCD_RST       16
#define BOARD_PIN_LCD_BL        6

/* ---- LCD Display Configuration (ST7789 1.9\" 320×170) ---- */
#define BOARD_LCD_H_RES         320
#define BOARD_LCD_V_RES         170
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (40 * 1000 * 1000)
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       true
#define BOARD_LCD_MIRROR_X      false
#define BOARD_LCD_MIRROR_Y      true
#define BOARD_LCD_INVERT_COLOR  true
#define BOARD_LCD_GAP_X         0
#define BOARD_LCD_GAP_Y         35
#define BOARD_LCD_BL_ACTIVE_LOW false
#define BOARD_LCD_COLOR_ORDER_BGR false

/* Flipper framebuffer → display color mapping (RGB565) */
#define BOARD_LCD_FG_COLOR      0xA0FD  /* Flipper Orange */
#define BOARD_LCD_FG_COLOR_RB   0x5F03
#define BOARD_LCD_BG_COLOR      0x0000  /* Black */

/* ---- SD Card Pins (standard SPI MicroSD module, shared SPI2 with LCD) ---- */
#define BOARD_PIN_SD_CS         3
#define BOARD_PIN_SD_MISO       8
#define BOARD_PIN_SD_MOSI       17   /* shared with LCD MOSI */
#define BOARD_PIN_SD_SCLK       18   /* shared with LCD SCLK */

/* ---- Touch Controller — NOT PRESENT ---- */
#define BOARD_PIN_TOUCH_SCL     UINT16_MAX
#define BOARD_PIN_TOUCH_SDA     UINT16_MAX
#define BOARD_PIN_TOUCH_RST     UINT16_MAX
#define BOARD_PIN_TOUCH_INT     UINT16_MAX
#define BOARD_TOUCH_I2C_ADDR    0x00
#define BOARD_TOUCH_I2C_PORT    I2C_NUM_0
#define BOARD_TOUCH_I2C_FREQ_HZ 0
#define BOARD_TOUCH_I2C_TIMEOUT 0

/* ---- SubGHz / CC1101 (dedicated SPI3) ---- */
#define BOARD_PIN_CC1101_SCK    13
#define BOARD_PIN_CC1101_CSN    46
#define BOARD_PIN_CC1101_MISO   11
#define BOARD_PIN_CC1101_MOSI   12
#define BOARD_PIN_CC1101_GDO0   9
#define BOARD_PIN_CC1101_GDO2   10
#define BOARD_CC1101_SPI_HOST   SPI3_HOST
#define BOARD_CC1101_SPI_SHARED 0

/* ---- NRF24L01 (optional, same SPI3 bus as CC1101) ---- */
#define BOARD_PIN_NRF24_SCK     13
#define BOARD_PIN_NRF24_MISO    11
#define BOARD_PIN_NRF24_MOSI    12
#define BOARD_PIN_NRF24_CSN     14
#define BOARD_PIN_NRF24_CE      21
#define BOARD_HAS_NRF24         1

/* ---- IR ---- */
#define BOARD_PIN_IR_TX         5
#define BOARD_PIN_IR_RX         UINT16_MAX

/* ---- NFC / PN532 (I2C) ---- */
#define BOARD_PIN_NFC_SCL       42
#define BOARD_PIN_NFC_SDA       47
#define BOARD_NFC_I2C_PORT      I2C_NUM_0

/* ---- Speaker / Mic — not present by default ---- */
#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX

/* ---- WS2812 RGB LED ---- */
#define BOARD_PIN_WS2812_DATA   48
#define BOARD_WS2812_LED_COUNT  1

/* ---- Qwiic / External I2C (shared with NFC) ---- */
#define BOARD_PIN_QWIIC_SDA     47
#define BOARD_PIN_QWIIC_SCL     42

/* ---- Features ---- */
#define BOARD_HAS_TOUCH         0
#define BOARD_HAS_ENCODER       0
#define BOARD_HAS_SD_CARD       1
#define BOARD_HAS_BLE           1
#define BOARD_HAS_RGB_LED       1
#define BOARD_HAS_VIBRO         0
#define BOARD_HAS_SPEAKER       0
#define BOARD_HAS_IR            1
#define BOARD_HAS_IBUTTON       0
#define BOARD_HAS_RFID          0
#define BOARD_HAS_NFC           1
#define BOARD_HAS_SUBGHZ        1
#define BOARD_HAS_MIC           0

/* ---- RFID (optional UART) ---- */
#define BOARD_PIN_RFID_RX       44
#define BOARD_PIN_RFID_TX       43
#define BOARD_RFID_UART_NUM     1

/* ---- Battery (virtual) ---- */
#define BQ27220_ADDR            0x55
#define BQ_I2C_PORT             I2C_NUM_0
#define BQ_I2C_SDA              BOARD_PIN_QWIIC_SDA
#define BQ_I2C_SCL              BOARD_PIN_QWIIC_SCL
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH     (1300U)
#define BQ25896_CHARGE_LIMIT    1280

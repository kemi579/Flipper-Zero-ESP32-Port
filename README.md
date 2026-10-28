> [!CAUTION]
> ## 🚨 SECURITY WARNING — DO NOT FLASH "L15Dev" FIRMWARE 🚨
>
> A firmware build distributed under the name **"L15Dev" / "Bitwire"** has been reported to contain **malware (a virus) and a backdoor**. **Do not download, flash, or run it under any circumstances.**
>
> Only use the official builds from this repository / the [web flasher](https://sor3nt.github.io/interface.html). If you already flashed an "L15Dev" image, re-flash a clean official build and treat any credentials/data on the device (WiFi passwords, captures) as compromised.

> WARNING: I do not take responsibility if you damage your board or property. This guide is for educational purposes only — proceed at your own risk.

# Flipper Zero ESP32 Port — DIY Edition

**Fork focused on DIY build:** ESP32-S3 + ST7789 1.9" display + 6 buttons + CC1101 + SPI MicroSD module.

Based on the excellent [Sor3nt/Flipper-Zero-ESP32-Port](https://github.com/Sor3nt/Flipper-Zero-ESP32-Port).

**Branch:** `diy-st7789-1.9`  
**Board ID:** `diy_esp32s3_st7789_1.9`

---

## Our Hardware

| Component              | Details                                      |
|------------------------|----------------------------------------------|
| **MCU**                | ESP32-S3 (recommended N16R8 — 16 MB Flash + 8 MB PSRAM) |
| **Display**            | ST7789 1.9" 320×170                          |
| **Input**              | 6× tactile buttons (active-low)              |
| **SubGHz**             | External CC1101                              |
| **SD Card**            | Standard SPI MicroSD module                  |
| **NFC**                | External PN532 (optional)                    |
| **IR**                 | TX                                           |
| **RGB LED**            | 1× WS2812                                    |

### Full Pinout

#### Buttons (to GND, internal pull-up)

| Button | GPIO |
|--------|------|
| Up     | **41** |
| Down   | **40** |
| Left   | **38** |
| Right  | **39** |
| OK     | **0**  |
| Back   | **4**  |

#### Display ST7789 (SPI2)

| Signal | GPIO |
|--------|------|
| MOSI   | **17** |
| SCLK   | **18** |
| DC     | **15** |
| CS     | **7**  |
| RST    | **16** |
| BL     | **6**  |

#### MicroSD module (SPI, shared with display)

| Module pin | ESP32-S3 |
|------------|----------|
| CS         | **3**    |
| SCK        | **18**   |
| MOSI       | **17**   |
| MISO       | **8**    |
| VCC        | 3.3V     |
| GND        | GND      |

#### CC1101 (SPI3)

| Signal | GPIO |
|--------|------|
| SCK    | **13** |
| CSN    | **46** |
| MISO   | **11** |
| MOSI   | **12** |
| GDO0   | **9**  |
| GDO2   | **10** |

#### Other

| Function     | GPIO   |
|--------------|--------|
| IR TX        | **5**  |
| PN532 SDA    | **47** |
| PN532 SCL    | **42** |
| WS2812 Data  | **48** |
| Battery ADC  | **2** (optional) |

> Detailed guide also in [`DIY_ST7789_1.9_README.md`](DIY_ST7789_1.9_README.md).

---

## How to Build & Flash

### Prerequisites

- **ESP-IDF v5.4.1** (exact version)
- Python 3

### Windows (recommended)

```bat
git clone https://github.com/kemi579/Flipper-Zero-ESP32-Port.git
cd Flipper-Zero-ESP32-Port
git checkout diy-st7789-1.9

:: Build
python winbuild.py build --board diy_st7789_1.9

:: Flash (replace COM14 with your port)
python winbuild.py flash --board diy_st7789_1.9 --port COM14

:: Build + Flash + Monitor
python winbuild.py all --board diy_st7789_1.9 --port COM14
```

If ESP-IDF is not in the default path:

```bat
set ESP_IDF_DIR=C:\path\to\esp-idf-v5.4.1
python winbuild.py build --board diy_st7789_1.9
```

### Linux / macOS

```bash
git clone https://github.com/kemi579/Flipper-Zero-ESP32-Port.git
cd Flipper-Zero-ESP32-Port
git checkout diy-st7789-1.9

chmod +x buildAndFlash_DIY_ST7789_1.9.sh
./buildAndFlash_DIY_ST7789_1.9.sh --port /dev/ttyUSB0

# or build only
./buildAndFlash_DIY_ST7789_1.9.sh --build-only
```

---

## After Flashing

1. Format microSD as **FAT32**.
2. Download [sdcard.zip](https://github.com/Sor3nt/Flipper-Zero-ESP32-Port/releases/latest/download/sdcard.zip).
3. Extract **the contents** to the root of the SD card.
4. Insert the card and reboot the board.

---

## Original Upstream Boards

This fork still contains support for the original boards:

| Board | MCU | Display | Input |
|---|---|---|---|
| LilyGo T-Embed CC1101 | ESP32-S3 | ST7789 320×170 | Encoder |
| Waveshare ESP32-C6-LCD-1.9 | ESP32-C6 | ST7789V2 320×172 | Touch |
| Waveshare ESP32-C6-LCD-1.47 | ESP32-C6 | JD9853 | Touch |
| DIY ESP32-S3 2.8" ILI9341 | ESP32-S3 | ILI9341 320×240 | 6 buttons |

See upstream README for full details: [Sor3nt/Flipper-Zero-ESP32-Port](https://github.com/Sor3nt/Flipper-Zero-ESP32-Port).

---

## Discord

Join the [Flipper Zero meets ESP32 - Discord](https://discord.gg/5DnAqFXaBC) for support and announcements.

---

## Notes

- Prefer ESP32-S3 with **PSRAM**. Without it many apps (especially WiFi tools) will be unstable.
- Power CC1101 and SD module from **3.3 V only**.
- If the screen is rotated or colors are wrong, edit these defines in `components/furi_hal/boards/board_diy_esp32s3_st7789_1.9.h`:
  - `BOARD_LCD_MIRROR_X` / `BOARD_LCD_MIRROR_Y`
  - `BOARD_LCD_INVERT_COLOR`
  - `BOARD_LCD_GAP_Y`
- Button pins can be changed the same way.

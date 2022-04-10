# Using ST7789 TFT with ESP32 and LVGL
### Tools
- resize image with:  https://resizeimage.net/#google_vignette
- LVGL image converter to C array (True Color):  https://docs.lvgl.io/master/overview/image.html

### Configuration
Select these LVGL Configuration in $ idf.py menuconfig:
- Swap the 2 bytes of RGB565 color. Useful if the display has a 8-bit interface (e.g. SPI)
- Color depth 16 RGB565
- invert colors in display
- driver: st7789
- Max horizontal: 240 
- Max Vertical: 300


### Pinout
|ESP32 | ST7789 Display |
|------|----------------|
|GND | GND|
|3v3 |VCC|
|D18 |SCL|
|D23 |SDA|
|D4 |RES |
|D2 |DC|
|D15 |CS| 
|3v3 |BLK|


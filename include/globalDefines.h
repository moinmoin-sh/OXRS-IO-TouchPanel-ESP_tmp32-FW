#pragma once
#include <Arduino.h>
#include <string>
using namespace std;

enum tileType_t
{
  TS_NONE,
  TS_BUTTON,
  TS_BUTTON_LEVEL_UP,
  TS_BUTTON_LEVEL_DOWN,
  TS_BUTTON_UP_DOWN,
  TS_BUTTON_LEFT_RIGHT,
  TS_BUTTON_PREV_NEXT,
  TS_BUTTON_SELECTOR,
  TS_INDICATOR,
  TS_COLOR_PICKER_RGB_CCT,
  TS_COLOR_PICKER_RGB,
  TS_COLOR_PICKER_CCT,
  TS_DROPDOWN,
  TS_KEYPAD,
  TS_REMOTE,
  TS_THERMOSTAT,
  TS_LINK,
  TS_FEED,
  TS_STYLE_COUNT // must be the last element
};

// keyPad types depending how called
enum keyPadType_t
{
  KP_NONE,
  KP_TILE,
  KP_DEVICE,
  KP_LOCKED
};

// entry for the tile_type_LUT
typedef struct
{
  int style;
  const char *styleStr;
} styleLutEntry_t;

typedef struct
{
  string iconStr;
  const void *img;
} imgListElement_t;

#define WP_OPA_BG_OFF     26
#define WP_OPA_BG_ON      255
#define WP_OPA_BG_50      128
#define WP_OPA_BG_PRESSED 128

// screen layout
#ifndef SCREEN_WIDTH
  #define SCREEN_WIDTH    320
#endif
#ifndef SCREEN_HEIGHT
  #define SCREEN_HEIGHT   480
#endif
#ifndef SCREEN_COLS
  #define SCREEN_COLS     2
#endif
#ifndef SCREEN_ROWS
  #define SCREEN_ROWS     3
#endif
#ifndef SCREEN_FOOTER_HEIGHT
  #define SCREEN_FOOTER_HEIGHT 33
#endif

#define SCREEN_START      1
#define SCREEN_END        32
#define SCREEN_HOME       SCREEN_START
#define SCREEN_SETTINGS   (SCREEN_END + 1)

#define TILE_PADDING      5
#define TILE_START        1
#define TILE_END          (SCREEN_COLS * SCREEN_ROWS)

typedef union
{
  struct
  {
    uint8_t tile;
    uint8_t screen;
  } idx;
  uint16_t id;
} tileId_t;

// radius of the color wheel
#define CW_RADIUS         110

// colorPicker modes
#define CP_MODE_COLOR 0x01
#define CP_MODE_TEMP 0x02

// symbols in wp_symbol_font_15
#define WP_SYMBOL_DOTS "\xEF\x85\x82"
#define WP_SYMBOL_CHEV_RIGHT "\xEF\x81\x94"
#define WP_SYMBOL_CHEV_DOWN "\xEF\x81\xB8"

#include <tinyusb/src/class/hid/hid.h>
#include "keyconfig.h"
/*
struct key
{
    int pin;
    uint8_t modifier;
    uint8_t scancode;
};
*/
// 0 1 2
// 3 4 5
// 6 7 8
// 9
int pins[NUMKEYS] =
{
    16, // 0
    5,  // 1
    4,  // 2
    15, // 3
    28, // 4
    3,  // 5
    7,  // 6
    29, // 7
    2,  // 8
    11,  // 9
    12,  // 10
    13  // 11
};
keyconfig keys[3] =
{
    // krita

    0,  HID_KEY_SPACE,         0,  0,                     0,  0,          0,  0,  // translate
    0,  HID_KEY_SPACE,         0,  HID_KEY_SHIFT_LEFT,    0,  0,          0,  0,  // rotate
    0,  HID_KEY_SPACE,         0,  HID_KEY_CONTROL_LEFT,  0,  0,          0,  0,  // zoom
    0,  HID_KEY_E,             0,  0,                     0,  0,          0,  0,  // toggle eraser
    0,  HID_KEY_X,             0,  0,                     0,  0,          0,  0,  // swap colors
    0,  HID_KEY_PAGE_UP,       0,  0,                     0,  0,          0,  0,  // layer up
    0,  HID_KEY_SHIFT_LEFT,    0,  0,                     0,  0,          0,  0,  // hide gui
    0,  HID_KEY_B,             0,  0,                     0,  0,          0,  0,  // brush
    0,  HID_KEY_PAGE_DOWN,     0,  0,                     0,  0,          0,  0,  // layer dow:
    0,  HID_KEY_CONTROL_LEFT,  0,  HID_KEY_T,             0,  0,          0,  0,  // transform layer
    0,  HID_KEY_5,             0,  0,                     0,  0,          0,  0,  // hide gui
    0,  HID_KEY_CONTROL_LEFT,  0,  HID_KEY_SHIFT_LEFT,    0,  HID_KEY_A,  0,  0,  // hide gui

    //zbrush

    0,  HID_KEY_0,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_1,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_2,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_3,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_4,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_5,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_6,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_7,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_8,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_9,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_BACKSPACE,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_COMMA,  0,  0,  0,  0,  0,  0,

    //blender

    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
    0, HID_KEY_SPACE, 0, 0, 0, 0, 0, 0,
};

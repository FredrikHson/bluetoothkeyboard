#include <tinyusb/src/class/hid/hid.h>
#include "keyconfig.h"

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
    11, // 9
    12, // 10
    13  // 11
};
// modifier,  hidkey,  modifier,  hidkey,  modifier,  hidkey,  modifier,  hidkey,
keyconfig keys[NUMMODES] =
{
    // krita

    0,  HID_KEY_SPACE,         0,  0,                     0,  0,          0,  0,  // translate
    0,  HID_KEY_SPACE,         0,  HID_KEY_SHIFT_LEFT,    0,  0,          0,  0,  // rotate
    0,  HID_KEY_SPACE,         0,  HID_KEY_CONTROL_LEFT,  0,  0,          0,  0,  // zoom
    0,  HID_KEY_E,             0,  0,                     0,  0,          0,  0,  // toggle eraser
    0,  HID_KEY_X,             0,  0,                     0,  0,          0,  0,  // swap colors
    0,  HID_KEY_PAGE_UP,       0,  0,                     0,  0,          0,  0,  // layer up
    0,  HID_KEY_SHIFT_LEFT,    0,  0,                     0,  0,          0,  0,  // resize brush
    0,  HID_KEY_B,             0,  0,                     0,  0,          0,  0,  // brush
    0,  HID_KEY_PAGE_DOWN,     0,  0,                     0,  0,          0,  0,  // layer down
    0,  HID_KEY_CONTROL_LEFT,  0,  HID_KEY_T,             0,  0,          0,  0,  // transform layer
    0,  HID_KEY_5,             0,  0,                     0,  0,          0,  0,  // reset rotation
    0,  HID_KEY_CONTROL_LEFT,  0,  HID_KEY_SHIFT_LEFT,    0,  HID_KEY_A,  0,  0,  // deselect all

    //zbrush

    0,  HID_KEY_ALT_LEFT,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_CONTROL_LEFT,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_2,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_SHIFT_LEFT,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_4,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_5,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_6,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_7,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_8,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_9,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_BACKSPACE,  0,  0,  0,  0,  0,  0,
    0,  HID_KEY_ESCAPE,  0,  0,  0,  0,  0,  0,

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

    //numpad

    0,  HID_KEY_KEYPAD_7,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_8,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_9,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_4,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_5,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_6,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_1,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_2,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_3,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_KEYPAD_0,   0,  0,  0,  0,  0,  0,
    0,  HID_KEY_COMMA,      0,  0,  0,  0,  0,  0,
    0,  HID_KEY_BACKSPACE,  0,  0,  0,  0,  0,  0,
};

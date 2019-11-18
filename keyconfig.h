#ifndef __KEYCONFIG_H_
#include <stdint.h>

#define NUMKEYS 12

struct key
{
    uint8_t modifier;
    uint8_t scancode;
};
struct keyconfig
{
    key keys[NUMKEYS][4];
};

enum keymode
{
    krita   = 0,
    zbrush  = 1,
    blender = 2
};

extern int pins[NUMKEYS];
extern keyconfig keys[3];
#endif

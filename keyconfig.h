#ifndef __KEYCONFIG_H_
#include <stdint.h>

#define NUMKEYS 12
#define NUMMODES 4

struct key
{
    uint8_t modifier;
    uint8_t scancode;
};

struct keyconfig
{
    key keys[NUMKEYS][4];
};

extern int pins[NUMKEYS];
extern keyconfig keys[NUMMODES];
#endif

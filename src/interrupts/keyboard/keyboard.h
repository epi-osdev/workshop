#ifndef __KEYBOARD_H__
    #define __KEYBOARD_H__

    #define LAYOUTS_NUM 2
    #define KEYS_NUM 58

typedef enum {
    FR,
    US
} KEYBOARD_LAYOUT;

void init_keyboard();

void set_layout(KEYBOARD_LAYOUT layout);
KEYBOARD_LAYOUT get_layout();

#endif

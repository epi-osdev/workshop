#ifndef __KEYBOARD_H__
    #define __KEYBOARD_H__

    #define LAYOUT_NUM 2
    #define KEY_NUM 58

enum KEYBOARD_LAYOUT {
    FR,
    US
};

unsigned long int current_layout;

void init_keyboard();
char *get_current_layout();

#endif

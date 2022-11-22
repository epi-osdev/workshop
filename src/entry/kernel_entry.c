#include "../interrupts/isr.h"
#include "../interrupts/keyboard/keyboard.h"

void kernel_main()
{
    char* video_memory = (char*) 0xb8000;
    *video_memory = 'X';
    video_memory++;
    *video_memory = 0xf0;

    isr_install();
    init_keyboard();
}

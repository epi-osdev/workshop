#include "../interrupts/isr.h"
#include "../interrupts/keyboard/keyboard.h"
#include "VGA.h"

void init()
{
    vga_clear_screen();
    isr_install();
    init_keyboard();
}

void kernel_main()
{
    init();
}

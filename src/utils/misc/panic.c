#include "panic.h"
#include "VGA.h"

void panic(const char *str)
{
    vga_clear_screen();
    vga_putstr_at(str, 0x0F, 0, 0);
    for (;;);
}
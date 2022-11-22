#include "VGA.h"
#include "heap/init.h"

void init()
{
    vga_clear_screen();
    heap_init();
}

void kernel_main()
{
    init();
    char welcome_msg[] = "Welcome to the kernel!";
    vga_putstr_at(welcome_msg, 0x0F, 0, 0);
}

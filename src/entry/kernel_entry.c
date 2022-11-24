#include "VGA.h"
#include "interrupts/idt.h"
#include "interrupts/isr.h"

void init()
{
    idt_init();
    isr_init();
}

void kernel_main()
{
    // Initialize needed resources like the IDT, etc..
    init();
    vga_putchar_at('X', 0x0f, 0, 0);
    // __asm("sti");
    __asm("int $0x3");
    __asm("int $0x3");
    __asm("int $0x4");
    vga_putchar_at('X', 0x0f, 3, 0);

    // Clean the screen
    // vga_clear_screen();
}
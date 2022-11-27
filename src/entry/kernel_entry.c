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
    __asm__ __volatile__("int $2");
    vga_putchar_at('X', 0x0f, 3, 0);
    char str[] = "Hello World!";
    vga_putstr_at(str, 0x0f, 0, 1);

    // Clean the screen
    // vga_clear_screen();
}
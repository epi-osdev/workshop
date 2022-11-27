#include "VGA.h"
#include "interrupts/idt.h"
#include "interrupts/isr.h"

void init()
{
    isr_init();
    idt_init();
}

void kernel_main()
{
    // Initialize needed resources like the IDT, etc..
    init();
    vga_putchar_at('X', 0x0f, 0, 0);
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
    __asm__ __volatile__("int $4");
    __asm__ __volatile__("int $5");
    // __asm__ __volatile__("int $8");
    vga_putchar_at('X', 0x0f, 3, 0);
    char str[] = "Hello World!";
    vga_putstr_at(str, 0x0f, 0, 1);

    // Clean the screen
    // vga_clear_screen();
}
#include "VGA.h"
#include "interrupts/idt.h"
#include "interrupts/isr.h"
#include "drivers/keyboard.h"
#include "interrupts/timer.h"

void init()
{
    // Default table entries
    isr_init();
    idt_init();

    // Set interrupt flag
    __asm__("sti");

    // Adding IRQ entries
    init_timer(50);
    init_keyboard();
}

void kernel_main()
{
    // Initialize needed resources like the IDT, etc..
    init();

    // Clean the screen
    vga_clear_screen();
}

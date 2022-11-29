#include "keyboard.h"

#include "interrupts/idt.h"
#include "interrupts/isr.h"
#include "interrupts/port.h"
#include "utils/VGA.h"

static KEYBOARD_LAYOUT current_layout = FR;

static char layouts[LAYOUTS_NUM][KEYS_NUM] = {
    #include "layouts/fr.txt"
    #include "layouts/us.txt"
};

static uint8_t resolve_scancode(uint8_t scancode)
{
    if (scancode > 58) {
        return 0;
    }

    return layouts[current_layout][scancode];
}

static void callback(registers_t *regs)
{
    uint8_t scancode = port_byte_in(0x60);
    uint8_t pressed_char = resolve_scancode(scancode);

    // TODO
    vga_putchar_at(pressed_char, 0x0f, 20, 20);
}

void init_keyboard()
{
    isr_register_handler(33, callback);
}

void set_layout(KEYBOARD_LAYOUT layout)
{
    current_layout = layout;
}

KEYBOARD_LAYOUT get_layout()
{
    return current_layout;
}

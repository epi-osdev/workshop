#include "keyboard.h"
#include "../../utils/ports.h"
#include "../isr.h"

static char available_layouts[LAYOUT_NUM][KEY_NUM] = {
    #include "layouts/fr.txt"
    #include "layouts/us.txt"
};

char *get_current_layout()
{
    return available_layouts[current_layout];
}

static void set_current_layout(unsigned int value)
{
    current_layout = value;
}

static void handler(__attribute__((unused)) registers_t r)
{
    unsigned char scancode = port_byte_in(0x60);
    (void) scancode;
}

void init_keyboard()
{
    set_current_layout(FR);
    register_interrupt_handler(IRQ(1), handler); 
}

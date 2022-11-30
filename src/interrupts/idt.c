#include "idt.h"

static idt_entry_t idt_entries[MAX_IDT_ENTRIES];
static idt_descriptor_t idt_descriptor = {
    .size = sizeof(idt_entries) - 1,
    .idt_start = idt_entries
};

void idt_init() 
{
    lidt();
}

void lidt()
{
    __asm__("lidt (%0)" : : "m" (idt_descriptor));
}

void set_idt_gate(
    uint8_t entry_index,
    void *base, 
    uint16_t segment,
    uint8_t flags
)
{
    if (entry_index > (MAX_IDT_ENTRIES - 1)) {
        return;
    }

    idt_entries[entry_index].base_low = (uint32_t) base & 0xffff;
    idt_entries[entry_index].segment = segment;
    idt_entries[entry_index].always_null = 0;
    idt_entries[entry_index].flags = flags;
    idt_entries[entry_index].base_high = (uint32_t) base >> 16;
}

void set_gate_flag(int entry_index, uint8_t flag)
{
    if (entry_index > (MAX_IDT_ENTRIES - 1)) {
        return;
    }

    idt_entries[entry_index].flags |= flag;
}

void unset_gate_flag(int entry_index, uint8_t flag)
{
    if (entry_index > (MAX_IDT_ENTRIES - 1)) {
        return;
    }

    idt_entries[entry_index].flags &= ~flag;
}

void idt_enable_gates()
{
    for (int i = 0; i < MAX_IDT_ENTRIES; i++) {
        set_gate_flag(i, IDT_FLAG_PRESENT);
    }
}

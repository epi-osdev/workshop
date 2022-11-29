#include "idt.h"

static idt_entry_t idt_entries[ENTRIES_NUM];
static idt_descriptor_t idt_descriptor = {
    sizeof(idt_entries) - 1,
    idt_entries
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
    int32_t entry_index,
    void *base, 
    uint32_t segment,
    uint8_t flags
)
{
    if (entry_index > (ENTRIES_NUM - 1)) {
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
    if (entry_index > (ENTRIES_NUM - 1)) {
        return;
    }

    idt_entries[entry_index].flags |= flag;
}

void unset_gate_flag(int entry_index, uint8_t flag)
{
    if (entry_index > (ENTRIES_NUM - 1)) {
        return;
    }

    idt_entries[entry_index].flags &= ~flag;
}

void idt_enable_gates()
{
    for (int i = 0; i < ENTRIES_NUM; i++) {
        set_gate_flag(i, IDT_FLAG_PRESENT);
    }
}

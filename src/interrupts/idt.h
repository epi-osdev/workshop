#ifndef __IDT_H__
    #define __IDT_H__

    #define MAX_IDT_ENTRIES 256

    #include "utils/types.h"

// IDT entries are called gates
typedef struct idt_entry_s {
    uint16_t base_low;
    uint16_t segment;
    uint8_t always_null;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct idt_descriptor_s {
    uint16_t size;
    idt_entry_t *idt_start;
} __attribute__((packed)) idt_descriptor_t;

enum IDT_FLAGS {
    // Gate
    IDT_FLAG_GATE_TASK          = 0X5,
    IDT_FLAG_GATE_16BIT_INT     = 0x6,
    IDT_FLAG_GATE_16BIT_TRAP    = 0x7,
    IDT_FLAG_GATE_32BIT_INT     = 0xe,
    IDT_FLAG_GATE_32BIT_TRAP    = 0xf,

    // Ring
    IDT_FLAG_RING0              = (0 << 5),
    IDT_FLAG_RING1              = (1 << 5),
    IDT_FLAG_RING2              = (2 << 5),
    IDT_FLAG_RING3              = (3 << 5),

    IDT_FLAG_PRESENT            = 0x80
};

void idt_init();
void set_idt_gate(
    uint8_t entry_index,
    void *base, 
    uint16_t segment,
    uint8_t flags
);
void set_gate_flag(int entry_index, uint8_t flag);
void idt_enable_gates();
void unset_gate_flag(int entry_index, uint8_t flag);
void lidt();


#endif

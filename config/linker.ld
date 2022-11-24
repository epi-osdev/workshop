ENTRY(_start)
OUTPUT_FORMAT(binary)
phys = 0x7C00;                  /* BIOS puts us at 0x7C00 */

SECTIONS
{
    . = phys;
    .text 0x1000: ALIGN(4096)
    {
        *(.text)
    }

    .asm : ALIGN(4096)
    {
        *(.asm)
    }

    .rodata : ALIGN(4096)
    {
        *(.rodata)
    }

    .data : ALIGN(4096)
    {
        *(.data)
    }

    .bss : ALIGN(4096)
    {
        *(COMMON)
        *(.bss)
    }
}
def main():
    for i in range(256):
        name = None
        if i >= 32 and i <= 47:
            name = f"irq{i - 32}"
        else:
            name = f"isr{i}"
        print(f"set_idt_gate({i}, {name}, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);")

if __name__ == "__main__":
    main()

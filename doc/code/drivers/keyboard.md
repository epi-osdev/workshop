# INTRODUCTION

This file describes the keyboard driver management and how to use it. It's used to initialize and provide provide an interface to the keyboard.

# TABLE OF CONTENTS

- [API](#api)
- [Code explanation](#code-explanation)

# API <a name="api"></a>

The keyboard driver provides the following functions:

- `init_keyboard`: It's initializing the keyboard driver. It must be called in the kernel initialization.
- `get_layout`: It's returning the current keyboard layout. (KEYBOARD_LAYOUT enum)
- `set_layout`: It's setting the current keyboard layout. (KEYBOARD_LAYOUT enum)

The `KEYBOARD_LAYOUT` enum is defined in [drivers/keyboard.h](../../../src/drivers/keyboard.h) and contains the following values:

# Code explanation <a name="code-explanation"></a>

the file contains a first global variable named current_layout. It's used to store the current keyboard layout. It's initialized to `FR` in the `init_keyboard` function.
```c
static KEYBOARD_LAYOUT current_layout = FR;
```

the `init_keyboard` function is initializing the keyboard driver. It's called in the kernel initialization.
```c
void init_keyboard()
{
    isr_register_handler(33, callback);
}
```
It's setting the isr callback for the interrupt 33 (it's the interrupt used by the keyboard). Actually we are setting the callback after the `lidt` function but it's not a problem because the IDT descriptor is holding an address and not the data.

We have getter and setter for the keyboard layout:

```c
KEYBOARD_LAYOUT get_layout()
{
    return current_layout;
}
```

```c
void set_layout(KEYBOARD_LAYOUT layout)
{
    current_layout = layout;
}
```

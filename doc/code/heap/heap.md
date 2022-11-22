# INTRODUCTION

Here is the explaination of how the heap is working and how we implemented it. In your life you will have to use only two types of memory: the stack and the heap. The stack is the local memory that we use for variable declaration; Eg:
```c
int main() {
    int a = 0; // push a on the stack
    int b = 0; // push b on the stack
    int c = a + b; // push c on the stack
    return 0;
}
```
Here we are looking for the heap. The heap is the memory that we use for dynamic allocation. It is the memory that we use when we want to allocate a variable that we don't know the size at compile time. Eg:
```c
int main() {
    char *str = malloc(10); // allocate 10 bytes on the heap
    int *array = malloc(10 * sizeof(int)); // allocate 10 * sizeof(int) bytes on the heap
    free(str); // free the memory allocated for str
    free(array); // free the memory allocated for array
    return 0;
}
```
The main differences between thoses is the fact that one is temporary and depends on the scope of the variable, the other is permanent and depends on the lifetime of the program. The stack is used for local variables, the heap is used for global variables. (Note: the heap is not only used for global variables, but it is the most common use case).

# Table of contents

- [Theorical implementation](#theorical-implementation)
- [Initialization](#initialization)
- [Allocation](#allocation)
- [Freeing](#freeing)
- [Data structure](#data-structure)

# Theorical implementation <a name="theorical-implementation"></a>

So, how it's working for us ? We are implementing a basic paging system for the heap. A paging system is just the fact of dividing the memory into blocks of a specific size. For us a block is `4096` bytes and the first one is a flag byte that's describing the block state. For now we have three flags:
- HEAP_FREE_FLAG      `0b00000000` -> the current block is free
- HEAP_USED_FLAG      `0b00000001` -> the current block is used
- HEAP_HAS_NEXT_FLAG  `0b00000010` -> the current block has a next block

The two first flags are obvious, the third one is just in case we are allocating an area >= to the `HEAP_BLOCK_SIZE` (4096 bytes). In this case we need more than one page to store the data. So we are just setting the flag to the next block and so on. 
When we are freeing a block we are just setting the flag to `HEAP_FREE_FLAG` and if the next block has the flag `HEAP_HAS_NEXT_FLAG` we are setting it to `HEAP_FREE_FLAG` too and so on.

# Initialization <a name="initialization"></a>

The initialization of the struct is made by the function `heap_init()` in the file [init.c](../../../src/heap/init.c). It's a simple function that initialize the heap struct with the correct default values. The heap struct is defined in the file [config.h](../../../src/heap/config.h)
for more information about how it's initialized you can look at the file [init.md](init.md)

# Allocation <a name="allocation"></a>

Once your heap is initialized you can allocate memory from it. For this, you can call the function heap_alloc with the size wanted, it will returns the first fit case. If there is no fit case, it will trigger a panic.
If you want more information about how the allocation is working you can look at the file [alloc.md](alloc.md)

# Freeing <a name="freeing"></a>

Once you have allocated memory, you can free it. For this, you can call the function heap_free with the pointer to the memory you want to free. It will free the memory and merge the free blocks if needed.
If you want more information about how the freeing is working you can look at the file [free.md](free.md)

# Data structure <a name="data-structure"></a>

The heap is a main structure that contains a table that's containing all of our data and a saddr that just our starting address. It's store in the file [config.h](../../../src/heap/config.h) and is defined like this:
```c
typedef struct heap_s {
    heap_table_t *table;        // Pointer to the heap table management
    void *saddr;                // Start address of the heap, define by HEAP_ADDR
} heap_t;
```

The heap_table_t is a structure that's containing all of our data. It's containing an array of bytes that's will contains all of our data. The entries is splitted into blocks of specific size. it's defined in the file [config.h](../../../src/heap/config.h) and it looks like this:
```c
typedef struct heap_table_s {   // This describe the heap table
    uint8_t *entries;           // all the entries of the heap, this is a pointer starting from the HEAP_ADDR
    size_t total_block_size;    // Total size of the heap in blocks, defined by HEAP_BLOCK_COUNT
} heap_table_t;
```
If you want more information about the data structure you can look at the file [config.md](config.md)
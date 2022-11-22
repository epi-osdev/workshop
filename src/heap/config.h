#ifndef __EOS_HEAP_CONFIG_H__
    #define __EOS_HEAP_CONFIG_H__

    #include "types.h"

/**
 * @brief this is the heap management file, it contains the heap structure and
 * the functions to manage it.
 */

    #define HEAP_BLOCK_SIZE     4096                                    // 4KB
    #define HEAP_BLOCK_COUNT    1024                                    // Nb of blocks
    #define HEAP_SIZE           (HEAP_BLOCK_SIZE * HEAP_BLOCK_COUNT)    // Total size of the heap blocks (4096MB)
    #define HEAP_ADDR           0x01000000                              // Address of the heap block entries

// All heap flags

    #define HEAP_FREE_FLAG      0b00000000
    #define HEAP_USED_FLAG      0b00000001
    #define HEAP_HAS_NEXT_FLAG  0b00000010

typedef struct heap_table_s {   // This describe the heap table
    uint8_t *entries;           // all the entries of the heap, this is a pointer starting from the HEAP_ADDR
    size_t total_block_size;    // Total size of the heap in blocks, defined by HEAP_BLOCK_COUNT
} heap_table_t;

typedef struct heap_s {
    heap_table_t *table;        // Pointer to the heap table management
    void *saddr;                // Start address of the heap, define by HEAP_ADDR
} heap_t;

#endif
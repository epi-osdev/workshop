#include "heap/init.h"
#include "misc.h"
#include "memory.h"

static heap_t _heap;
static heap_table_t _heap_table;

static void init_heap_struct()
{
    memset(&_heap, 0, sizeof(heap_t));
    _heap.saddr = (void *)HEAP_ADDR;
}

static void init_heap_table()
{
    _heap_table.entries = (void *)HEAP_ADDR;
    _heap_table.total_block_size = HEAP_BLOCK_COUNT;
    _heap.table = &_heap_table;
    for (int i = 0; i < HEAP_BLOCK_COUNT; i++)
        _heap.table->entries[i] = HEAP_FREE_FLAG;
}

static int check_align_size(void *ptr)
{
    return ((size_t)ptr % HEAP_BLOCK_SIZE == 0);
}

static void checking_alignment()
{
    void *saddr = _heap.saddr;
    void *eaddr = (void *)((uint32_t)saddr + HEAP_SIZE);

    if (!check_align_size(saddr) || !check_align_size(eaddr)) {
        panic("Heap starting address is not aligned to HEAP_BLOCK_SIZE");
    }
}

void heap_init()
{
    init_heap_struct();
    init_heap_table();
    checking_alignment();
}

heap_t *get_heap()
{
    return &_heap;
}

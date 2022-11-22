#include "free.h"
#include "config.h"

void heap_free(void *ptr)
{
    uint8_t *base_ptr = ptr - 1;

    while (*base_ptr & HEAP_HAS_NEXT_FLAG) {
        *base_ptr = HEAP_FREE_FLAG;
        base_ptr += HEAP_BLOCK_SIZE;
    }
    *base_ptr = HEAP_FREE_FLAG;
}

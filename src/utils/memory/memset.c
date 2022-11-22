#include "memset.h"

void memset(void *ptr, uint8_t value, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        ((uint8_t *)ptr)[i] = value;
    }
}

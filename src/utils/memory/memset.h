#ifndef __EOS_UTILS_MEMORY_MEMSET_H__
    #define __EOS_UTILS_MEMORY_MEMSET_H__

    #include "types.h"

/**
* @brief set the memory at the given address with the given value
* @param addr the address to set
* @param value the value to set
* @param size the size of the memory to set
*/
void memset(void *ptr, uint8_t value, size_t size);

#endif

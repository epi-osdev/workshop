#ifndef __EOS_HEAP_ALLOC_H__
    #define __EOS_HEAP_ALLOC_H__

    #include "types.h"

/**
* @brief This function return the first free address in the heap.
* It will always return the address of the first page of the heap that can fit all the buffer
* @param size The size of the buffer to allocate
* @return The address of the first page of the heap that can fit all the buffer
*/
void *heap_alloc(size_t size);

#endif
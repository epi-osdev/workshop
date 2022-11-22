#ifndef __EOS_HEAP_INIT_H__
    #define __EOS_HEAP_INIT_H__

    #include "config.h"

/**
* @brief Initialize the heap
*/
void heap_init();

/**
* @brief return the current heap
* @return the current heap structure
*/
heap_t *get_heap();

#endif
#include "allocator.h"
#include <stdint.h>

static uint8_t memory_pool[POOL_SIZE]; // before my_malloc

void *my_malloc(size_t size) {
    // point to start of pool
    BlockHeader *current = (BlockHeader *)memory_pool;

    // Loop through pool
    while ((uint8_t *)current < memory_pool + POOL_SIZE) {

        if (current->is_free && current->size >= size) {

            current-> is_free = 0;

            return (void *)(current + 1); // return pointer to memory after header
        }
        // Move to next block
        current = (BlockHeader *)((uint8_t *)current + sizeof(BlockHeader) + current->size);
    }

    return NULL; // Return NULL if nothing found
    
}


void my_free(void *ptr) {

    BlockHeader *header = (BlockHeader *)ptr - 1; // Get the header of the block
    header->is_free = 1; // Mark the block as free

}


void allocator_init(void) {
    // cast memory_pool to a BlockHeader pointer
    BlockHeader *header = (BlockHeader *)memory_pool;


    // set size to cover the entire pool minus header
    header->size = POOL_SIZE - sizeof(BlockHeader);
    // mark it as free
    header->is_free = 1;

}
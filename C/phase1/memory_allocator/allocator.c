#include "allocator.h"
#include <stdint.h>
#include <stdio.h>

static uint8_t memory_pool[POOL_SIZE]; // before my_malloc

void *my_malloc(size_t size) {
    if (size == 0) return NULL; // guard against zero size request

    BlockHeader *current = (BlockHeader *)memory_pool;

    while ((uint8_t *)current + sizeof(BlockHeader) <= memory_pool + POOL_SIZE) {

        if (current->is_free && current->size >= size) {
            current->is_free = 0;
            return (void *)(current + 1);
        }

        if (current->size == 0) return NULL; // prevent infinite loop

        current = (BlockHeader *)((uint8_t *)current + sizeof(BlockHeader) + current->size);
    }

    return NULL;
}


void my_free(void *ptr) {
    if (ptr == NULL) return; // Handle NULL pointer

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

void allocator_print_pool(void) {
    // cast memory_pool to BlockHeader pointer
    BlockHeader *header = (BlockHeader *)memory_pool;
    int total_blocks = 0;

    // loop through all blocks while inside pool boundary
    while ((uint8_t *)header + sizeof(BlockHeader) <= memory_pool + POOL_SIZE) {
        printf("Block %d: Size = %zu, Is Free = %d\n", total_blocks, header->size, header->is_free);
        total_blocks++;

        // Move to the next block
        header = (BlockHeader *)((uint8_t *)header + sizeof(BlockHeader) + header->size);
    }

    printf("Total blocks in pool: %d\n", total_blocks);
}

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

// Must be inside header guard to avoid multiple inclusion of the same header file
#include <stddef.h>

// Define the size of the memory pool
#define POOL_SIZE 1024

// Define a structure for the block header
typedef struct BlockHeader {
    size_t size;
    int is_free;
} BlockHeader;

void *my_malloc(size_t size); // takes the size of the memory block to be allocated and returns a pointer to the allocated memory

void my_free(void *ptr); // takes a pointer to the memory block to be freed

void allocator_init(); // initializes the memory pool and sets up the initial free block

#endif // ALLOCATOR_H
#include "allocator.h"
#include <stdio.h>


int main() {
    allocator_init();

    void *ptr = my_malloc(32); //allocate 32 bytes

    if (ptr != NULL) {
        printf("Allocation done\n");
    } else {
        printf("Allocation failed\n");
    }

    my_free(ptr); // release memory
    printf("Memory freed\n");

    return 0;
}

  

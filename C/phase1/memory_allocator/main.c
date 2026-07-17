#include "allocator.h"
#include <stdio.h>

int main() {
    allocator_init();

    // --- Test 1: Basic allocation ---
    void *ptr = my_malloc(32);
    if (ptr != NULL) {
        printf("Test 1 PASSED: Allocation successful\n");
    } else {
        printf("Test 1 FAILED: Allocation failed\n");
    }
    my_free(ptr);
    printf("Test 1: Memory freed\n\n");

    // --- Test 2: Allocate more than pool size ---
    void *big = my_malloc(2000);
    if (big == NULL) {
        printf("Test 2 PASSED: Oversized allocation correctly returned NULL\n\n");
    } else {
        printf("Test 2 FAILED: Should have returned NULL\n\n");
    }

    // --- Test 3: Fill the pool ---
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(32); // should fail
    if (p5 == NULL) {
        printf("Test 3 PASSED: Pool full, allocation correctly returned NULL\n\n");
    } else {
        printf("Test 3 FAILED: Should have returned NULL\n\n");
    }

    // --- Test 4: NULL free ---
    my_free(NULL);
    printf("Test 4 PASSED: my_free(NULL) handled safely\n\n");

    return 0;
}

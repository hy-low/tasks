#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "heap.h"

// Test basic heap operations
void test1(void) {
    Heap *heap = heap_create();

    int n = 1000000;
    for (int i = 1; i <= n; i++) {
        heap_push(heap, n - i + 1);
        assert(heap_size(heap) == i);
        assert(heap_top(heap) == n - i + 1);
    }

    for (int i = 1; i <= n; i++) {
        assert(heap_top(heap) == i);
        heap_pop(heap);
        assert(heap_size(heap) == n - i);
    }

    heap_free(heap);
}

// Create a large number of heaps
void test2(void) {
    int n = 1000000;
    Heap **heaps = malloc(sizeof(Heap*) * n);
    for (int i = 0; i < n; i++) {
        heaps[i] = heap_create();
    }
    for (int i = 0; i < n; i++) {
        heap_free(heaps[i]);
    }
    free(heaps);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    test1();
    test2();

    printf("Set 4b OK\n");
}

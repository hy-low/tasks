#include <stdio.h>
#include "heap.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    Heap *heap = heap_create();

    heap_push(heap, 3);
    heap_push(heap, 7);
    heap_push(heap, 1);
    heap_push(heap, 3);

    printf("Heap size: %d\n", heap_size(heap));
    printf("Heap top value: %d\n", heap_top(heap));

    heap_pop(heap);

    printf("Heap size: %d\n", heap_size(heap));
    printf("Heap top value: %d\n", heap_top(heap));

    heap_free(heap);
}

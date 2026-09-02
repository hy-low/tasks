#include <stdio.h>
#include "heap.h"

void local_tests(void) {
    Heap *heap = heap_create();

    printf("Initial size: %d\n", heap_size(heap));

    heap_push(heap, 30);
    heap_push(heap, 10);
    heap_push(heap, 20);

    printf("Size after pushing 3 values: %d\n", heap_size(heap));
    printf("Top value: %d\n", heap_top(heap));

    heap_pop(heap);

    printf("Size after pop: %d\n", heap_size(heap));
    printf("Top value after pop: %d\n", heap_top(heap));

    heap_push(heap, 5);
    heap_push(heap, 40);
    heap_push(heap, 15);
    heap_push(heap, 1);
    heap_push(heap, 50);

    printf("Size after pushing more values: %d\n", heap_size(heap));
    printf("Top value: %d\n", heap_top(heap));

    while (heap_size(heap) > 0) {
        printf("Popping: %d\n", heap_top(heap));
        heap_pop(heap);
    }

    printf("Final size: %d\n", heap_size(heap));

    heap_free(heap);
}

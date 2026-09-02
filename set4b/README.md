# Set 4b

In this exercise, your task is to implement a heap data structure in C.

More precisely, you should implement a minimum binary heap that stores values so that the smallest value can always be found quickly.

Your heap should store `int` values. It should start with a small capacity and automatically grow when more space is needed.

## Files

- `heap.h` contains the public function declarations
- `heap.c` contains the implementation

The heap should hide its internal data from the user. The user should only work with a `Heap*`.

## Required functions

### `Heap* heap_create(void)`

Creates a new empty heap.

The heap should:

- start with size 0
- have an initial capacity of 4
- allocate memory for storing integers

Returns a pointer to the new heap.

### `void heap_push(Heap *heap, int value)`

Adds a new value to the heap.

If the heap is full, it should:

- double its capacity
- resize the internal array using `realloc`

After adding the value, the heap must still keep the smallest value at the top.

### `void heap_pop(Heap *heap)`

Removes the smallest value from the heap.

You may assume the heap is not empty when this function is called.

After removing the value, the heap must still keep the smallest value at the top.

### `int heap_top(Heap *heap)`

Returns the smallest value in the heap without removing it.

You may assume the heap is not empty when this function is called.

### `int heap_size(Heap *heap)`

Returns the number of values currently stored in the heap.

### `void heap_free(Heap *heap)`

Frees all memory used by the heap.

This function should free:

- the internal array
- the heap structure itself

## Example code

The file `local.c` contains the following code to test your heap.

```c
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
```

Expected output:

```
Initial size: 0
Size after pushing 3 values: 3
Top value: 10
Size after pop: 2
Top value after pop: 20
Size after pushing more values: 7
Top value: 1
Popping: 1
Popping: 5
Popping: 15
Popping: 20
Popping: 30
Popping: 40
Popping: 50
Final size: 0
```

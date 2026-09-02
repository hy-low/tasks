# Set 4a

In this exercise, your task is to implement a stack data structure in C.

A stack stores values in LIFO (last in, first out) order. This means the last value added to the stack is the first value removed.

Your stack should store `int` values. It should start with a small capacity and automatically grow when more space is needed.

## Files

- `stack.h` contains the public function declarations
- `stack.c` contains the implementation

The stack should hide its internal data from the user. The user should only work with a `Stack*`.

## Required functions

### `Stack* stack_create(void)`

Creates a new empty stack.

The stack should:

- start with size 0
- have an initial capacity of 4
- allocate memory for storing integers

Returns a pointer to the new stack.

### `void stack_push(Stack *stack, int value)`

Adds a new value to the top of the stack.

If the stack is full, it should:

- double its capacity
- resize the internal array using `realloc`

### `void stack_pop(Stack *stack)`

Removes the value at the top of the stack.

You may assume the stack is not empty when this function is called.

### `int stack_top(Stack *stack)`

Returns the value at the top of the stack without removing it.

You may assume the stack is not empty when this function is called.

### `int stack_size(Stack *stack)`

Returns the number of values currently stored in the stack.

### `void stack_free(Stack *stack)`

Frees all memory used by the stack.

This function should free:

- the internal array
- the stack structure itself

## Example code

The file `local.c` contains the following code to test your stack.

```c
#include <stdio.h>
#include "stack.h"

void local_tests(void) {
    Stack *stack = stack_create();

    printf("Initial size: %d\n", stack_size(stack));

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("Size after pushing 3 values: %d\n", stack_size(stack));
    printf("Top value: %d\n", stack_top(stack));

    stack_pop(stack);

    printf("Size after pop: %d\n", stack_size(stack));
    printf("Top value after pop: %d\n", stack_top(stack));

    stack_push(stack, 40);
    stack_push(stack, 50);
    stack_push(stack, 60);
    stack_push(stack, 70);

    printf("Size after pushing more values: %d\n", stack_size(stack));
    printf("Top value: %d\n", stack_top(stack));

    while (stack_size(stack) > 0) {
        printf("Popping: %d\n", stack_top(stack));
        stack_pop(stack);
    }

    printf("Final size: %d\n", stack_size(stack));

    stack_free(stack);
}
```

Expected Output

```
Initial size: 0
Size after pushing 3 values: 3
Top value: 30
Size after pop: 2
Top value after pop: 20
Size after pushing more values: 6
Top value: 70
Popping: 70
Popping: 60
Popping: 50
Popping: 40
Popping: 20
Popping: 10
Final size: 0
```

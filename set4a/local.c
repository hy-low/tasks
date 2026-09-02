#include <stdio.h>
#include "stack.h"

void local_tests(void) {
    // You can use this file for testing functions locally
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

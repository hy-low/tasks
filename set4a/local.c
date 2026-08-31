#include <stdio.h>
#include "stack.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    Stack *stack = stack_create();

    stack_push(stack, 1);
    stack_push(stack, 3);
    stack_push(stack, 3);
    stack_push(stack, 7);

    printf("Stack size: %d\n", stack_size(stack));
    printf("Stack top value: %d\n", stack_top(stack));

    stack_pop(stack);

    printf("Stack size: %d\n", stack_size(stack));
    printf("Stack top value: %d\n", stack_top(stack));

    stack_free(stack);
}

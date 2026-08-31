#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "stack.h"

// Test basic stack operations
void test1(void) {
    Stack *stack = stack_create();
    assert(stack_size(stack) == 0);

    int n = 1000000;
    for (int i = 1; i <= n; i++) {
        stack_push(stack, 1337 * i);
        assert(stack_size(stack) == i);
        assert(stack_top(stack) == 1337 * i);
    }
    for (int i = n-1; i >= 0; i--) {
        stack_pop(stack);
        assert(stack_size(stack) == i);
        if (i != 0) {
            assert(stack_top(stack) == 1337 * i);
        }
    }

    stack_free(stack);
}

// Create a large number of stacks
void test2(void) {
    int n = 1000000;
    Stack **stacks = malloc(sizeof(Stack*) * n);
    for (int i = 0; i < n; i++) {
        stacks[i] = stack_create();
    }
    for (int i = 0; i < n; i++) {
        stack_free(stacks[i]);
    }
    free(stacks);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    test1();
    test2();

    printf("Set 4a OK\n");
}

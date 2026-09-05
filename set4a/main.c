#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "stack.h"

#define GRAY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define CLEAR_PREVIOUS_LINE "\033[1A\033[2K\r"

static const char *current_test = NULL;

void testing(const char *name) {
    current_test = name;
    printf(GRAY "[" YELLOW "testing" GRAY "]" RESET " %s\n", name);
    fflush(stdout);
}

void test_ok(void) {
    printf(CLEAR_PREVIOUS_LINE GRAY "[" GREEN "ok" GRAY "]" RESET " %s\n",
           current_test);
}

void test_failed(void) {
    printf(CLEAR_PREVIOUS_LINE GRAY "[" RED "failed" GRAY "]" RESET " %s\n",
           current_test);
}

void test_assert_impl(char *condition, int result) {
    if (result) return;

    test_failed();
    printf("Wrong answer: %s\n", condition);
    exit(0);
}

#define test_assert(condition) test_assert_impl(#condition, condition)

// Test basic stack operations
void test1(void) {
    Stack *stack = stack_create();
    test_assert(stack_size(stack) == 0);

    int n = 1000000;
    for (int i = 1; i <= n; i++) {
        stack_push(stack, 1337 * i);
        test_assert(stack_size(stack) == i);
        test_assert(stack_top(stack) == 1337 * i);
    }
    for (int i = n-1; i >= 0; i--) {
        stack_pop(stack);
        test_assert(stack_size(stack) == i);
        if (i != 0) {
            test_assert(stack_top(stack) == 1337 * i);
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

    testing("basic stack operations");

    test1();

    test_ok();

    testing("large number of stacks");

    test2();

    test_ok();

    printf("Set 4a OK\n");

    return 0;
}

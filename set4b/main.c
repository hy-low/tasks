#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "heap.h"

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

// Test basic heap operations
void test1(void) {
    Heap *heap = heap_create();

    int n = 1000000;
    for (int i = 1; i <= n; i++) {
        heap_push(heap, n - i + 1);
        test_assert(heap_size(heap) == i);
        test_assert(heap_top(heap) == n - i + 1);
    }

    for (int i = 1; i <= n; i++) {
        test_assert(heap_top(heap) == i);
        heap_pop(heap);
        test_assert(heap_size(heap) == n - i);
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

    testing("basic heap operations");

    test1();

    test_ok();

    testing("large number of heaps");

    test2();

    test_ok();

    printf("Set 4b OK\n");

    return 0;
}

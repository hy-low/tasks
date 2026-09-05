#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "tree.h"

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

// Test basic tree operations
void test1(void) {
    Tree *tree = tree_create();

    int n = 100;
    for (int i = 1; i <= n; i++) {
        tree_insert(tree, (42 * i) % 1337);
        test_assert(tree_size(tree) == i);
    }

    for (int i = 1; i <= n; i++) {
        tree_remove(tree, (42 * i) % 1337);
        test_assert(tree_size(tree) == n - i);
    }

    tree_free(tree);
}

// Create a large number of trees
void test2(void) {
    int n = 1000000;
    Tree **trees = malloc(sizeof(Tree*) * n);
    for (int i = 0; i < n; i++) {
        trees[i] = tree_create();
    }
    for (int i = 0; i < n; i++) {
        tree_free(trees[i]);
    }
    free(trees);
}

// More advanced test
void test3(void) {
    int n = 100000;
    int *data = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        data[i] = i + 1;
        int p = rand() % (i + 1);
        if (p == i) continue;
        int x = data[p];
        data[p] = data[i];
        data[i] = x;
    }

    Tree *tree = tree_create();
    int size = 0;

    int min_value = n;
    int max_value = 1;
    for (int i = 0; i < n; i++) {
        tree_insert(tree, data[i]);
        size++;
        test_assert(tree_size(tree) == size);
        if (data[i] < min_value) min_value = data[i];
        if (data[i] > max_value) max_value = data[i];
        test_assert(*tree_min(tree) == min_value);
        test_assert(*tree_max(tree) == max_value);
    }

    for (int i = 0; i < n; i += 2) {
        tree_remove(tree, data[i]);
        size--;
        test_assert(tree_size(tree) == size);
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            test_assert(tree_check(tree, data[i]) == 0);
        } else {
            test_assert(tree_check(tree, data[i]) == 1);
        }
    }

    int *value = tree_min(tree);
    int count = 0;
    while (value) {
        test_assert(tree_check(tree, *value) == 1);
        count++;
        value = tree_find(tree, *value + 1);
    }
    test_assert(count == size);

    for (int i = 1; i < n; i += 2) {
        tree_remove(tree, data[i]);
        size--;
        test_assert(tree_size(tree) == size);
    }

    free(data);
    tree_free(tree);
}

// Duplicate values test
void test4() {
    Tree *tree = tree_create();

    int n = 1000000;
    for (int i = 1; i <= n; i++) {
        tree_insert(tree, 1337);
        test_assert(tree_size(tree) == 1);
    }

    tree_free(tree);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("basic tree operations");

    test1();

    test_ok();

    testing("large number of trees");

    test2();

    test_ok();

    testing("advanced tree operations");

    test3();

    test_ok();

    testing("duplicate values");

    test4();

    test_ok();

    printf("Set 4c OK\n");

    return 0;
}

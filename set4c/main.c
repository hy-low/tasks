#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "tree.h"

// Test basic tree operations
void test1(void) {
    Tree *tree = tree_create();

    int n = 100;
    for (int i = 1; i <= n; i++) {
        tree_insert(tree, (42 * i) % 1337);
        assert(tree_size(tree) == i);
    }

    for (int i = 1; i <= n; i++) {
        tree_remove(tree, (42 * i) % 1337);
        assert(tree_size(tree) == n - i);
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
        assert(tree_size(tree) == size);
        if (data[i] < min_value) min_value = data[i];
        if (data[i] > max_value) max_value = data[i];
        assert(*tree_min(tree) == min_value);
        assert(*tree_max(tree) == max_value);
    }

    for (int i = 0; i < n; i += 2) {
        tree_remove(tree, data[i]);
        size--;
        assert(tree_size(tree) == size);
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            assert(tree_check(tree, data[i]) == 0);
        } else {
            assert(tree_check(tree, data[i]) == 1);
        }
    }

    int *value = tree_min(tree);
    int count = 0;
    while (value) {
        assert(tree_check(tree, *value) == 1);
        count++;
        value = tree_find(tree, *value + 1);
    }
    assert(count == size);

    for (int i = 1; i < n; i += 2) {
        tree_remove(tree, data[i]);
        size--;
        assert(tree_size(tree) == size);
    }

    free(data);
    tree_free(tree);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    test1();
    test2();
    test3();

    printf("Set 4c OK\n");
}

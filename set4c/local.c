#include <stdio.h>
#include "tree.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    Tree *tree = tree_create();

    tree_insert(tree, 42);
    tree_insert(tree, 1337);
    tree_insert(tree, 123);

    printf("Tree size: %d\n", tree_size(tree));
    printf("Min value: %d\n", *tree_min(tree));
    printf("Max value: %d\n", *tree_max(tree));
    printf("Contents: ");

    int *value = tree_min(tree);
    while (value) {
        printf("%d ", *value);
        value = tree_find(tree, *value + 1);
    }
    printf("\n");

    tree_free(tree);
}

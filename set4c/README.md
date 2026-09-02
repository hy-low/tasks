# Set 4c

In this exercise, your task is to implement a binary search tree in C.

A binary search tree stores values in sorted order. For each node, smaller values are stored on the left side and larger values are stored on the right side.

Your tree should store `int` values. It should not store duplicate values.

## Files

- `tree.h` contains the public function declarations
- `tree.c` contains the implementation

The tree should hide its internal data from the user. The user should only work with a `Tree*`.

## Required functions

### `Tree* tree_create(void)`

Creates a new empty tree.

The tree should:

- start with size 0
- have no root node

Returns a pointer to the new tree.

### `void tree_insert(Tree *tree, int value)`

Adds a new value to the tree.

The tree must keep the binary search tree order:

- smaller values go to the left
- larger values go to the right

If the value already exists in the tree, do nothing.

### `void tree_remove(Tree *tree, int value)`

Removes a value from the tree.

If the value does not exist, do nothing.

The function should correctly handle removing:

- a leaf node
- a node with one child
- a node with two children
- the root node

### `int tree_check(Tree *tree, int value)`

Checks if a value exists in the tree.

Returns:

- 1 if the value is found
- 0 if the value is not found

### `int* tree_min(Tree *tree)`

Returns a pointer to the smallest value in the tree.

If the tree is empty, return `NULL`.

### `int* tree_max(Tree *tree)`

Returns a pointer to the largest value in the tree.

If the tree is empty, return `NULL`.

### `int* tree_find(Tree *tree, int value)`

Finds the smallest value in the tree that is greater than or equal to `value`.

Returns a pointer to that value.

If no such value exists, return `NULL`.

### `int tree_size(Tree *tree)`

Returns the number of values currently stored in the tree.

### `void tree_free(Tree *tree)`

Frees all memory used by the tree.

This function should free:

- all tree nodes
- the tree structure itself

## Example code

The file `local.c` contains the following code to test your tree.

```c
#include <stdio.h>
#include "tree.h"

void local_tests(void) {
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
```

Expected output:

```
Tree size: 3
Min value: 42
Max value: 1337
Contents: 42 123 1337
```

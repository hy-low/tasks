#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "linkedlist.h"

void local_tests(void) {
    // You can use this file for testing functions locally

    int n = 16;

    ArrayList *list1 = array_list_create();
    for (int i = 0; i < n; i++) {
        array_list_insert(list1, (i + 1) * 3 % n);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array_list_get(list1, i));
    }
    printf("\n");
    array_list_free(list1);

    LinkedList *list2 = linked_list_create();
    for (int i = 0; i < n; i++) {
        linked_list_insert(list2, (i + 1) * 3 % n);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", linked_list_get(list2, i));
    }
    printf("\n");
    linked_list_free(list2);
}

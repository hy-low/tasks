#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "arraylist.h"
#include "linkedlist.h"

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

int cmp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    if (x < y) return -1;
    if (x == y) return 0;
    if (x > y) return 1;
}

void test_array_list(void) {
    ArrayList *list = array_list_create();
    test_assert(array_list_size(list) == 0);
    int n = 100;
    int my_list[n];
    for (int i = 0; i < n; i++) {
        array_list_insert(list, (i + 1) * 7 % n);
        test_assert(array_list_size(list) == i + 1);
        my_list[i] = (i + 1) * 7 % n;
        qsort(my_list, i + 1, sizeof(int), cmp);
        for (int j = 0; j <= i; j++) {
            test_assert(my_list[j] == array_list_get(list, j));
        }
    }
    array_list_free(list);
}

void test_linked_list(void) {
    LinkedList *list = linked_list_create();
    test_assert(linked_list_size(list) == 0);
    int n = 100;
    int my_list[n];
    for (int i = 0; i < n; i++) {
        linked_list_insert(list, (i + 1) * 7 % n);
        test_assert(linked_list_size(list) == i + 1);
        my_list[i] = (i + 1) * 7 % n;
        qsort(my_list, i + 1, sizeof(int), cmp);
        for (int j = 0; j <= i; j++) {
            test_assert(my_list[j] == linked_list_get(list, j));
        }
    }
    linked_list_free(list);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("array list");
    test_array_list();
    test_ok();

    testing("linked list");
    test_linked_list();
    test_ok();

    printf("Set 6a OK\n");
}

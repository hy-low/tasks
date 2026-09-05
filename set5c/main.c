#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "zip.h"

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

void test1(void) {
    char *filenames[5] = {"aybabtu.txt", "large.txt", "small.txt", "test.py", "tree.pcx"};
    char *datetimes[5] = {"2026-09-04 23:05:54", "2026-09-05 14:27:14", "2026-09-05 14:26:56",
                          "2026-09-05 14:27:10", "2026-09-04 23:06:06"};
    int orig_sizes[5] = {121, 1000001, 0, 19, 422};
    int comp_sizes[5] = {101, 988, 0, 19, 216};
    int comp_methods[5] = {8, 8, 0, 0, 8};

    ZipReader *reader = zip_open("test.zip");
    test_assert(reader != NULL);
    ZipEntry *entry;
    int count = 0;
    while (entry = zip_next_entry(reader)) {
        test_assert(strcmp(entry->filename, filenames[count]) == 0);
        char modified[20];
        strftime(modified, 20, "%F %T", &entry->modified);
        test_assert(strcmp(modified, datetimes[count]) == 0);
        test_assert(entry->orig_size == orig_sizes[count]);
        test_assert(entry->comp_size == comp_sizes[count]);
        test_assert(entry->comp_method == comp_methods[count]);
        zip_free_entry(entry);
        count++;
    }
    test_assert(count == 5);
    zip_free(reader);
}

void test2(void) {
    char *filenames[1] = {"secret.bin"};
    char *datetimes[1] = {"2026-09-05 14:57:24"};
    int orig_sizes[1] = {4};
    int comp_sizes[1] = {4};
    int comp_methods[1] = {0};

    ZipReader *reader = zip_open("secret.zip");
    test_assert(reader != NULL);
    ZipEntry *entry;
    int count = 0;
    while (entry = zip_next_entry(reader)) {
        test_assert(strcmp(entry->filename, filenames[count]) == 0);
        char modified[20];
        strftime(modified, 20, "%F %T", &entry->modified);
        test_assert(strcmp(modified, datetimes[count]) == 0);
        test_assert(entry->orig_size == orig_sizes[count]);
        test_assert(entry->comp_size == comp_sizes[count]);
        test_assert(entry->comp_method == comp_methods[count]);
        zip_free_entry(entry);
        count++;
    }
    test_assert(count == 1);
    zip_free(reader);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("test.zip");
    test1();
    test_ok();

    testing("secret.zip");
    test2();
    test_ok();

    printf("Set 5c OK\n");

    return 0;
}

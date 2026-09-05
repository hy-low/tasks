#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "csv.h"

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

void test(void) {
    char *data[5][4] = {{"Pac-Man", "1980", "Eat the maze", "150"},
                        {"Donkey Kong", "1981", "Rise above the barrels", "120"},
                        {"Tetris", "1984", "Fit in or fade out", "80"},
                        {"The Legend of Zelda", "1986", "Courage opens every dungeon", "120"},
                        {"Zero Wing", "1989", "All your base are belong to us", "100"}};

    CsvReader *reader = csv_open("test.csv");
    test_assert(reader != NULL);
    CsvRecord *record;
    int count = 0;
    while (record = csv_next_record(reader)) {
        test_assert(record->count == 4);
        for (int i = 0; i < 4; i++) {
            test_assert(strcmp(record->fields[i], data[count][i]) == 0);
        }
        csv_free_record(record);
        count++;
    }
    test_assert(count == 5);
    csv_free(reader);
}

void fail(void) {
    CsvReader *reader = csv_open("fail.csv");
    test_assert(reader == NULL);
}

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("test.csv");
    test();
    test_ok();

    testing("fail.csv");
    fail();
    test_ok();

    printf("Set 5a OK\n");

    return 0;
}

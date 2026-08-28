#include <stdio.h>
#include "tasks.h"

int tests_total = 0;
int tests_accepted = 0;

void test_value_impl(char *call, long result, long expected) {
    tests_total++;
    if (result == expected) {
        tests_accepted++;
        return;
    }

    printf("Wrong answer: %s\n", call);
    printf("  Return value: %ld\n", result);
    printf("  Expected value: %ld\n", expected);
}

#define test_value(call, expected) test_value_impl(#call, call, expected)

int main(void) {
    if (tests_accepted == tests_total) {
        printf("All tests accepted, congratulations\n");
        return 0;
    } else {
        printf("%d/%d tests accepted\n", tests_accepted, tests_total);
        return 1;
    }
}

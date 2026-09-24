#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "factorial.h"

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

void test_string_impl(char *call, char *result, char *expected) {
  if (strcmp(result, expected) == 0) {
    free(result);
    return;
  }

  test_failed();
  printf("Wrong answer: %s\n", call);
  printf("  Return value: \"%s\"\n", result);
  printf("  Expected value: \"%s\"\n", expected);
  free(result);
  exit(0);
}

#define test_string(call, expected) test_string_impl(#call, call, expected)

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("factorial");
    test_string(factorial(0), "1");
    test_string(factorial(1), "1");
    test_string(factorial(2), "2");
    test_string(factorial(3), "6");
    test_string(factorial(4), "24");
    test_string(factorial(5), "120");
    test_string(factorial(10), "3628800");
    test_string(factorial(50), "30414093201713378043612608166064768844377641568960512000000000000");
    test_string(factorial(100), "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
    test_ok();

    printf("Set 6b OK\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

void local_tests(void) {
    // You can use this file for testing functions locally

    int n = 100;
    char *result = factorial(n);
    printf("The factorial of %d is %s\n", n, result);
    free(result);
}

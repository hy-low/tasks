#include <stdio.h>
#include "tasks.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    unsigned int x = 123;
    printf("Number %u has %d one bits\n", x, bit_count(x));
}

#include <stdio.h>
#include "eval.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    printf("%ld\n", eval("42*(1337+1)")); // 56196
}

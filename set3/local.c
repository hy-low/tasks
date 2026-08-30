#include <stdio.h>
#include "tasks.h"

void local_tests(void) {
    // You can use this file for testing functions locally
    char *string = "saippuakauppias";
    char *pattern = "pp";
    int result = count(string, pattern);
    printf("Pattern %s occurs %d times in %s\n", pattern, result, string);
}

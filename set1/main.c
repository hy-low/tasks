#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "tasks.h"

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

void test_value_impl(char *call, long result, long expected) {
    if (result == expected) return;

    test_failed();
    printf("Wrong answer: %s\n", call);
    printf("  Return value: %ld\n", result);
    printf("  Expected value: %ld\n", expected);
    exit(1);
}

void test_double_impl(char *call, double result, double expected) {
    if (result == expected) return;

    test_failed();
    printf("Wrong answer: %s\n", call);
    printf("  Return value: %lf\n", result);
    printf("  Expected value: %lf\n", expected);
    exit(1);
}

void test_array_impl(char *call, long result, long expected, char *context) {
    if (result == expected) return;

    test_failed();
    printf("Wrong answer: %s\n", call);
    printf("  Return value: %ld\n", result);
    printf("  Expected value: %ld\n", expected);
    printf("  Context: array = %s\n", context);
    exit(1);
}

void test_analyze_rectangle(int width, int height, long expected_area, long expected_perimeter) {
    long area, perimeter;
    analyze_rectangle(width, height, &area, &perimeter);

    if (area == expected_area && perimeter == expected_perimeter) return;

    test_failed();
    printf("Wrong answer: analyze_rectangle(%d, %d, &area, &perimeter)\n", width, height);
    printf("  Result: area = %ld, perimeter = %ld\n", area, perimeter);
    printf("  Expected: area = %ld, perimeter = %ld\n", expected_area, expected_perimeter);
    exit(1);
}

void test_week_day_name(int day, char *expected) {
    char *result = week_day_name(day);

    if (strcmp(result, expected) == 0) return;

    test_failed();
    printf("Wrong answer: week_day_name(%d)\n", day);
    printf("  Return value: \"%s\"\n", result);
    printf("  Expected value: \"%s\"\n", expected);
    exit(1);
}

void test_manhattan_distance(int x1, int y1, int x2, int y2, int expected) {
    struct Position p1 = {x1, y1};
    struct Position p2 = {x2, y2};
    int result = manhattan_distance(p1, p2);

    if (result == expected) return;

    test_failed();
    printf("Wrong answer: manhattan_distance(p1, p2)\n");
    printf("  Return value: %d\n", result);
    printf("  Expected value: %d\n", expected);
    printf("  Context: p1 = {%d, %d}, p2 = {%d, %d}\n", x1, y1, x2, y2);
    exit(1);
}

void test_fraction_sum(int a1, int b1, int a2, int b2, int a3, int b3) {
    struct Fraction f1 = {a1, b1};
    struct Fraction f2 = {a2, b2};
    struct Fraction f3 = fraction_sum(f1, f2);

    if (f3.a == a3 && f3.b == b3) return;

    test_failed();
    printf("Wrong answer: fraction_sum(f1, f2)\n");
    printf("  Return value: {%d, %d}\n", f3.a, f3.b);
    printf("  Expected value: {%d, %d}\n", a3, b3);
    printf("  Context: f1 = {%d, %d}, f2 = {%d, %d}\n", a1, b1, a2, b2);
    exit(1);
}

void test_convert_array(int *array, int n, char *context) {
    int copy[n];
    for (int i = 0; i < n; i++) copy[i] = array[i];
    convert_array(array, n);

    int fail = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] != abs(copy[i])) fail = 1;
    }

    if (!fail) return;

    test_failed();
    printf("Wrong answer: convert_array(array, %d)\n", n);
    printf("  Result: array = {");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != n-1) printf(", ");
    }
    printf("}\n");
    printf("  Expected: array = {");
    for (int i = 0; i < n; i++) {
        printf("%d", abs(copy[i]));
        if (i != n-1) printf(", ");
    }
    printf("}\n");
    printf("  Context: array = %s\n", context);
    exit(1);
}

#define test_value(call, expected) test_value_impl(#call, call, expected)
#define test_double(call, expected) test_double_impl(#call, call, expected)
#define test_array(call, expected, context) test_array_impl(#call, call, expected, context)

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    testing("calc_area");

    test_value(calc_area(1, 1), 1);
    test_value(calc_area(3, 4), 12);
    test_value(calc_area(42, 1337), 56154);
    test_value(calc_area(1000000000, 1000000000), 1e18);

    test_ok();

    testing("is_odd");

    test_value(is_odd(0), 0);
    test_value(is_odd(1), 1);
    test_value(is_odd(2), 0);
    test_value(is_odd(-1), 1);
    test_value(is_odd(42), 0);
    test_value(is_odd(1337), 1);

    test_ok();

    testing("range_sum");

    test_value(range_sum(1), 1);
    test_value(range_sum(5), 15);
    test_value(range_sum(100), 5050);
    test_value(range_sum(1000000), 500000500000L);

    test_ok();

    testing("squared_sum");

    test_value(squared_sum(1), 1);
    test_value(squared_sum(5), 55);
    test_value(squared_sum(100), 338350);
    test_value(squared_sum(1000000), 333333833333500000L);

    test_ok();

    testing("divide_apples");

    test_double(divide_apples(0), 0);
    test_double(divide_apples(1), 0.5);
    test_double(divide_apples(2), 1);
    test_double(divide_apples(42), 21);
    test_double(divide_apples(1337), 668.5);

    test_ok();

    testing("analyze_rectangle");

    test_analyze_rectangle(1, 1, 1, 4);
    test_analyze_rectangle(3, 4, 12, 14);
    test_analyze_rectangle(42, 1337, 56154, 2758);
    test_analyze_rectangle(1000000000, 1000000000, 1e18, 4e9);

    test_ok();

    testing("count_steps");

    test_value(count_steps(1), 1);
    test_value(count_steps(2), 2);
    test_value(count_steps(42), 8);
    test_value(count_steps(1337), 16);
    test_value(count_steps(1000000000), 42);

    test_ok();

    testing("week_day_name");

    test_week_day_name(1, "Monday");
    test_week_day_name(2, "Tuesday");
    test_week_day_name(3, "Wednesday");
    test_week_day_name(4, "Thursday");
    test_week_day_name(5, "Friday");
    test_week_day_name(6, "Saturday");
    test_week_day_name(7, "Sunday");

    test_ok();

    testing("digit_count");

    test_value(digit_count(0), 1);
    test_value(digit_count(1), 1);
    test_value(digit_count(42), 2);
    test_value(digit_count(1337), 4);
    test_value(digit_count(1000000000), 10);

    test_ok();

    testing("manhattan_distance");

    test_manhattan_distance(1, 1, 1, 1, 0);
    test_manhattan_distance(3, 2, 5, 1, 3);
    test_manhattan_distance(42, 1337, 1, 1e9, 999998704);

    test_ok();

    testing("fraction_sum");

    test_fraction_sum(1, 2, 1, 2, 1, 1);
    test_fraction_sum(1, 1, 1, 1, 2, 1);
    test_fraction_sum(2, 3, 5, 7, 29, 21);
    test_fraction_sum(1, 1337, 13, 42, 2489, 8022);
    test_fraction_sum(95, 1337, 96, 1337, 1, 7);

    test_ok();

    testing("array_even_count");

    {
        int array[] = {1, 2, 3};
        test_array(array_even_count(array, 3), 1, "{1, 2, 3}");
    }
    {
        int array[] = {42, 42, 42, 42};
        test_array(array_even_count(array, 4), 4, "{42, 42, 42, 42}");
    }
    {
        int array[] = {3, 1, 4, 1, 5, 9};
        test_array(array_even_count(array, 6), 1, "{3, 1, 4, 1, 5, 9}");
    }

    test_ok();

    testing("array_min_value");

    {
        int array[] = {3, 1, 4, 1, 5, 9};
        test_array(array_min_value(array, 6), 1, "{3, 1, 4, 1, 5, 9}");
    }
    {
        int array[] = {42, 42, 42, 42};
        test_array(array_min_value(array, 4), 42, "{42, 42, 42, 42}");
    }
    {
        int array[] = {1337337337};
        test_array(array_min_value(array, 1), 1337337337, "{1337337337}");
    }

    test_ok();

    testing("array_is_sorted");

    {
        int array[] = {1, 42, 1337};
        test_array(array_is_sorted(array, 3), 1, "{1, 42, 1337}");
    }
    {
        int array[] = {3, 1, 4, 1, 5, 9};
        test_array(array_is_sorted(array, 6), 0, "{3, 1, 4, 1, 5, 9}");
    }
    {
        int array[] = {1};
        test_array(array_is_sorted(array, 1), 1, "{1}");
    }
    {
        int array[] = {1, 1, 1, 1, 1, 1};
        test_array(array_is_sorted(array, 6), 1, "{1, 1, 1, 1, 1, 1}");
    }
    {
        int array[] = {1, 2, 1, 1, 1, 1};
        test_array(array_is_sorted(array, 6), 0, "{1, 2, 1, 1, 1, 1}");
    }
    {
        int array[] = {1, 1, 1, 1, 2, 1};
        test_array(array_is_sorted(array, 6), 0, "{1, 1, 1, 1, 2, 1}");
    }

    test_ok();

    testing("convert_array");

    {
        int array[] = {1, 0, -1, 5, -2, 7};
        test_convert_array(array, 6, "{1, 0, -1, 5, -2, 7}");
    }
    {
        int array[] = {-42, -1337};
        test_convert_array(array, 2, "{-42, -1337}");
    }

    test_ok();

    testing("array_distinct_count");

    {
        int array[] = {3, 1, 4, 1, 5, 9};
        test_array(array_distinct_count(array, 6), 5, "{3, 1, 4, 1, 5, 9}");
    }
    {
        int array[] = {42, 1337};
        test_array(array_distinct_count(array, 2), 2, "{42, 1337}");
    }
    {
        int array[] = {1, 1, 1, 1, 2, 1};
        test_array(array_distinct_count(array, 6), 2, "{1, 1, 1, 1, 2, 1}");
    }

    test_ok();

    testing("count_letters");

    test_value(count_letters("aybabtu", 'a'), 2);
    test_value(count_letters("aybabtu", 'u'), 1);
    test_value(count_letters("aybabtu", 'c'), 0);
    test_value(count_letters("saippuakauppias", 'p'), 4);
    test_value(count_letters("saippuakauppias", 's'), 2);

    test_ok();

    testing("count_words");

    test_value(count_words("aybabtu"), 1);
    test_value(count_words("a b c"), 3);
    test_value(count_words("all your base are belong to us"), 7);

    test_ok();

    testing("max_word_length");

    test_value(max_word_length("aybabtu"), 7);
    test_value(max_word_length("a b c"), 1);
    test_value(max_word_length("all your base are belong to us"), 6);

    test_ok();

    testing("is_palindrome");

    test_value(is_palindrome("abc"), 0);
    test_value(is_palindrome("a"), 1);
    test_value(is_palindrome("abcba"), 1);
    test_value(is_palindrome("saippuakauppias"), 1);
    test_value(is_palindrome("aybabtu"), 0);

    test_ok();

    testing("count_letters_set");

    test_value(count_letters_set("aybabtu", "a"), 2);
    test_value(count_letters_set("aybabtu", "au"), 3);
    test_value(count_letters_set("saippuakauppias", "ps"), 6);
    test_value(count_letters_set("saippuakauppias", "psa"), 10);

    test_ok();

    testing("check_anagrams");

    test_value(check_anagrams("aybabtu", "utbabya"), 1);
    test_value(check_anagrams("a", "a"), 1);
    test_value(check_anagrams("aa", "aaa"), 0);
    test_value(check_anagrams("aybabtu", "aabbtuy"), 1);
    test_value(check_anagrams("aybabtu", "aabbtty"), 0);

    test_ok();

    testing("valid_student_number");

    test_value(valid_student_number("012749138"), 0);
    test_value(valid_student_number("012749139"), 1);
    test_value(valid_student_number("013333337"), 1);
    test_value(valid_student_number("012345678"), 0);
    test_value(valid_student_number("012344550"), 1);
    test_value(valid_student_number("1337"), 0);
    test_value(valid_student_number("0127491390"), 0);
    test_value(valid_student_number("100000007"), 0);

    test_ok();

    printf("Set 1 OK\n");

    return 0;
}

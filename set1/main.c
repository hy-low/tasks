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
    test_value(range_sum(1), 1);
    test_value(range_sum(5), 15);
    test_value(range_sum(100), 5050);
    test_value(range_sum(1000000), 500000500000L);

    test_value(squared_sum(1), 1);
    test_value(squared_sum(5), 55);
    test_value(squared_sum(100), 338350);
    test_value(squared_sum(1000000), 333333833333500000L);

    test_value(digit_count(0), 1);
    test_value(digit_count(1), 1);
    test_value(digit_count(42), 2);
    test_value(digit_count(1337), 4);
    test_value(digit_count(1000000000), 10);

    int array1[] = {1, 2, 3};
    int array2[] = {5};
    int array3[] = {1, 1, 1, 1, 1};
    int array4[] = {3, 1, 4, 1, 5, 9};
    int array5[] = {2, 1};

    test_value(array_sum(array1, 3), 6);
    test_value(array_sum(array2, 1), 5);
    test_value(array_sum(array3, 5), 5);
    test_value(array_sum(array4, 6), 23);

    test_value(is_sorted(array1, 3), 1);
    test_value(is_sorted(array2, 1), 1);
    test_value(is_sorted(array3, 3), 1);
    test_value(is_sorted(array4, 5), 0);
    test_value(is_sorted(array5, 6), 0);

    test_value(count_distinct(array1, 3), 3);
    test_value(count_distinct(array2, 1), 1);
    test_value(count_distinct(array3, 5), 1);
    test_value(count_distinct(array4, 6), 5);

    test_value(is_palindrome("abc"), 0);
    test_value(is_palindrome("a"), 1);
    test_value(is_palindrome("abcba"), 1);
    test_value(is_palindrome("saippuakauppias"), 1);
    test_value(is_palindrome("aybabtu"), 0);

    test_value(count_words("aybabtu"), 1);
    test_value(count_words("a b c"), 3);
    test_value(count_words("all your base are belong to us"), 7);

    test_value(max_word_length("aybabtu"), 7);
    test_value(max_word_length("a b c"), 1);
    test_value(max_word_length("all your base are belong to us"), 6);

    test_value(check_anagrams("aybabtu", "utbabya"), 1);
    test_value(check_anagrams("a", "a"), 1);
    test_value(check_anagrams("aa", "aaa"), 0);
    test_value(check_anagrams("aybabtu", "aabbtuy"), 1);
    test_value(check_anagrams("aybabtu", "aabbtty"), 0);

    printf("%d/%d tests accepted\n", tests_accepted, tests_total);

    if (tests_accepted == tests_total) {
        return 0;
    } else {
        return 1;
    }
}

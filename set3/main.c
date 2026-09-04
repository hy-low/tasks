#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "tasks.h"

void test_value_impl(char *call, long result, long expected) {
    if (result == expected) return;

    printf("Wrong answer: %s\n", call);
    printf("  Return value: %ld\n", result);
    printf("  Expected value: %ld\n", expected);
    exit(0);
}

void test_string_impl(char *call, char *result, char *expected) {
    if (strcmp(result, expected) == 0) {
        free(result);
        return;
    }

    printf("Wrong answer: %s\n", call);
    printf("  Return value: \"%s\"\n", result);
    printf("  Expected value: \"%s\"\n", expected);
    free(result);
    exit(0);
}

void test_concat(char **array, int n, char *expected) {
    char *result = concat(array, n);
    if (strcmp(result, expected) == 0) {
        free(result);
        return;
    }

    printf("Wrong answer: concat(array, %d)\n", n);
    printf("  Return value: \"%s\"\n", result);
    printf("  Expected value: \"%s\"\n", expected);
    printf("  Context: array = {");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", array[i]);
        if (i != n - 1) printf(", ");
    }
    printf("}\n");
    free(result);
    exit(0);
}

void test_join(char **array, int n, char delimiter, char *expected) {
    char *result = join(array, n, delimiter);
    if (strcmp(result, expected) == 0) {
        free(result);
        return;
    }

    printf("Wrong answer: join(array, %d)\n", n);
    printf("  Return value: \"%s\"\n", result);
    printf("  Expected value: \"%s\"\n", expected);
    printf("  Context: array = {");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", array[i]);
        if (i != n - 1) printf(", ");
    }
    printf("}\n");
    free(result);
    exit(0);
}

void test_split(char **array, int n, char delimiter, char *string) {
    char **result;
    int count = split(string, delimiter, &result);
    if (count == n) {
        int fail = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(result[i], array[i]) != 0) {
                fail = 1;
                break;
            }
        }
        if (!fail) {
            for (int i = 0; i < n; i++) {
                free(result[i]);
            }
            free(result);
            return;
        }
    }

    printf("Wrong answer: split(\"%s\", '%c', &result)\n", string, delimiter);
    printf("  Return value: %d\n", count);
    printf("  Expected value: %d\n", n);
    printf("  Context: result = {");
    for (int i = 0; i < count; i++) {
        printf("\"%s\"", result[i]);
        if (i != count - 1) printf(", ");
    }
    printf("}\n");
    for (int i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
    exit(0);
}

void test_sort_strings(char **array, int n, char **sorted) {
    sort_strings(array, n);
    int fail = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(array[i], sorted[i]) != 0) {
            fail = 1;
            break;
        }
    }
    if (fail == 0) return;

    printf("Wrong answer: sort_strings(&array, %d)\n", n);
    printf("  Result = {");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", array[i]);
        if (i != n - 1) printf(", ");
    }
    printf("}\n");
    printf("  Expected = {");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", sorted[i]);
        if (i != n - 1) printf(", ");
    }
    printf("}\n");
    exit(0);
}

#define test_value(call, expected) test_value_impl(#call, call, expected)
#define test_string(call, expected) test_string_impl(#call, call, expected)

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    test_value(count("aybabtu", "bab"), 1);
    test_value(count("aaaaaa", "aa"), 5);
    test_value(count("aybabtu", "x"), 0);
    test_value(count("saippuakauppias", "pp"), 2);
    test_value(count("aybabtu", "aybabtu"), 1);

    test_value(starts_with("aybabtu", "ayb"), 1);
    test_value(starts_with("aybabtu", "lol"), 0);
    test_value(starts_with("aybabtu", "a"), 1);
    test_value(starts_with("aybabtu", "ayx"), 0);
    test_value(starts_with("aybabtu", "aybabtu"), 1);
    test_value(starts_with("aybabtu", "aybabtux"), 0);

    test_value(ends_with("aybabtu", "btu"), 1);
    test_value(ends_with("aybabtu", "lol"), 0);
    test_value(ends_with("aybabtu", "u"), 1);
    test_value(ends_with("aybabtu", "xtu"), 0);
    test_value(ends_with("aybabtu", "aybabtu"), 1);
    test_value(ends_with("aybabtu", "xaybabtu"), 0);

    {
        char *array[] = {"apina", "banaani", "cembalo"};
        test_concat(array, 3, "apinabanaanicembalo");
    }
    {
        char *array[] = {"all", "your", "base", "are", "belong", "to", "us"};
        test_concat(array, 7, "allyourbasearebelongtous");
    }

    test_value(find("aybabtu", "bab"), 2);
    test_value(find("aybabtu", "lol"), -1);
    test_value(find("aybabtu", "a"), 0);
    test_value(find("aybabtu", "u"), 6);
    test_value(find("aybabtu", "aybabtu"), 0);
    test_value(find("aybabtu", "aybabtux"), -1);

    test_string(repeat("abc", 4), "abcabcabcabc");
    test_string(repeat("aybabtu", 1), "aybabtu");
    test_string(repeat("aybabtu", 0), "");
    test_string(repeat("a", 20), "aaaaaaaaaaaaaaaaaaaa");

    test_string(trim(" aybabtu   "), "aybabtu");
    test_string(trim("aybabtu"), "aybabtu");
    test_string(trim("    aybabtu    "), "aybabtu");
    test_string(trim("    ayb abtu    "), "ayb abtu");
    test_string(trim("   "), "");

    test_string(upper("aybabtu"), "AYBABTU");
    test_string(upper("AyBaBtU"), "AYBABTU");
    test_string(upper("AYBABTU"), "AYBABTU");
    test_string(upper(""), "");
    test_string(upper("abcdefghijklmnopqrstuvwxyz"), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    test_string(lower("AYBABTU"), "aybabtu");
    test_string(lower("AyBaBtU"), "aybabtu");
    test_string(lower("aybabtu"), "aybabtu");
    test_string(lower(""), "");
    test_string(lower("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), "abcdefghijklmnopqrstuvwxyz");

    test_string(substr("aybabtu", 2, 3), "bab");
    test_string(substr("aybabtu", 10, 3), "");
    test_string(substr("aybabtu", 2, 10), "babtu");
    test_string(substr("aybabtu", 0, 1), "a");
    test_string(substr("aybabtu", 6, 1), "u");

    test_string(replace("aybabtu", "bab", "lol"), "ayloltu");
    test_string(replace("aa", "a", "aa"), "aaaa");
    test_string(replace("aaaa", "aa", "a"), "aa");
    test_string(replace("aaaa", "a", ""), "");
    test_string(replace("aybabtu", "a", "lol"), "lolyblolbtu");
    test_string(replace("aybabtu", "x", "lol"), "aybabtu");
    test_string(replace("aybabtu", "aybabtu", "lol"), "lol");
    test_string(replace("abababababababab", "aba", "baa"), "baabbaabbaabbaab");

    test_string(rot13("aybabtu"), "nlonogh");
    test_string(rot13("AYBABTU"), "NLONOGH");
    test_string(rot13("saippukauppias"), "fnvcchxnhccvnf");
    test_string(rot13("All your base are belong to us."), "Nyy lbhe onfr ner orybat gb hf.");

    {
        char *array[] = {"apina", "banaani", "cembalo"};
        test_join(array, 3, '|', "apina|banaani|cembalo");
    }
    {
        char *array[] = {"all", "your", "base", "are", "belong", "to", "us"};
        test_join(array, 7, ' ', "all your base are belong to us");
    }

    {
        char *array[] = {"apina", "banaani", "cembalo"};
        test_split(array, 3, '|', "apina|banaani|cembalo");
    }
    {
        char *array[] = {"all", "your", "base", "are", "belong", "to", "us"};
        test_split(array, 7, ' ', "all your base are belong to us");
    }

    {
        char *array[] = {"all", "your", "base", "are", "belong", "to", "us"};
        char *sorted[] = {"all", "are", "base", "belong", "to", "us", "your"};
        test_sort_strings(array, 7, sorted);
    }
    {
        char *array[] = {"aaaaa", "aaaa", "aaa", "aa", "a"};
        char *sorted[] = {"a", "aa", "aaa", "aaaa", "aaaaa"};
        test_sort_strings(array, 5, sorted);
    }

    printf("Set 3 OK\n");
}

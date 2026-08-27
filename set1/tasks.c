/*
 * Counts the sum of integers between 1 and n.
 *
 * Parameters:
 *   n: positive integer
 *
 * Return value:
 *   sum of integers from 1 through n
 *
 * Examples:
 *   range_sum(5) -> 15
 *   range_sum(10) -> 55
 */
long range_sum(int n) {
    // TODO
    return -1;
}

/*
 * Counts the sum of squares of integers between 1 and n.
 *
 * Parameters:
 *   n: positive integer
 *
 * Return value:
 *   sum of squares from 1^2 through n^2
 *
 * Examples:
 *   squared_sum(3) -> 14
 *   squared_sum(5) -> 55
 */
long squared_sum(int n) {
    // TODO
    return -1;
}

/*
 * Counts the number of digits in the given integer.
 *
 * Parameters:
 *   n: integer between 1 and 10^9
 *
 * Return value:
 *   number of digits
 *
 * Examples:
 *   digit_count(42) -> 2
 *   digit_count(123) -> 3
 */
int digit_count(int n) {
    // TODO
    return -1;
}

/*
 * Counts the sum of numbers in the array.
 *
 * Parameters:
 *   array: pointer to an integer array
 *   n: number of elements in the array
 *
 * Return value:
 *   sum of all array elements
 *
 * Examples:
 *   array_sum({1, 2, 3}, 3) -> 6
 *   array_sum({5, 2, 1, 2}, 4) -> 10
 */
long array_sum(int *array, int n) {
    // TODO
    return -1;
}

/*
 * Checks if the given array is sorted.
 *
 * Parameters:
 *   array: pointer to an integer array
 *   n: number of elements in the array
 *
 * Return value:
 *   1 if the array is sorted, 0 otherwise
 *
 * Examples:
 *   is_sorted({1, 2, 3}, 3) -> 1
 *   is_sorted({3, 2, 1}, 3) -> 0
 */
int is_sorted(int *array, int n) {
    // TODO
    return -1;
}

/*
 * Counts the number of distinct values in the array.
 *
 * Parameters:
 *   array: pointer to an integer array
 *   n: number of elements in the array
 *
 * Return value:
 *   number of distinct values
 *
 * Examples:
 *   count_distinct({1, 2, 2, 3}, 4) -> 3
 *   count_distinct({5, 5, 5}, 3)    -> 1
 */
int count_distinct(int *array, int n) {
    // TODO
    return -1;
}

/*
 * Checks if the given word is a palindrome.
 *
 * Parameters:
 *   word: string consisting of characters a..z
 *
 * Return value:
 *   1 if the string is a palindrome, 0 otherwise
 *
 * Examples:
 *   is_palindrome("abcba") -> 1
 *   is_palindrome("aybabtu") -> 0
 */
int is_palindrome(char *word) {
    int length = 0;

    while (word[length] != '\0') {
        length++;
    }

    int left = 0;
    int right = length - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

/*
 * Counts the number of words in the given string.
 *
 * Words are separated by single spaces.
 *
 * Parameters:
 *   words: string consisting of characters a..z and spaces
 *
 * Return value:
 *   number of words in the string
 *
 * Examples:
 *   count_words("apina banaani cembalo") -> 3
 *   count_words("  a  ab abc  ") -> 3
 */
int count_words(char *words) {
    // TODO
    return -1;
}

/*
 * Finds the length of the longest word in the given string.
 *
 * The words are separated by single spaces.
 *
 * Parameters:
 *   words: string consisting of characters a..z and spaces
 *
 * Return value:
 *   length of the longest word in the string
 *
 * Examples:
 *   max_word_length("apina banaani cembalo") -> 7
 *   max_word_length("a ab abc") -> 3
 */
int max_word_length(char *words) {
    // TODO
    return -1;
}

/*
 * Checks if two words are anagrams of each other.
 *
 * The words must contain exactly the same characters
 * the same number of times.
 *
 * Parameters:
 *   word1: string consisting of characters a..z
 *   word2: string consisting of characters a..z
 *
 * Return value:
 *   1 if the words are anagrams, 0 otherwise
 *
 * Examples:
 *   check_anagrams("abab", "baba") -> 1
 *   check_anagrams("abab", "abca") -> 0
 *   check_anagrams("a", "aybabtu") -> 0
 */
int check_anagrams(char *word1, char *word2) {
    // TODO
    return -1;
}

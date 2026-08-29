#include "tasks.h"

// Calculates the area of a rectangle
// Example: calc_area(2, 3) -> 6
long calc_area(int width, int height) {
    // TODO
}

// Checks if an integer is odd
// Example: is_odd(5) -> 1
// Example: is_odd(6) -> 0
int is_odd(int n) {
    // TODO
}

// Counts the sum of integers between 1 and n
// Example: range_sum(5) -> 15
long range_sum(int n) {
    // TODO
}

// Counts the sum of squares between 1 and n
// Example: squared_sum(5) -> 55
long squared_sum(int n) {
    // TODO
}

// Divides n apples evenly for two persons
// Example: divide_apples(5) -> 2.5
// Example: divide_apples(6) -> 3
double divide_apples(int n) {
    // TODO
}

// Calculates rectangle area and perimeter
//   - Results are returned through pointers
// Example: analyze_rectangle(3, 4, &area, &perimeter)
//   - area -> 12
//   - perimeter -> 14
void analyze_rectangle(int width, int height, long *area, long *perimeter) {
    // TODO
}

// Counts the steps in the following process:
//   - If n is even, divide it by two
//   - If n is odd, subtract one
//   - If n is zero, stop
// Example: count_steps(10) -> 5 (10 -> 5 -> 4 -> 2 -> 1 -> 0)
int count_steps(int n) {
    // TODO
}

// Returns the week day name in English
//   - day is between 1 and 7
// Example: week_day_name(1) -> "Monday"
// Example: week_day_name(2) -> "Tuesday"
char* week_day_name(int day) {
    // TODO
}

// Counts the number of digits in the given integer
//   - You can assume that n is nonnegative
// Example: digit_count(123) -> 3
int digit_count(int n) {
    // TODO
}

// Calculates the Manhattan distance between two positions
//   - Formula: |x1 - x2| + |y1 - y2| where |...| is absolute value
// Example: p1 = {2, 3}, p2 = {1, 5} -> |2 - 1| + |3 - 5| = 3
int manhattan_distance(struct Position p1, struct Position p2) {
    // TODO
}

// Calculates the sum of two fractions
//   - Return the result in simplest form
// Example: f1 = {1, 4}, f2 = {1, 12} -> {1, 3}
struct Fraction fraction_sum(struct Fraction f1, struct Fraction f2) {
    // TODO
}

// Counts the number of even numbers in the array
// Example: {2, 1, 2, 4, 5} -> 3
int array_even_count(int *array, int n) {
    // TODO
}

// Finds the minimum value in the array
// Example: {2, 1, 2, 4, 5} -> 1
int array_min_value(int *array, int n) {
    // TODO
}

// Checks if the given array is sorted
// Example: {1, 3, 2, 4} -> 0
// Example: {1, 2, 2, 5} -> 1
int array_is_sorted(int *array, int n) {
    // TODO
}

// Converts all array values to absolute values
// Example: {1, -1, -5, 0} -> {1, 1, 5, 0}
void convert_array(int *array, int n) {
    // TODO
}

// Counts the number of distinct values in the array
// Example: {1, 2, 1, 5, 2} -> 3
int array_distinct_count(int *array, int n) {
    // TODO
}

// Counts the number of times a letter appears in a string
// Example: count_letters("aybabtu", 'a') -> 2
int count_letters(char *string, char letter) {
    // TODO
}

// Counts the number of words in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 3
int count_words(char *words) {
    // TODO
}

// Finds the maximum word length in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 4
int max_word_length(char *words) {
    // TODO
}

// Checks if the given word is a palindrome
//   - The word consists of letters a..z
// Example: is_palindrome("abba") -> 1
// Example: is_palindrome("abca") -> 0
int is_palindrome(char *word) {
    // TODO
}

// Counts the number of times any letter appears in a string
// Example: count_letters("aybabtu", "au") -> 3
int count_letters_set(char *string, char *letters) {
    // TODO
}

// Checks if two words are anagrams of each other
//   - The words consist of letters a..z
// Example: check_anagrams("abca", "aacb") -> 1
// Example: check_anagrams("abca", "abcb") -> 0
int check_anagrams(char *word1, char *word2) {
    // TODO
}

// Checks a University of Helsinki student number
//   - The number consists of nine digits 0-9 and the first digit is 0
//   - The last digit is a checksum calculated from other digits
//   - The checksum is calculated as a sum using the weights {3,7,1,3,7,1,3,7}
//   - If the result is divisible by 10, the checksum is 0
//   - Otherwise the checksum is the distance to the next multiple of ten
// Example: consider 012749139
//   - The format of the number is correct (nine digits, first digit 0)
//   - Let's calculate the checksum: 3*0+7*1+1*2+3*7+7*4+1*9+3*1+7*3 = 91
//   - The distance to the next multiple of ten is 9
//   - The checksum matches the last digit, so the number is valid
int valid_student_number(char *number) {
    // TODO
}

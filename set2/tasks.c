#include "tasks.h"

// Counts the number of one bits in x
// Example: bit_count(123) -> 6
//    123 = 1111011
int bit_count(unsigned int x) {
    // TODO
}

// Returns the parity of x
//   - If x has an even number of one bits, return 0
//   - If x has an odd number of one bits, return 1
// Example: parity(123) -> 0
//    123 = 1111011
int parity(unsigned int x) {
    // TODO
}

// Returns the bit at position pos
//   - Bit at position 0 is the least significant bit
// Example: get_bit(123, 0) -> 1
// Example: get_bit(123, 2) -> 0
//   123 = 1111011
//             ^ ^
int get_bit(unsigned int x, int pos) {
    // TODO
}

// Sets the bit at position pos to 1
// Example: set_bit(123, 2) -> 127
//   123 = 1111011
//   127 = 1111111
unsigned int set_bit(unsigned int x, int pos) {
    // TODO
}

// Sets the bit at position pos to 0
// Example: clear_bit(123, 0) -> 122
//   123 = 1111011
//   122 = 1111010
unsigned int clear_bit(unsigned int x, int pos) {
    // TODO
}

// Flips the bit at position pos
// Example: flip_bit(123, 0) -> 122
// Example: flip_bit(123, 2) -> 127
//   123 = 1111011
//   122 = 1111010
//   127 = 1111111
unsigned int flip_bit(unsigned int x, int pos) {
    // TODO
}

// Returns the position of the highest one bit
//   - You can assume that x != 0
// Example: highest_bit_pos(42) -> 5
//   42 = 101010
//        ^
int highest_bit_pos(unsigned int x) {
    // TODO
}

// Returns the position of the lowest one bit
//   - You can assume that x != 0
// Example: lowest_bit_pos(42) -> 1
//   42 = 101010
//            ^
int lowest_bit_pos(unsigned int x) {
    // TODO
}

// Sets the lowest one bit to zero
// Example: clear_lowest_bit(42) -> 40
//   42 = 101010
//   40 = 101000
unsigned int clear_lowest_bit(unsigned int x) {
    // TODO
}

// Returns 1 if x is a power of two, otherwise returns 0
// Example: is_power_of_two(16) -> 1
// Example: is_power_of_two(17) -> 0
int is_power_of_two(unsigned int x) {
    // TODO
}

// Counts the number of bit positions where a and b have the same bit
// Example: common_bit_count(42, 1337) -> 27
//     42 = 00000000000000000000000000101010
//   1337 = 00000000000000000000010100111001
//          ^^^^^^^^^^^^^^^^^^^^^ ^ ^^^ ^^
int common_bit_count(unsigned int a, unsigned int b) {
    // TODO
}

// Rotates all 32 bits of x one position to the left
//   - The highest bit wraps around to the lowest bit
// Example: rotate_left(3333333333) -> 2371699371
//   3333333333 = 11000110101011101010000101010101
//   2371699371 = 10001101010111010100001010101011
unsigned int rotate_left(unsigned int x) {
    // TODO
}

// Rotates all 32 bits of x one position to the right
//   - The lowest bit wraps around to the highest bit
// Example: rotate_right(3333333333) -> 3814150314
//   3333333333 = 11000110101011101010000101010101
//   3814150314 = 11100011010101110101000010101010
unsigned int rotate_right(unsigned int x) {
    // TODO
}

// Flips all 32 bits of x
// Example: flip_all_bits(1337) -> 4294965958
//         1337 = 00000000000000000000010100111001
//   4294965958 = 11111111111111111111101011000110
unsigned int flip_all_bits(unsigned int x) {
    // TODO
}

// Swaps every pair of adjacent bits
// Example: swap_adjacent_bits(1337) -> 2614
//   1337 = 10100111001
//   2614 = 10011100101
unsigned int swap_adjacent_bits(unsigned int x) {
    // TODO
}

// Reverses the order of all bits of x
// Example: reverse_bits(1337) -> 2627731456
//         1337 = 00000000000000000000010100111001
//   2627731456 = 10011100101000000000000000000000
unsigned int reverse_bits(unsigned int x) {
    // TODO
}

// Returns 1 ^ 2 ^ 3 ^ ... ^ n.
// Example: xor_sum(5) -> 1
long xor_sum(int n) {
    // TODO
}

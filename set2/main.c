#include <stdio.h>
#include <stdlib.h>
#include "local.h"
#include "tasks.h"

void test_value_impl(char *call, long result, long expected) {
    if (result == expected) return;

    printf("Wrong answer: %s\n", call);
    printf("  Return value: %ld\n", result);
    printf("  Expected value: %ld\n", expected);
    exit(0);
}

#define test_value(call, expected) test_value_impl(#call, call, expected)

int main(void) {
    printf("Local tests:\n");
    printf("****************************************\n");

    local_tests();

    printf("\n\nServer tests:\n");
    printf("****************************************\n");

    test_value(bit_count(0), 0);
    test_value(bit_count(1), 1);
    test_value(bit_count(42), 3);
    test_value(bit_count(1337), 6);
    test_value(bit_count(123456789), 16);
    test_value(bit_count(987654321), 17);
    test_value(bit_count(3333333333), 16);

    test_value(parity(0), 0);
    test_value(parity(1), 1);
    test_value(parity(42), 1);
    test_value(parity(1337), 0);
    test_value(parity(123456789), 0);
    test_value(parity(987654321), 1);
    test_value(parity(3333333333), 0);

    test_value(get_bit(1337, 0), 1);
    test_value(get_bit(1337, 1), 0);
    test_value(get_bit(1337, 2), 0);
    test_value(get_bit(1337, 3), 1);
    test_value(get_bit(3333333333, 0), 1);
    test_value(get_bit(3333333333, 1), 0);
    test_value(get_bit(3333333333, 30), 1);
    test_value(get_bit(3333333333, 31), 1);

    test_value(set_bit(1337, 0), 1337);
    test_value(set_bit(1337, 1), 1339);
    test_value(set_bit(1337, 2), 1341);
    test_value(set_bit(1337, 3), 1337);
    test_value(set_bit(3333333333, 0), 3333333333);
    test_value(set_bit(3333333333, 1), 3333333335);
    test_value(set_bit(3333333333, 29), 3870204245);
    test_value(set_bit(3333333333, 31), 3333333333);

    test_value(clear_bit(1337, 0), 1336);
    test_value(clear_bit(1337, 1), 1337);
    test_value(clear_bit(1337, 2), 1337);
    test_value(clear_bit(1337, 3), 1329);
    test_value(clear_bit(3333333333, 0), 3333333332);
    test_value(clear_bit(3333333333, 1), 3333333333);
    test_value(clear_bit(3333333333, 30), 2259591509);
    test_value(clear_bit(3333333333, 31), 1185849685);

    test_value(flip_bit(1337, 0), 1336);
    test_value(flip_bit(1337, 1), 1339);
    test_value(flip_bit(1337, 2), 1341);
    test_value(flip_bit(1337, 3), 1329);
    test_value(flip_bit(3333333333, 0), 3333333332);
    test_value(flip_bit(3333333333, 1), 3333333335);
    test_value(flip_bit(3333333333, 29), 3870204245);
    test_value(flip_bit(3333333333, 31), 1185849685);

    test_value(highest_bit_pos(1), 0);
    test_value(highest_bit_pos(42), 5);
    test_value(highest_bit_pos(1337), 10);
    test_value(highest_bit_pos(3333333333), 31);

    test_value(lowest_bit_pos(1), 0);
    test_value(lowest_bit_pos(42), 1);
    test_value(lowest_bit_pos(1337), 0);
    test_value(lowest_bit_pos(3333333333), 0);
    test_value(lowest_bit_pos(1024), 10);
    test_value(lowest_bit_pos(1<<31), 31);

    test_value(clear_lowest_bit(1), 0);
    test_value(clear_lowest_bit(42), 40);
    test_value(clear_lowest_bit(1337), 1336);
    test_value(clear_lowest_bit(3333333333), 3333333332);
    test_value(clear_lowest_bit(1536), 1024);
    test_value(clear_lowest_bit(1U<<31), 0);

    test_value(is_power_of_two(1), 1);
    test_value(is_power_of_two(2), 1);
    test_value(is_power_of_two(3), 0);
    test_value(is_power_of_two(4), 1);
    test_value(is_power_of_two(13), 0);
    test_value(is_power_of_two(16), 1);
    test_value(is_power_of_two(1023), 0);
    test_value(is_power_of_two(1024), 1);
    test_value(is_power_of_two(1025), 0);
    test_value(is_power_of_two((1U<<31)-1), 0);
    test_value(is_power_of_two(1U<<31), 1);
    test_value(is_power_of_two((1U<<31)+1), 0);

    test_value(common_bit_count(0, 0), 32);
    test_value(common_bit_count(42, 1337), 27);
    test_value(common_bit_count(2222222222, 3333333333), 15);
    test_value(common_bit_count(1U<<31, (1U<<31)-1), 0);

    test_value(rotate_left(1), 2);
    test_value(rotate_left(42), 84);
    test_value(rotate_left(3333333333), 2371699371);

    test_value(rotate_right(1), 1U<<31);
    test_value(rotate_right(42), 21);
    test_value(rotate_right(3333333333), 3814150314);

    test_value(flip_all_bits(1), 4294967294);
    test_value(flip_all_bits(42), 4294967253);
    test_value(flip_all_bits(1337), 4294965958);
    test_value(flip_all_bits(3333333333), 961633962);

    test_value(swap_adjacent_bits(1), 2);
    test_value(swap_adjacent_bits(42), 21);
    test_value(swap_adjacent_bits(1337), 2614);
    test_value(swap_adjacent_bits(3333333333), 3378336426);

    test_value(reverse_bits(1), 2147483648);
    test_value(reverse_bits(42), 1409286144);
    test_value(reverse_bits(1337), 2627731456);
    test_value(reverse_bits(3333333333), 2860873059);

    test_value(xor_sum(1), 1);
    test_value(xor_sum(2), 3);
    test_value(xor_sum(42), 43);
    test_value(xor_sum(1337), 1);
    test_value(xor_sum(13371337), 1);
    test_value(xor_sum(42424242), 42424243);

    printf("OK\n");
}

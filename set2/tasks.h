int bit_count(unsigned int x);
int parity(unsigned int x);

int get_bit(unsigned int x, int pos);
unsigned int set_bit(unsigned int x, int pos);
unsigned int clear_bit(unsigned int x, int pos);
unsigned int flip_bit(unsigned int x, int pos);

int highest_bit_pos(unsigned int x);
int lowest_bit_pos(unsigned int x);
unsigned int clear_lowest_bit(unsigned int x);
int is_power_of_two(unsigned int x);
int common_bit_count(unsigned int a, unsigned int b);

unsigned int rotate_left(unsigned int x);
unsigned int rotate_right(unsigned int x);

unsigned int flip_all_bits(unsigned int x);
unsigned int swap_adjacent_bits(unsigned int x);
unsigned int reverse_bits(unsigned int x);

int missing(int *array, int n);
int only_one(int *array, int n);
long xor_sum(int n);

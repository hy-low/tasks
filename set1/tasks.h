struct Position {
    int x, y;
};

struct Fraction {
    int a, b;
};

long calc_area(int width, int height);
int is_odd(int n);
long range_sum(int n);
long squared_sum(int n);
double divide_apples(int n);
void analyze_rectangle(int width, int height, long *area, long *perimeter);
int count_steps(int n);
char* week_day_name(int day);
int digit_count(int n);
int manhattan_distance(struct Position p1, struct Position p2);
struct Fraction fraction_sum(struct Fraction f1, struct Fraction f2);
int array_even_count(int *array, int n);
int array_min_value(int *array, int n);
int array_is_sorted(int *array, int n);
void convert_array(int *array, int n);
int array_distinct_count(int *array, int n);
int count_letters(char *string, char letter);
int count_words(char *words);
int max_word_length(char *words);
int is_palindrome(char *word);
int count_letters_set(char *string, char *letters);
int check_anagrams(char *word1, char *word2);
int valid_student_number(char *number);

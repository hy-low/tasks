#include <stdio.h>

int is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

void create_array(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
}

double harmonic_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

int month_days(int month) {
    switch (month) {
        case 2:
            return 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

int sum8(int a, int b, int c, int d, int e, int f, int g, int h) {
    return a + b + c + d + e + f + g + h;
}

struct Struct8 {
    int a, b, c, d, e, f, g, h;
};

int sum8_struct(struct Struct8 s) {
    return s.a + s.b + s.c + s.d + s.e + s.f + s.g + s.h;
}

struct Struct8 create_struct(void) {
    struct Struct8 s = {3, 1, 4, 1, 5, 9, 2, 6};
    return s;
}

int main(void) {
    printf("%d\n", is_leap_year(2026)); // 0
    printf("%d\n", is_leap_year(2027)); // 0
    printf("%d\n", is_leap_year(2028)); // 1
    printf("%d\n", is_leap_year(1900)); // 0
    printf("%d\n", is_leap_year(2000)); // 1

    int n = 10;
    int array[n];
    create_array(array, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("%lf\n", harmonic_sum(1)); // 1.000000
    printf("%lf\n", harmonic_sum(2)); // 1.500000
    printf("%lf\n", harmonic_sum(5)); // 2.283333
    printf("%lf\n", harmonic_sum(10)); // 2.928968

    printf("%d\n", month_days(1)); // 31
    printf("%d\n", month_days(2)); // 28
    printf("%d\n", month_days(3)); // 31
    printf("%d\n", month_days(4)); // 30

    printf("%d\n", sum8(1, 2, 3, 4, 5, 6, 7, 8)); // 36

    struct Struct8 s = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d\n", sum8_struct(s)); // 36
    s = create_struct();
    printf("%d\n", sum8_struct(s)); // 31
}

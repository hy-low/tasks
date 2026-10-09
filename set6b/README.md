# Set 6b

This task deals with handling big integers in C. More specifically, your task is to implement a function

```c
char* factorial(int n);
```

that calculates the factorial of a given integer `n` and returns it as a string.
**Note: you may only use the C standard library in your own implementation, do not use GMP.**

For example, the output of the code

```c
int n = 100;
printf("The factorial of %d is %s\n", n, factorial(n));
```

should be as follows:

```
The factorial of 100 is 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
```

Your function should reserve memory dynamically, and the caller of the function must free the memory.

## Experiment

This is an experimental task where you should compare three methods for calculating factorials:

- Your implemented `factorial` function
- A C implementation using the GMP library (see Chapter 7 in the course material)
- A Python implementation using built-in Python big integers

Suggested approach:
- Implement a factorial_gmp.c which conforms to the factorial.h header.
- Implement a factorial_main.c which takes `n` as a command line argument and calls `factorial` (see Chapter 1).
- Edit the Makefile to compile factorial_main.c and factorial_gmp.c (Chapter 7)
- Edit the Makefile to link two programs: factorial and factorial_gmp, using the two different factorial*.o files, respectively.
- Finally, implement a factorial.py.

For each implementation, try to estimate the maximum value of `n` that you can process within one minute.
**Measuring the program execution times and adjusting `n` via manual trial and error is sufficient**,
but more sophisticated approximations, such as [log-log](https://en.wikipedia.org/wiki/Power_law) linear regression, may be utilized.

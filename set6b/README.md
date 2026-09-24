# Set 6b

This task deals with handling big integers in C. More specifically, your task is to implement a function

```c
char* factorial(int n);
```

that calculates the factorial of a given integer `n` and returns it as a string. For example, the output of the code

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

For each implementation, find out the maximum value of `n` that you can process within one minute.

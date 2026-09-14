# Set 10

In this exercise, your task is to create an assembly subprogram that evaluates a mathematical expression.

The C function signature is as follows:

```c
unsigned long eval(const char *expr);
```

Example code:

```c
printf("%ld\n", eval("42*(1337+1)")); // 56196
```

## Definition

In the context of this exercise, a valid expression is defined as follows:

- A nonnegative integer is an expression.
- If `A` and `B` are expressions, then `A+B` and `A*B` are also expressions.
- If `X` is an expression, then `(X)` is also an expression.

For example, `42`, `1+1` and `42*(1337+1)` are valid expressions.

## Input checks

Your subprogram should return an error value 0 if:

- The given string is not a valid expression (for example, `42+`, `()` or `aybabtu`).
- The value of the expression (or a subexpression) is greater than 2<sup>64</sup>–1 (the maximum `unsigned long` value).
- The expression contains a number with a leading zero (for example, `042` is not a valid number).

Note that the return value 0 is ambiguous because it may also be the value of a valid expression (for example, the expression `1*0` is valid and its value is 0).

## Remarks

- You must not modify the parameter string (declared with the `const` keyword).
- You can use the `jc` instruction to check for overflows.
- Local label names using dot syntax, such as `.loop` and `.fail`, can be useful.
- You may assume that the input string is not very long: for example, an O(_n_<sup>2</sup>) algorithm is efficient enough.

# Low-level programming exercises

This repository contains the exercises for the University of Helsinki course _Low-level programming_.

Each exercise set is structured as follows:

- The file `tasks.c` contains the functions you need to implement.
- The file `main.c` contains the main function, which tests your functions.
- You can place your own test code in the file `local.c`, for example to test individual functions.
- The command `make` compiles the files, and the command `./main` runs the tests and displays their results.

Example (set 1):

```console
$ make
$ ./main
Local tests:
****************************************
42 is odd


Server tests:
****************************************
Wrong answer: calc_area(1, 1)
  Return value: 41
  Expected value: 1
```

When you have successfully implemented all the functions in a given exercise set, you can submit to [CSES](https://cses.fi/low/list/) a zip file containing all the files in that set's directory.

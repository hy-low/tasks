# Set 5a

In this exercise, your task is to read content from a CSV file. For example, here is a CSV file that consists of five records (lines):

```
Pac-Man,1980,Eat the maze,150
Donkey Kong,1981,Rise above the barrels,120
Tetris,1984,Fit in or fade out,80
The Legend of Zelda,1986,Courage opens every dungeon,120
Zero Wing,1989,All your base are belong to us,100
```

In this case, each record consists of four fields: name, year, description and price.

You can assume that:

- Each record consists of fields separated by commas (`,`)
- The escape character `"` is not used in the tests, which means that simple processing is enough (however, this will change in Set 5b)
- All newlines are Unix newlines (`\n`)

You have to check that each record has the same number of fields.

## Files

- `csv.h` contains the public function declarations
- `csv.c` contains the implementation

## Required functions

### `CsvReader* csv_open(char *filename)`

Creates a CSV reader for a given file, and returns a pointer to the reader.

The function should return `NULL` if:

- It can't open the file
- The format of the file is not correct, i.e., each record has not the same number of fields

### `CsvRecord* csv_next_record(CsvReader *reader)`

Returns a pointer to a `CsvRecord` struct that corresponds to a single record in the file. The struct type is defined in `csv.h`.

Each function call should return the next record. If no more records are available, return `NULL`. The function should reserve memory and the caller should free the memory.

### `void csv_free_record(CsvRecord *record)`

Frees the memory reserved for a `CsvRecord` struct.

### `void csv_free(CsvReader *reader)`

Frees the memory reserved for a `CsvReader` struct.

## Example code

The file `local.c` contains the following code to test your implementation.

```c
void local_tests(void) {
    CsvReader *reader = csv_open("test.csv");
    CsvRecord *record;
    int count = 0;
    while (record = csv_next_record(reader)) {
        count++;
        printf("\n");
        printf("Record %d\n", count);
        for (int i = 0; i < record->count; i++) {
            printf("Field %d: %s\n", i + 1, record->fields[i]);
        }
        csv_free_record(record);
    }
    csv_free(reader);
}
```

Expected output:

```
Record 1
Field 1: Pac-Man
Field 2: 1980
Field 3: Eat the maze
Field 4: 150

Record 2
Field 1: Donkey Kong
Field 2: 1981
Field 3: Rise above the barrels
Field 4: 120

Record 3
Field 1: Tetris
Field 2: 1984
Field 3: Fit in or fade out
Field 4: 80

Record 4
Field 1: The Legend of Zelda
Field 2: 1986
Field 3: Courage opens every dungeon
Field 4: 120

Record 5
Field 1: Zero Wing
Field 2: 1989
Field 3: All your base are belong to us
Field 4: 100
```

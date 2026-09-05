# Set 5b

In this exercise, your task is to extend your CSV reader so that it also supports double quotes as escape characters. Here is a more complex CSV file to test that your reader works correctly:

```
Pac-Man,1980,"One, two, three",150
Donkey Kong,1981,"",120
Tetris,1984,"Blocks fall, ""panic"" rises",80
The Legend of Zelda,1986,"Courage ""opens"" every dungeon",120
Zero Wing,1989,"All your base
are belong to us",100
```

Escaping is done as follows:

- If a value contains a comma `,`, a double quote `"` or a newline, the value should be enclosed in double quotes.
- If a value contains a double quote, the double quote should be repeated (for example, `"Blocks fall, ""panic"" rises"` means `Blocks fall, "panic" rises`).
- You can always enclose a value in double quotes, even if it would not be necessary.

## Files

- `csv.h` contains the public function declarations
- `csv.c` contains the implementation

## Required functions

### `CsvReader* csv_open(char *filename)`

Creates a CSV reader for a given file, and returns a pointer to the reader.

The function should return `NULL` if:

- It can't open the file
- The format of the file is not correct (each record has not the same number of fields, or double quotes are incorrectly)

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
    CsvReader *reader = csv_open("test2.csv");
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
Field 3: One, two, three
Field 4: 150

Record 2
Field 1: Donkey Kong
Field 2: 1981
Field 3: 
Field 4: 120

Record 3
Field 1: Tetris
Field 2: 1984
Field 3: Blocks fall, "panic" rises
Field 4: 80

Record 4
Field 1: The Legend of Zelda
Field 2: 1986
Field 3: Courage "opens" every dungeon
Field 4: 120

Record 5
Field 1: Zero Wing
Field 2: 1989
Field 3: All your base
are belong to us
Field 4: 100
```

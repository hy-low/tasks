# Set 5c

In this exercise, your task is to read content from a ZIP file. You should read information about the files that are stored in the file. However, you don't have to _extract_ the compressed data.

You can use online sources (such as Wikipedia) to learn about the ZIP file format structure.

You don't have to support anything fancy (such as ZIP64 or extra fields). Note that file modification time/date is stored using an old MS-DOS format and you have to convert it to a `tm` struct (defined in `time.h`).

## Files

- `zip.h` contains the public function declarations
- `zip.c` contains the implementation

## Required functions

### `ZipReader* zip_open(char *filename)`

Creates a ZIP reader for a given file, and returns a pointer to the reader.

The function should return `NULL` if:

- It can't open the file
- It can't find the list of files inside the ZIP file

### `ZipEntry* zip_next_entry(ZipReader *reader)`

Returns a pointer to a `ZipEntry` struct that corresponds to a single file inside the ZIP file. The struct type is defined in `zip.h`.

Each function call should return the next entry. If no more entries are available, return `NULL`. The function should reserve memory and the caller should free the memory.

### `void zip_free_entry(ZipEntry *entry)`

Frees the memory reserved for a `ZipEntry` struct.

### `void zip_free(ZipReader *reader)`

Frees the memory reserved for a `ZipReader` struct.

## Example code

The file `local.c` contains the following code to test your implementation.

```c
void local_tests(void) {
    ZipReader *reader = zip_open("test.zip");
    ZipEntry *entry;
    int count = 0;
    while (entry = zip_next_entry(reader)) {
        count++;
        printf("\nFile %d: %s\n", count, entry->filename);

        char modified[20];
        strftime(modified, 20, "%F %T", &entry->modified);
        printf("Modified: %s\n", modified);

        printf("Original size: %d\n", entry->orig_size);
        printf("Compressed size: %d\n", entry->comp_size);
        printf("Compression method: %d\n", entry->comp_method);

        zip_free_entry(entry);
    }

    zip_free(reader);
}

```

Expected output:

```
File 1: aybabtu.txt
Modified: 2026-09-04 23:05:54
Original size: 121
Compressed size: 101
Compression method: 8

File 2: large.txt
Modified: 2026-09-05 14:27:14
Original size: 1000001
Compressed size: 988
Compression method: 8

File 3: small.txt
Modified: 2026-09-05 14:26:56
Original size: 0
Compressed size: 0
Compression method: 0

File 4: test.py
Modified: 2026-09-05 14:27:10
Original size: 19
Compressed size: 19
Compression method: 0

File 5: tree.pcx
Modified: 2026-09-04 23:06:06
Original size: 422
Compressed size: 216
Compression method: 8
```

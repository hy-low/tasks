#include <stdio.h>
#include <time.h>
#include "zip.h"

void local_tests(void) {
    // You can use this file for testing functions locally

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

#include <stdio.h>
#include "csv.h"

void local_tests(void) {
    // You can use this file for testing functions locally

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

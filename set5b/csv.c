#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

typedef struct CsvReader {
    // TODO
};

CsvReader* csv_open(char *filename) {
    // TODO
}

CsvRecord* csv_next_record(CsvReader *reader) {
    // TODO
}

void csv_free_record(CsvRecord *record) {
    // TODO
}

void csv_free(CsvReader *reader) {
    // TODO
}

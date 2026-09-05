#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "zip.h"

typedef struct ZipReader {
    // TODO
};

ZipReader* zip_open(char *filename) {
    // TODO
}

ZipEntry* zip_next_entry(ZipReader *reader) {
    // TODO
}

void zip_free_entry(ZipEntry *entry) {
    // TODO
}

void zip_free(ZipReader *reader) {
    // TODO
}
